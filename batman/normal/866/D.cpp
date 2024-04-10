#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

ll n,ans;
multiset <ll> s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		s.insert(x);s.insert(x);
		ans+=x-*s.begin();
		s.erase(s.begin());
	}
	cout<<ans<<"\n";
	return 0;
}