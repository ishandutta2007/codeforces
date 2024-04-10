#include<bits/stdc++.h>
using namespace std;
const int BBB=1000;
int n,m,a[1000100],lp[2010],lim;
int dsu[100100],sz[100100],id[100100],pos[100100],num[100100];
//id:the index of node of each value.
//pos:the correspond value of each node.
//num:the index of node of each position.
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
void merge(int x,int y){//merge y into x.
	if(!id[y])return;
	if(!id[x]){id[x]=id[y],pos[id[y]]=x,id[y]=0;return;}
	dsu[id[y]]=id[x],sz[id[x]]+=sz[id[y]];id[y]=0;
}
int tp[500100],L[500100],R[500100],X[500100],res[500100];
namespace FIFO{
char buf[1<<23],*p1=buf,*p2=buf;
#ifndef Troverld
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#else
#define gc() getchar()
#endif
template<typename T>void read(T&x){
	x=0;
	char c=gc();
	while(c>'9'||c<'0')c=gc();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=gc();
}
template<typename T>void print(T x){if(x<=9)putchar('0'+x);else print(x/10),putchar('0'+x%10);}
}using namespace FIFO;
void solve(int p){
	int M=100001,tag=0,cnt=0;
	auto refuel=[&](){
		for(int i=lp[p];i<lp[p+1];i++){
			if(!id[a[i]])id[a[i]]=++cnt,pos[cnt]=a[i],dsu[cnt]=cnt,sz[cnt]=0;
			sz[num[i]=id[a[i]]]++;
		}
	};
	auto fullmodi=[&](int x){
		if(M-tag<=(x<<1))while(M-tag>x)merge(M-x,M),M--;
		else{for(int i=1;i<=x;i++)merge(i+tag+x,i+tag);tag+=x;}
	};
	auto clean=[&](){for(int i=1;i<=cnt;i++)id[pos[i]]=0;cnt=0;};
	auto refresh=[&](){
		for(int i=lp[p];i<lp[p+1];i++)a[i]=pos[find(num[i])]-tag;tag=0;
		clean();
	};
	auto modify=[&](int l,int r,int x){
		if(l>=lp[p+1]||r<lp[p])return;
		if(l<=lp[p]&&lp[p+1]-1<=r)return fullmodi(x);
		refresh();
//		for(int i=lp[p];i<lp[p+1];i++)printf("%d ",a[i]);puts("");
		for(int i=lp[p];i<lp[p+1];i++)if(l<=i&&i<=r&&a[i]>x)a[i]-=x;
		refuel();
	};
	auto fullask=[&](int x){x+=tag;if(x>M||!id[x])return 0;return sz[find(id[x])];};
	auto query=[&](int l,int r,int x){
		if(l>=lp[p+1]||r<lp[p])return 0;
		if(l<=lp[p]&&lp[p+1]-1<=r)return fullask(x);
		refresh();
//		for(int i=lp[p];i<lp[p+1];i++)printf("%d ",a[i]);puts("");
		int ret=0;
		for(int i=lp[p];i<lp[p+1];i++)if(l<=i&&i<=r&&a[i]==x)ret++;
		refuel();
		return ret;
	};
	refuel();
	for(int i=1;i<=m;i++){
		if(tp[i]==1)modify(L[i],R[i],X[i]);
		else res[i]+=query(L[i],R[i],X[i]);
	}
	clean();
}
int main(){
	read(n),read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i+=BBB)lp[lim++]=i;
	lp[lim]=n+1;
	for(int i=1;i<=m;i++)read(tp[i]),read(L[i]),read(R[i]),read(X[i]);
	for(int i=0;i<lim;i++)solve(i);
	for(int i=1;i<=m;i++)if(tp[i]==2)print(res[i]),putchar('\n');
	return 0;
}