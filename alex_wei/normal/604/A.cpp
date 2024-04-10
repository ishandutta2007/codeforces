#include<bits/stdc++.h>
using namespace std;
#define ll long long
int m[6],w[6],s,u,ans;
int main()
{
	for(int i=1;i<6;i++)
		cin>>m[i];
	for(int i=1;i<6;i++)
		cin>>w[i];
	cin>>s>>u;
	for(int i=1;i<6;i++)
		ans+=max(150.0*i,i*(500.0-2.0*m[i])-50.0*w[i]);
	cout<<ans+100*s-50*u;
	return 0;
}