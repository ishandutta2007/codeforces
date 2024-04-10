#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,k;
int main()
{
    cin>>n>>k;
	if(k==0)
		for(int i=1;i<=n;i++)
			cout<<i<<" ";
	else
	{
		for(int i=1;i<=n-k-1;i++)
			cout<<i<<" ";
		for(int i=n;i>n-k-1;i--)
			cout<<i<<" ";	
	}		
    return 0;
}