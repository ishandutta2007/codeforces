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
vector<ll> ans;
bool viv = false;
string type[3] = {"AND", "OR", "XOR"};

int x(int l, int r, int tp) {
	cout << type[tp] << ' ';
	cout << l + 1 << ' ';
	cout << r + 1 << endl;
	ll val;
	cin >> val;
	return val;
}

void work(int root) {
	for (auto &i : ans)
		i ^= root;
	cout << "! ";
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
	exit(0);
}

void solve() {
	cin >> n;
	ans.resize(n);
	map<int, int> mp;
	pii pr = {-1, -1};
	int one = -1, two = -1, zero = -1;
	for (int i = 1; i < n; i++) {
		ans[i] = x(0, i, 2);
		if (mp.find(ans[i]) != mp.end())
			pr = {mp[ans[i]], i};
		mp[ans[i]] = i;
		if (ans[i] == 0)
			zero = i;
		if (ans[i] == 1)
			one = i;
		if (ans[i] == 2)
			two = i;
	}	
	if (zero != -1)
		work(x(0, zero, 0));
	if (pr.F != -1) {
		int val = x(pr.F, pr.S, 0);
		int root = val ^ (ans[pr.F]);
		work(root);
	}
	assert(one != -1);
	assert(two != -1);
	int root = x(0, one, 0);
	root += x(0, two, 0) & 1;
	work(root); 
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}