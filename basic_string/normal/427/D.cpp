#include<bits/stdc++.h>
using namespace std;
const int N=5009;
char a[N],b[N];
using ll=unsigned long long;
namespace H{
	const int O=16383,M=N*2;
	int he[O+8],id1[M],id2[M],ne[M],t;
	ll to[M];
	void add1(ll x){
		int i=x&O,j=he[i];
		for(;j;j=ne[j])if(to[j]==x)return void(++id1[j]);
		ne[++t]=he[i],to[t]=x,id1[t]=1,id2[t]=0,he[i]=t;
	}
	void add2(ll x){
		int i=x&O,j=he[i];
		for(;j;j=ne[j])if(to[j]==x)return void(++id2[j]);
		ne[++t]=he[i],to[t]=x,id1[t]=0,id2[t]=1,he[i]=t;
	}
}
ll pw[N],h1[N],h2[N];
int main(){
	int n,m,i,j,k;
	scanf("%s%s",a+1,b+1),n=strlen(a+1),m=strlen(b+1),pw[0]=1;
	for(i=1;i<N;++i)pw[i]=pw[i-1]*13331;
	for(i=1;i<=n;++i)h1[i]=h1[i-1]*13331+a[i];
	for(i=1;i<=m;++i)h2[i]=h2[i-1]*13331+b[i];
	for(i=1;i<=min(n,m);++i){
		H::t=0;memset(H::he,0,sizeof H::he);
		for(j=i;j<=n;++j)H::add1(h1[j]-h1[j-i]*pw[i]);
		for(j=i;j<=m;++j)H::add2(h2[j]-h2[j-i]*pw[i]);
		for(j=H::t;j;--j)if(H::id1[j]==1&&H::id2[j]==1)printf("%d",i),exit(0);
	}
	puts("-1");
	return 0;
}