#include<bits/stdc++.h>
using namespace std;
enum{N=200009,P=998244353};
basic_string<int>g[N];
int f[N][3];
void dfs(int x){
	if(!g[x].size()){f[x][2]=1;return;}
	f[x][0]=1;
	for(int i:g[x]){
		dfs(i);
		f[x][2]=(f[x][2]*(f[i][0]+f[i][1]+f[i][2]*2ll)+f[x][1]*1ll*(f[i][1]+f[i][2]))%P;
		f[x][1]=(f[x][1]*1ll*(f[i][0]+f[i][2])+f[x][0]*1ll*(f[i][1]+f[i][2]))%P;
		f[x][0]=f[x][0]*1ll*(f[i][0]+f[i][2])%P;
	}
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,j;
	for(cin>>n,i=2;i<=n;++i)cin>>j,g[j]+=i;
	dfs(1),cout<<(f[1][0]+f[1][2])%P;
	return 0;
}