#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
#define ll long long
int he[N],to[N*2],ne[N*2],w[N],a[N],o;
bool fl;
void dfs(int x,int y){
	for(int i=he[x],j;i;i=ne[i])if((j=to[i])!=y){
		dfs(j,x);
		if(x==1){
		if(fl)a[++o]=w[x];
		fl=1;}else a[++o]=w[x];
	}
}
int main(){
	int T,n,i,j,k,t;
	ll ans=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),t=0,o=0,fl=0;
		memset(he,0,n*4+4),ans=0;
		for(i=1;i<=n;++i)scanf("%d",w+i),ans+=w[i];
		for(i=1;i<n;++i){
			scanf("%d%d",&j,&k);
			ne[++t]=he[j],to[t]=k,he[j]=t;
			ne[++t]=he[k],to[t]=j,he[k]=t; 
		}
		dfs(1,0);
		cout<<ans<<' ';
		sort(a+1,a+o+1,greater<int>());
		for(i=1;i<=o;++i)ans+=a[i],cout<<ans<<' ';cout<<'\n'; 
	}
	return 0;
}