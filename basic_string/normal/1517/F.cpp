#include<bits/stdc++.h>
using namespace std;
enum{N=309,M=N*2,P=998244353};
int F[N][M],G[M],*f[N],*g=G+N,n,o;
basic_string<int>e[N];
unordered_set<int>s[N],t;
int qp(int a,int b){int r=1;for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;return r;}
void dfs(int x,int y){
	memset(F[x],0,M*4),f[x][-1]=f[x][o]=1,s[x]={-1,o};
	for(int i:e[x])if(i^y){
		dfs(i,x),memset(G,0,M*4),t={};
		int l;
		for(int j:s[x])for(int k:s[i])if(j+k>=0)t.insert(l=max(j,k-1)),g[l]=(g[l]+f[x][j]*1ll*f[i][k])%P;
		else if((l=min(j,k-1))>=-o)t.insert(l),g[l]=(g[l]+f[x][j]*1ll*f[i][k])%P;
		memcpy(F[x],G,M*4),s[x]=t;
	}
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i,j,k;
	for(i=0;i<N;++i)f[i]=F[i]+N;
	for(cin>>n,i=1;i<n;++i)cin>>j>>k,e[j]+=k,e[k]+=j;
	for(o=1,j=0;o<n;++o)for(dfs(1,0),k=0;k<n;++k)j=(j-f[1][k])%P;
	cout<<((j+qp(2,n)*(n-1ll))%P*qp(qp(2,P-2),n)%P+P)%P;
	return 0;
}