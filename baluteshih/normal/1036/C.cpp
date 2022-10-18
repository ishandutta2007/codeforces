#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll ten[18];
vector<ll> v;

int main()
{jizz
	ll l,r,q;
	ten[0]=1;
	for(int i=1;i<18;++i)
		ten[i]=ten[i-1]*10;
	for(int i=0;i<18;++i)
		for(ll a=1;a<10;++a)
			v.pb(a*ten[i]);
	for(int i=0;i<18;++i)
		for(int j=i+1;j<18;++j)
			for(ll a=1;a<10;++a)
				for(ll b=1;b<10;++b)
					v.pb(a*ten[i]+b*ten[j]);
	for(int i=0;i<18;++i)
		for(int j=i+1;j<18;++j)
			for(int k=j+1;k<18;++k)
				for(ll a=1;a<10;++a)
					for(ll b=1;b<10;++b)
						for(ll c=1;c<10;++c)
							v.pb(a*ten[i]+b*ten[j]+c*ten[k]);
	v.pb(1e18),sort(ALL(v));
	cin >> q;
	while(q--)
		cin >> l >> r,cout << (upper_bound(ALL(v),r)-v.begin())-(upper_bound(ALL(v),l-1)-v.begin()) << "\n";
}