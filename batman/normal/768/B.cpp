#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)
#define K ((ll)52)

ll n,l,r;

ll solve(ll x)
{
	if(x==0)return 0;
	ll x2=n,ans=0;
	vector <bool> ex;
	while(x2)ex.push_back(x2%2),x2/=2;
	reverse(ex.begin(),ex.end());
	for(ll i=0;i<ex.size();i++)
		ans+=((x+1)/2)*ex[i],x-=(x+1)/2;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>l>>r;
	cout<<solve(r)-solve(l-1);
	return 0;
}