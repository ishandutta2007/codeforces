#include<bits/stdc++.h>
using namespace std;
int n,a[400100],b[400100],buc[200100],mat[400100],mbt[400100];
int stk[400100],tp;
struct Path{
list<int>l,r;
list<int>::iterator S,T;
void rev(){swap(l,r),swap(S,T);}
void init(int x){l.clear(),r.clear(),l.push_back(x),r.push_back(x),S=l.begin(),T=r.begin();}
void pm(int x,int y){
	rev();
	l.push_front(y),l.push_back(x),S=l.begin();
	r.push_front(x),r.push_back(y),T=--r.end();
}
void mp(int x,int y){
	rev();
	l.push_front(x),l.push_back(y),S=--l.end();
	r.push_front(y),r.push_back(x),T=r.begin();
}
void operator+=(Path&y){
//	for(auto x:l)printf("%d ",x);printf("|");for(auto x:y.l)printf("%d ",x);puts("");
	l.splice(S,y.l),l.erase(S),S=y.S;
	r.splice(T,y.r),r.erase(T),T=y.T;
}
}c[400100];
vector<int>p,r,v;
bool vis[400100];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=(n<<1);i++)scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=(n<<1);i++)if(a[i]>0)buc[a[i]]=i;
	for(int i=1;i<=(n<<1);i++)if(a[i]<0)mat[buc[-a[i]]]=i,mat[i]=buc[-a[i]];
	for(int i=1;i<=(n<<1);i++)if(b[i]>0)buc[b[i]]=i;
	for(int i=1;i<=(n<<1);i++)if(b[i]<0)mbt[buc[-b[i]]]=i,mbt[i]=buc[-b[i]];
	for(int i=1;i<=(n<<1);i++)if(!vis[i]&&a[i]>0){
		for(int j=i;!vis[j];){
			vis[j]=true,v.push_back(j),r.push_back(a[j]>0?1:-1),j=mat[j];
			vis[j]=true,v.push_back(j),r.push_back(b[j]>0?-1:1),j=mbt[j];
		}
//		puts("QWQ");
//		for(auto x:v)printf("%d ",x);puts("");
//		for(auto x:r)printf("%d ",x);puts("");
		int num=0;for(auto x:r)num+=x;if(abs(num)!=2){puts("NO");return 0;}
		if(num==-2){
			reverse(v.begin(),v.end()),reverse(r.begin(),r.end()-1);
			for(auto&x:r)x*=-1;
		}
//		for(auto x:v)printf("%d ",x);puts("");
//		for(auto x:r)printf("%d ",x);puts("");
		if(r[0]==-1||r.back()==-1){
			int j=2;
			while(j<r.size()&&r[j-1]+r[j]!=2)j+=2;
			rotate(v.begin(),v.begin()+j,v.end()),rotate(r.begin(),r.begin()+j,r.end());
		}
//		for(auto x:v)printf("%d ",x);puts("");
//		for(auto x:r)printf("%d ",x);puts("");
		c[0].init(v[1]);
		for(int j=1;j+1<v.size();j++){
			if(!tp||r[j]==r[stk[tp]])stk[++tp]=j,c[tp].init(v[j+1]);
			else if(r[stk[tp]]==1)c[tp].pm(v[stk[tp]],v[j+1]),c[tp-1]+=c[tp],tp--;
			else c[tp].mp(v[stk[tp]],v[j+1]),c[tp-1]+=c[tp],tp--;
//			for(auto x:c[tp].l)printf("%d ",x);puts("FUFUFU");
		}
//		printf("DFFD:%d\n",tp);
//		printf("DVDVD:%d,%d\n",p.size(),v[0]);
//		for(auto x:p)printf("%d:%d %d\n",x,a[x],b[x]); 
		p.push_back(v[0]),v.clear(),r.clear();
		for(auto x:c[0].l)p.push_back(x);
	}
	puts("YES");
	for(auto x:p)printf("%d %d\n",a[x],b[x]); 
	return 0;
}