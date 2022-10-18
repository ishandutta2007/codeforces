#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll arr[200005],n;

pll check(ll x)
{
	//cout << "check " << x << ":\n";
	pll cnt=MP(0,0);
	for(ll i=1,j=i;i<=n;++i)
	{
		while(j<=n&&arr[j]-(arr[i]+x)<=x) ++j;
		if(j-i>cnt.F) cnt=MP(j-i,arr[i]+x);
	}
	for(ll i=n,j=n;i>1;--i)
	{
		while(j>0&&(arr[i]-x)-arr[j]<=x) --j;
		if(i-j>cnt.F) cnt=MP(i-j,arr[i]-x);
	}
	//cout << cnt.F << " " << cnt.S << "\n";
	return cnt;
}

int main()
{jizz
	ll t,k,l,r;
	cin >> t;
	while(t--)
	{
		cin >> n >> k,++k,l=0,r=1e9;
		for(int i=1;i<=n;++i)
			cin >> arr[i];
		while(l<r)
		{
			ll mid=l+r>>1;
			if(check(mid).F>=k) r=mid;
			else l=mid+1;
		}
		cout << check(l).S << "\n";
	}
}