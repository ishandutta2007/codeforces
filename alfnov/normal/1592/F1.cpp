#include<bits/stdc++.h>
using namespace std;
char t[505][505];
int a[505][505],b[505][505];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)scanf("%s",t[i]+1);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)
		b[i][j]=(t[i][j]=='B');
	int aa=0;
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
		a[i][j]=(0ll+b[i][j]+b[i][j+1]+b[i+1][j]+b[i+1][j+1])&1;
		aa+=a[i][j];
	}
	int ans=aa;
	for(int i=1;i<n;++i)for(int j=1;j<m;++j){
		if(!a[i][j]||!a[i][m]||!a[n][j]||!a[n][m])continue;
		ans=min(ans,aa-1);
	}
	cout<<ans<<endl;
	return 0;
}