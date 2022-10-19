#include<bits/stdc++.h>
using namespace std;
int n,stk[1010],tp,ord[1010];
struct Vector{
	int x,y;
	Vector(int X=0,int Y=0){x=X,y=Y;}
	friend Vector operator +(const Vector &u,const Vector &v){return Vector(u.x+v.x,u.y+v.y);}
	friend Vector operator -(const Vector &u,const Vector &v){return Vector(u.x-v.x,u.y-v.y);}
	friend int operator &(const Vector &u,const Vector &v){return u.x*v.y-u.y*v.x;}//cross times
	friend int operator |(const Vector &u,const Vector &v){return u.x*v.x+u.y*v.y;}//point times
	double operator ~()const{return atan2(y,x);}
	void read(){scanf("%d%d",&x,&y);}
	void print(){printf("(%d,%d)",x,y);}
}p[1010];
bool col[1010];
vector<pair<int,int> >edges;
void solve(int u,int v,int w){
	bool minor=col[u]^col[v]^col[w];
	int MINOR;
	if(col[u]==minor)MINOR=u;
	if(col[v]==minor)MINOR=v;
	if(col[w]==minor)MINOR=w;
	for(int i=0;i<n;i++){
		if(i==u||i==v||i==w)continue;
		if(col[i]!=minor)continue;
		bool U=((p[u]-p[i])&(p[v]-p[i]))>0;
		bool V=((p[v]-p[i])&(p[w]-p[i]))>0;
		bool W=((p[w]-p[i])&(p[u]-p[i]))>0;
		if(U!=V||V!=W||W!=U)continue;
		edges.push_back(make_pair(MINOR,i));
		solve(u,v,i),solve(v,w,i),solve(w,u,i);
		return;
	}
	for(int i=0;i<n;i++){
		if(i==u||i==v||i==w)continue;
		bool U=((p[u]-p[i])&(p[v]-p[i]))>0;
		bool V=((p[v]-p[i])&(p[w]-p[i]))>0;
		bool W=((p[w]-p[i])&(p[u]-p[i]))>0;
		if(U!=V||V!=W||W!=U)continue;
		if(col[u]==col[i]){edges.push_back(make_pair(u,i));continue;}
		if(col[v]==col[i]){edges.push_back(make_pair(v,i));continue;}
		if(col[w]==col[i]){edges.push_back(make_pair(w,i));continue;}
	}
}
bool onhull[1010];
void print(){
	printf("%d\n",edges.size());
	for(auto i:edges)printf("%d %d\n",i.first,i.second);
	exit(0);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)p[i].read(),scanf("%d",&col[i]),ord[i]=i;
	sort(ord,ord+n,[](int u,int v){return p[u].x==p[v].x?p[u].y<p[v].y:p[u].x<p[v].x;});
	for(int i=1;i<n;i++)p[ord[i]]=p[ord[i]]-p[ord[0]];
	p[ord[0]]=Vector(0,0);
	sort(ord+1,ord+n,[](int u,int v){return ~p[u]<~p[v];});
	stk[tp++]=ord[0];
	for(int i=1;i<n;i++){
		while(tp>=2&&((p[ord[i]]-p[stk[tp-1]])&(p[stk[tp-1]]-p[stk[tp-2]]))>=0)tp--;
		stk[tp++]=ord[i];
	}
	for(int i=0;i<tp;i++)onhull[stk[i]]=true;
	int l=tp,r=1;
	while(r<l&&col[stk[r]]==col[stk[0]])r++;
	while(l>r&&col[stk[l-1]]==col[stk[0]])l--;
	if(r==l){
		for(int j=1;j<tp;j++)edges.push_back(make_pair(stk[j-1],stk[j]));
		for(int i=0;i<n;i++){
			if(onhull[i]||col[i]==col[stk[0]])continue;
			for(int j=0;j<tp;j++)solve(stk[j],stk[(j+1)%tp],i);
			print();
		}
		for(int i=0;i<n;i++){
			if(onhull[i])continue;
			for(int j=i+1;j<n;j++)if(!onhull[j])edges.push_back(make_pair(i,j));
			if(col[i]==col[stk[0]])edges.push_back(make_pair(i,stk[0]));
			print();
		}
	}else{
		for(int i=r;i<l;i++)if(col[stk[i]]==col[stk[0]]){puts("Impossible");return 0;}
		for(int i=(l+1)%tp;i!=r;i=(i+1)%tp)edges.push_back(make_pair(stk[(i+tp-1)%tp],stk[i]));
		for(int i=r+1;i<l;i++)edges.push_back(make_pair(stk[i-1],stk[i]));
		for(int i=(l+1)%tp;i!=r;i=(i+1)%tp)solve(stk[(i+tp-1)%tp],stk[i],stk[r]);
		for(int i=r+1;i<l;i++)solve(stk[i-1],stk[i],stk[l%tp]);
		print();
	}
	print();
	return 0;
}