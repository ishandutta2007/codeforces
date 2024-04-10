#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int n,m,f[3009][3009],a[2],b[2];
char s[3009][3009];
void wk(int x){
	int i,j;
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(s[i][j]=='.'){
		f[i][j]=(f[i][j]+f[i-1][j]+f[i][j-1])%P;
	}
	a[x]=f[n-1][m],b[x]=f[n][m-1];
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>s[i]+1;
	if(f[1][2]=1,s[1][2]=='.')wk(0);
	if(memset(f,0,sizeof f),f[2][1]=1,s[2][1]=='.')wk(1);
	cout<<((a[0]*1ll*b[1]-a[1]*1ll*b[0])%P+P)%P;
}