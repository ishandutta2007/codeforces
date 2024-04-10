#include<bits/stdc++.h>
using namespace std;
int n,d[102],a,b;
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)cin>>d[i],d[i]+=d[i-1];
	cin>>a>>b,cout<<d[b]-d[a];
	return 0;
}