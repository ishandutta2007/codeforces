#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
ifstream in;
ofstream out;
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;;
const long long inf = 2 * (ml * ml * ml + 7);
 
 
ll n, t, a, b, k;
vector<ll> dp, f;
bool viv = false;

ll mul(ll a, ll b) {
	ld da = a, db = b;
	ld dm = da * db;
	return (dm > inf / 2) ? inf / 2 : da * db;
}

void prepare() {
	f.push_back(1);
	for (ll i = 1; i < 21; i++) {
		f.push_back(f.back() * i);
	}
	for (ll i = 0; i < 40; i++)
		f.push_back(f.back());
	for (auto &i : f)
		i = min(i, inf / 2);
	dp.push_back(1);
	dp.push_back(1);
	for (ll i = 2; i < 55; i++) {
		dp.push_back(0);
		for (ll j = 1; j <= i; j++) {
			ll res = mul(f[max(j - 2, 0ll)], dp[i - j]);			
			dp[i] += res;
			dp[i] = min(dp[i], inf);
		}
	}
}

bool good(vector<ll> v) {
	for (ll i = 0; i < v.size() - 1; i++)
		if (v[i] == v.back())
			return false;
	if (v.back() == v.size())
		return false;

	if (v[0] == v.size())
		return true;
	ll n = v[0];
	vector<bool> used(n, false), have(n, false), star(n, true);
	for (auto &i : v)
		i--;
	for (auto &i : v)
		have[i] = true;
	for (auto &i : v)
		star[i] = false;
	for (ll i = 0; i < v.size(); i++) 
		if (star[i]) {
			used[v[i]] = true;
			ll now = v[i];
			while (now < v.size() && have[v[now]] && !used[v[now]])
				now = v[now], used[now] = true;
			if (now < v.size() && have[v[now]])
				return false;
		}
	for (ll i = 0; i < n; i++)
		if (have[i] && !used[i])
			return false;
	return true;
}

vector<ll> solve(ll n, ll k) {
	if (n == 0)
		return {};
	if (dp[n] < k) 
		return {-1};
	ll now = 0, st = 0, was = 0;
	while (now < k) {
		st++;
		was = now;
		now += mul(f[max(st - 2, 0ll)], dp[n - st]);
	}
	k -= was;
	ll tie = dp[n - st];
	ll head = (k - 1) / tie;
	k -= head * tie;

	vector<ll> ans;
	ans.push_back(st);
	for (ll i = 1; i < st; i++) {
		ll vars = f[max(st - (i + 2), 0ll)];
		ll add = 1;
		bool cont = true;
		while (cont) {
			ans.push_back(add);
			if (good(ans)) {
				head -= vars;
				if (head < 0) 
					cont = false, head += vars;
			}
			if (cont) 
				add++, ans.pop_back();
		}
	}

	auto t = solve(n - ans.size(), k);
	for (auto &i : t)
		i += ans.size();
	for (auto i : t)
		ans.push_back(i);
	return ans;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    prepare();
    ll n, k, t = 1;
    cin >> t;
    while (t--) {
    	cin >> n >> k;
    	auto ans = solve(n, k);
    	for (auto i : ans)
    		cout << i << ' ';
    	cout << '\n';
    }


    return 0;
}