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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n;
	vector<int> d;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			d.push_back(i);
			if (i * i != n)
				d.push_back(n / i);
		}
	}
	sort(d.begin(), d.end());
	vector<int> p;	
	for (int i = 0; i < d.size(); i++) {
		bool pr = true;
		for (auto val : p)	
			if (d[i] % val == 0)
				pr = false;
		if (d[i] == 1)
			pr = false;
		if (pr)
			p.push_back(d[i]);
	}

	vector<vector<int>> guys((1 << p.size()));
	for (int i = 0; i < d.size(); i++) {
		int code = 0;
		for (int j = 0; j < p.size(); j++)
			if (d[i] % p[j] == 0)
				code |= (1 << j);
		if (viv)
			cout << d[i] << " is " << code << endl;
		guys[code].push_back(d[i]);
	}

	vector<int> codes(1, 0);
	for (int i = 0; i < p.size(); i++) {
		auto cp = codes;
		reverse(cp.begin(), cp.end());
		for (auto &val : cp)
			val |= (1 << i);
		for (auto val : cp)
			codes.push_back(val);
	}
	if (viv) {
		cout << "codes = ";
		for (auto i : codes)
			cout << i << ' ';
		cout << endl;
	}
	reverse(codes.begin(), codes.end());
	codes.pop_back();

	vector<int> ans;
	for (int i = 0; i < codes.size(); i++) {
		for (auto val : guys[codes[i]])
			ans.push_back(val);
	}
	vector<int> ans2;
	for (auto val : ans)
		if (val != n)	
			ans2.push_back(val);
	ans = ans2;
	ans.push_back(n);


	int res = 0;
	for (int i = 0; i < ans.size(); i++) {
		int j = (i + 1) % ans.size();
		unsigned a = ans[i];
		unsigned b = ans[j];
		if (__gcd(a, b) == 1)
			res++;
	}
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
	cout << res << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}