#include<bits/stdc++.h>
using namespace std;
int n,t;
void c(int t)
{
	for(int j=0;j<=t/3;j++)
		for(int k=0;k<=t/7;k++)
			if(3*j+7*k==t){cout<<"YES\n";return;}
	cout<<"NO\n";
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>t,c(t);
    return 0;
}