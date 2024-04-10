#include<bits/stdc++.h>
using namespace std;
enum{N=300009,M=23};
basic_string<int>g[N],a;
long long ans;
int d[N],f[M][N],n;
void dfs(int x,int y){
	for(int i:g[x])if(i^y)dfs(i,x),d[x]=max(d[x],d[i]);
	int j,k,l;
	for(ans+=++d[x],f[j=1][x]=n;j<M&&j<d[x];++j){
		a={};
		for(int i:g[x])if(i!=y&&f[j][i]>1)a+=f[j][i];
		sort(begin(a),end(a),greater<>());
		for(l=size(a),k=0;k<l;++k)f[j+1][x]=max(f[j+1][x],min(a[k],k+1));
	}
}
void cal(int x,int y){
	int j;
	for(int i:g[x])if(i^y){
		cal(i,x);
		for(j=1;j<M;++j)f[j][x]=max(f[j][x],f[j][i]);
	}
	for(j=1;;++j){
		if(f[j+1][x]>1)ans+=(f[j][x]-f[j+1][x])*j;
		else{ans+=(f[j][x]-1)*j;break;}
	}
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i,j,k;
	for(i=1,cin>>n;i<n;++i)cin>>j>>k,g[j]+=k,g[k]+=j;
	dfs(1,0),cal(1,0),cout<<ans;
	return 0;
}