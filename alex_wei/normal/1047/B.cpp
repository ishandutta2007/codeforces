#include<bits/stdc++.h>
using namespace std;
int n,x,y,mx; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x>>y,mx=max(mx,x+y);
	cout<<mx;
	return 0;
}