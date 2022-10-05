#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5,M=2e5+5;
ll a[63],len[M],d[N];
int he[N],to[M],ne[M];
bool f[N];
void ins(ll x){
	for(int i=62;~i;--i)if(x&(1ll<<i))if(!a[i]){a[i]=x;return;}else x^=a[i];
}
void dfs(int x,ll y){
	d[x]=y,f[x]=1;
	for(int i=he[x],j;i;i=ne[i]){
		if(j=to[i],f[j])ins(y^len[i]^d[j]);
		else dfs(j,y^len[i]);
	}
}
int main(){
	int n,m,t=0,i,j;
	ll k;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d%lld",&i,&j,&k);
		ne[++t]=he[i],to[t]=j,len[t]=k,he[i]=t;
		ne[++t]=he[j],to[t]=i,len[t]=k,he[j]=t; 
	}
	dfs(1,0);
	for(k=d[n],i=62;~i;--i)k=min(k,k^a[i]);
	printf("%lld",k);
	return 0;
}