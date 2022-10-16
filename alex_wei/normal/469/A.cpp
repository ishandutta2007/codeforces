#include<bits/stdc++.h>
using namespace std;
int n,p,q,s,a[102]; 
int main()
{
	cin>>n>>p;
	for(int i=1;i<=p;i++)cin>>s,a[s]=1;
	cin>>q;
	for(int i=1;i<=q;i++)cin>>s,a[s]=1;
	for(int i=1;i<=n;i++)
		if(!a[i])cout<<"Oh, my keyboard!",exit(0);
	cout<<"I become the guy.";
	return 0;
}