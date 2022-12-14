#include<iostream>
using namespace std;
int v[10101];
int a[1010];
int main()
{
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		v[a[i]]=1;
	}
	int ans=0;
	for(int i=0;i<x;i++)
	if(v[i]==0)
		ans++;
	if(v[x]==1)
		ans++;
	cout<<ans<<endl;
	return 0;
}