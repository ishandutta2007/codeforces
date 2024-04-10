#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,s,t,a[200*1000];
int main()
{
    cin>>n>>s>>t;
    for(int i=0;i<n;i++)
    	cin>>a[i];
	for(int i=0;i<n+1000;i++)
	{
		if(s==t)
		{
			cout<<i;
			return 0;
		}
		s=a[s-1];
	}
	cout<<-1;	
    return 0;
}