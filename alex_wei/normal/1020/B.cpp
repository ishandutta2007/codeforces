#include<bits/stdc++.h>
using namespace std;
int n,p[1002],vis[1002]; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		int poi=p[i];
		while(poi!=i&&!vis[poi])
			vis[poi]=1,poi=p[poi];
		cout<<poi<<" ";
	}
	return 0;
}