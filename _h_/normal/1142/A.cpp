#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define trav(x, v) for(auto &x : v)
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<vi> vvi;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	ll n, k, a, b;
	cin >> n >> k >> a >> b;

	ll tot = n*k;

	ll x0 = a;

	ll lo = tot, hi = 1;
	auto fun = [&](ll d){
		d %= tot;
		if(d < 0) d += tot;
		ll res = d ? tot / __gcd(d, tot) : 1;
		lo = min(lo, res);
		hi = max(hi, res);
	};
	rep(t,0,n){
		ll x1 = b + t*k;
		fun(x1 - x0);
		x1 = t*k - b;
		fun(x1 - x0);
	}
	cout << lo << ' ' << hi << endl;
}