#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N=2e3+5;

int n,m,ans,f[N][N];
char c[N][N];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++){
			if(j==1||c[i][j]!=c[i][j-2]||c[i][j]!=c[i-1][j-1]||c[i][j]!=c[i+1][j-1])f[i][j]=1;
			else f[i][j]=min(f[i][j-2],min(f[i-1][j-1],f[i+1][j-1]))+1;
			ans+=min(f[i][j],c[i][j]==c[i][j-1]?f[i][j-1]+1:1);
		} cout<<ans<<endl;
	return 0;
}