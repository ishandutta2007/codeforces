#include<bits/stdc++.h>
using namespace std;
int n,m,a,b=1e9,c,d=1e9,e,f;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>e>>f,a=max(a,e),b=min(b,f);
	cin>>m;
	for(int i=0;i<m;i++)
		cin>>e>>f,c=max(c,e),d=min(d,f);
	cout<<max(0,max(c-b,a-d));
	return 0;
}