#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)501*1000)

pair<ll,ll> solve(ll a,ll b)
{
	if(a==0 || b==0)return {a,b};
	if(a>=2*b)return solve(a%(2*b),b);
	if(b>=2*a)return solve(a,b%(2*a));
	return {a,b};
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll a,b;
	cin>>a>>b;
	cout<<solve(a,b).first<<" "<<solve(a,b).second<<"\n";
	return 0;
}