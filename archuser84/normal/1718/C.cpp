#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

vector<ll> factor(ll x)
{
	vector<ll> ans;
	for (ll y = 2; y*y <= x; ++y) {
		if (x%y == 0) {
			while (x%y == 0)
				x /= y;
			ans.push_back(y);
		}
	}
	if (x > 1)
		ans.push_back(x);
	return ans;
}

void solve()
{
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n);
	Loop (i,0,n)
		cin >> a[i];
	vector<ll> n_lens = factor(n);
	for (ll &x : n_lens)
		x = n/x;
	vector<vector<ll>> sum;
	multiset<ll, greater<ll>> s;
	for (ll l : n_lens) {
		vector<ll> v(l);
		Loop (i,0,n)
			v[i%l] += a[i];
		sum.push_back(v);
		Loop (i,0,l)
			s.insert(v[i] * l);
	}
	cout << *s.begin() << '\n';
	while (q--) {
		ll p, x;
		cin >> p >> x;
		--p;
		Loop (i,0,sum.size()) {
			ll l = sum[i].size();
			s.erase(s.find(sum[i][p%l] * l));
			sum[i][p%l] -= a[p];
			sum[i][p%l] += x;
			s.insert(sum[i][p%l] * l);
		}
		a[p] = x;
		cout << *s.begin() << '\n';
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}