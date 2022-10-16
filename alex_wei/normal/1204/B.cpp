#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,l,r,sum,sum2;
int main()
{
	cin>>n>>l>>r;
	for(int i=1;i<l;i++)sum+=(1<<i);
	for(int i=l;i<=n;i++)sum++;
	for(int i=0;i<r;i++)sum2+=(1<<i);
	for(int i=r;i<n;i++)sum2+=(1<<(r-1));
	cout<<sum<<" "<<sum2;
	return 0;
}