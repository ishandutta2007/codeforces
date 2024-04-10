#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;


const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


vector<ll> erat(int last) {
	vector<bool> prime(last + 1, true);
	vector<ll> res;
	for (int i = 2; i <= last; i++) {
		if (prime[i])
			res.push_back(i);
		if ((ll)i * i < last)
			for (int j = i * i; j <= last; j += i)
				prime[j] = false;
	}
	return res;
}


bool viv = false;
int n, e;
vector<int> v;

set<int> s;

void prepare(){
	auto p = erat(ml + 10);
	for (auto i : p)
		s.insert(i);
}

ll sum(ll a, ll b) {
	return (a + b) * (b + 1 - a) / 2;
}

void solve() {
	cin >> n >> e;
	v.resize(n);
	for (auto &i : v) {
		cin >> i;
		if (i == 1)
			i = 0;
		else {
			if (s.count(i))
				i = 1;
			else
				i = 2;
		}
	}

	vector<int> l(n, 0);
	vector<int> r(n, 0);
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] == 0) {
			r[i] = 1;
			if (i + e < n)
				r[i] += r[i + e];
		}
	}
	for (int i = 0; i < n; i++) {
		if (v[i] == 0) {
			l[i] = 1;
			if (i - e >= 0)
				l[i] += l[i - e];
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int cl = 0, cr = 0;		
		if (i - e >= 0)
			cl = l[i - e];
		if (i + e < n)
			cr = r[i + e];
		long long lans = 0;
		if (v[i] == 1) {
			ll a, b;
			a = cl, b = cr;
			if (a > b)
				swap(a, b);
			lans += sum(1, a + 1);
			lans += sum(1, a + 1);
			lans += (a + b + 1 - 2 * (a + 1)) * (a + 1);
			lans--;
			if (viv) {
				cout << i << ' ' << cl << ' ' << cr << ": " << lans << endl;
			}
		}
		ans += lans;
	}
	cout << ans << '\n';
}

int main() {
	prepare();
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}