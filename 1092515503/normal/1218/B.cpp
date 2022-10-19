#include<bits/stdc++.h>
using namespace std;
struct Vector{
	int x,y;
	Vector(){}
	Vector(int X,int Y){x=X,y=Y;}
	friend Vector operator+(const Vector&u,const Vector&v){return Vector(u.x+v.x,u.y+v.y);}
	friend Vector operator-(const Vector&u,const Vector&v){return Vector(u.x-v.x,u.y-v.y);}
	friend int operator&(const Vector&u,const Vector&v){return u.x*v.y-u.y*v.x;}//cross times
	friend int operator|(const Vector&u,const Vector&v){return u.x*v.x+u.y*v.y;}//point times
	int quardrant()const{
		if(x>0&&y>=0)return 0;
		if(x<=0&&y>0)return 1;
		if(x<0&&y<=0)return 2;
		if(x>=0&&y<0)return 3;
	}
	friend bool operator<(const Vector&u,const Vector&v){
		if(u.quardrant()!=v.quardrant())return u.quardrant()<v.quardrant();
		return(u&v)>0;
	}
	friend bool operator<<(const Vector&u,const Vector&v){return(u&v)>0;}
	friend bool operator==(const Vector&u,const Vector&v){
		if(u.quardrant()!=v.quardrant())return false;
		return(u&v)==0;
	}
	void read(){scanf("%d%d",&x,&y);}
	void print(){printf("(%d,%d)",x,y);}
}p[50100],V;
int n,m,X[50100],Y[50100],q,o[50100];
double res;
double dis(int i,Vector P){return 1.0*(p[X[i]]&p[Y[i]])/(P&(p[Y[i]]-p[X[i]]));}
double area(int i,Vector P,Vector Q){return dis(i,P)*dis(i,Q)*(P&Q);}
struct segcmp{
bool operator()(const int&u,const int&v)const{
	int Ux=p[X[u]]&p[Y[u]],Uy=V&(p[Y[u]]-p[X[u]]);
	int Vx=p[X[v]]&p[Y[v]],Vy=V&(p[Y[v]]-p[X[v]]);
	if(1ll*Ux*Vy!=1ll*Uy*Vx)return 1ll*Ux*Vy<1ll*Uy*Vx;
	if(V==p[X[u]]&&V==p[X[v]])return((p[Y[u]]-p[X[u]])&(p[Y[v]]-p[X[v]]))<0;
	return((p[X[u]]-p[Y[u]])&(p[X[v]]-p[Y[v]]))>0;
}
};
vector<int>v[50100];
set<int,segcmp>s;
int main(){
	scanf("%d",&n);
	for(int i=0,_;i<n;i++){
		scanf("%d",&_);
		for(int j=0;j<_;j++)p[m+j].read();
		for(int j=0;j<_;j++){
			q++,X[q]=m+j,Y[q]=m+(j+1)%_;
			if(p[X[q]]==p[Y[q]])continue;
			if(p[Y[q]]<<p[X[q]])swap(X[q],Y[q]);
			v[X[q]].push_back(q),v[Y[q]].push_back(-q);
		}
		m+=_;
	}
	// for(int i=0;i<q;i++)putchar('{'),p[X[i]].print(),p[Y[i]].print(),putchar('}');puts("");
	for(int i=0;i<m;i++)o[i]=i;
	sort(o,o+m,[](int x,int y){return p[x]<p[y];});
	for(int l=0,r=0;l<m;l=r){
		while(r<m&&p[o[l]]==p[o[r]])r++;
		V=p[o[l]];
		for(int i=l;i<r;i++)for(auto x:v[o[i]])if(x<0){auto it=s.find(-x);if(it!=s.end())s.erase(it);}
		for(int i=l;i<r;i++)for(auto x:v[o[i]])if(x>0)s.insert(x);
		// V.print();for(auto i:s)putchar('{'),p[X[i]].print(),p[Y[i]].print(),printf(":%lf}",dis(i,V));puts("");
	}
	for(int l=0,r=0;l<m;l=r){
		while(r<m&&p[o[l]]==p[o[r]])r++;
		V=p[o[l]];
		for(int i=l;i<r;i++)for(auto x:v[o[i]])if(x<0){auto it=s.find(-x);if(it!=s.end())s.erase(it);}
		for(int i=l;i<r;i++)for(auto x:v[o[i]])if(x>0)s.insert(x);
		// V.print();for(auto i:s)putchar('{'),p[X[i]].print(),p[Y[i]].print(),putchar('}');puts("");
		if(!s.empty())res+=area(*next(s.begin()),p[o[l]],p[o[r%m]])-area(*s.begin(),p[o[l]],p[o[r%m]]);
	}
	printf("%lf\n",res/2);
	return 0;
}