#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,sum,a[301*1000];
int main()
{
    cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}	
	sort(a,a+n);
	for(int i=0;i<n;i++)
		sum+=abs(i+1-a[i]);
	cout<<sum;	
    return 0;
}