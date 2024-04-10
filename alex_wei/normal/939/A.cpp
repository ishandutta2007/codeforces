#include<bits/stdc++.h>
using namespace std;
int n,f[5002]; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>f[i];
	for(int i=1;i<=n;i++)if(f[f[f[i]]]==i)cout<<"YES",exit(0);
	cout<<"NO";
    return 0;
}