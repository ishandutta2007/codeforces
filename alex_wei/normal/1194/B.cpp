#include <bits/stdc++.h>
using namespace std;
int q,n,m,r[50002],c[50002];
int main()
{
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>n>>m;
		char mp[n+1][m+1];
		int sum=1e9;
		memset(c,0,sizeof(c));
		memset(r,0,sizeof(r));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>mp[i][j],r[i]+=(mp[i][j]=='*'),c[j]+=(mp[i][j]=='*');
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				sum=min(sum,n+m-r[i]-c[j]-(mp[i][j]=='.'));
		cout<<sum<<endl;
	}
    return 0;
}