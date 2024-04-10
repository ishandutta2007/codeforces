#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)

ll n,a[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<7;i++)cin>>a[i];
	for(int i=0;;i++,i%=7)
	{
		n-=a[i];
		if(n<=0)return cout<<i+1,0;
	}
	
	return 0;
}