#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)

ll n,a[N],dp[2][N];
vector <ll> v;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];a[i]-=i;
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());v.resize(unique(v.begin(),v.end())-v.begin());
	for(int i=0;i<n;i++)
	{
		bool p=(i&1);
		for(int j=0;j<v.size();j++)
			dp[p][j]=min(dp[!p][j]+abs(a[i]-v[j]),(j)?dp[p][j-1]:(ll)1e18);
	}
	cout<<dp[((n-1)&1)][(ll)v.size()-1];
	return 0;
}