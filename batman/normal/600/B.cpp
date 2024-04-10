#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (201*1000)
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll n,m,a[N],b[N];
map <ll,ll> mp;
set <ll> s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)s.insert(a[i]),mp[a[i]]=i+1;
	for(int i=0;i<m;i++)
	{
		set <ll>::iterator it=s.upper_bound(b[i]);
		if(it==s.begin())
		{
			cout<<"0 ";
			continue;
		}
		it--;
		cout<<mp[*it]<<" ";
	}
			
    return 0;
}