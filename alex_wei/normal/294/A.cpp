#include<bits/stdc++.h>
using namespace std;
int n,c[105],m,x,y; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		c[x-1]+=y-1;
		c[x+1]+=c[x]-y;
		c[x]=0;
	}
	for(int i=1;i<=n;i++)
		cout<<c[i]<<endl;
	return 0;
}