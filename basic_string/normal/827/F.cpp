#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
struct E{
	int u,v,l,r;
	bool operator<(E a)const{return l>a.l;}
}e;
int f[N][2],n;
basic_string<E>g[N][2];
priority_queue<E>q;
void wk(int u,int v,int l,int r){
	bool o=l&1;
	if(f[u][o]<l)g[u][o]+=E{u,v,l,r};else{
		if(v==n)printf("%d",l+1),exit(0);
		if(f[v][!o]<=r){
			f[v][!o]=r+1;
			for(auto e:g[v][!o])q.push({e.u,e.v,l+1,e.r});
			g[v][!o]={};
		}
	}
}
int main(){
	int m,i,u,v,l,r;
	scanf("%d%d",&n,&m),memset(f,-9,sizeof f),f[1][0]=0;
	if(n==1)puts("0"),exit(0);
	while(m--){
		scanf("%d%d%d%d",&u,&v,&l,&r),--r,i=r-l&1;
		q.push({u,v,l,r-i}),q.push({v,u,l,r-i});
		q.push({u,v,l+1,r-!i}),q.push({v,u,l+1,r-!i});
	}
	while(q.size()){
		e=q.top(),q.pop();
		if(e.l<=e.r)wk(e.u,e.v,e.l,e.r);
	}
	puts("-1");
	return 0;
}