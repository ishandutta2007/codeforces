#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define MOD ((ll)1e9+7)
#define INF ((ll)2e9+100)

ll n,m;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	m=240-m;
	ll i=1;
	for(;i<=n;i++)
	{
		if(m-i*5<0)return cout<<i-1,0;
		m-=i*5;
	}
	cout<<n;
	return 0;
}