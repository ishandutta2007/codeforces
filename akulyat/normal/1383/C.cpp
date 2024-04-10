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

// ifstream in;
// ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
bool viv = false;
string a, b;
int in[20], out[20];

vector<vector<int>> comp;

void DFS(int v, vector<bool> &used) {
	used[v] = true;
	comp.back().push_back(v);
	for (int s = 0; s < 20; s++)
		if ((out[v] & (1 << s)) || (in[v] & (1 << s)))
			if (!used[s])
				DFS(s, used);
}

void get_comp() {
	vector<bool> used(20, false);
	for (int i = 0; i < 20; i++)
		if (!used[i]) {
			comp.push_back({});
			DFS(i, used);
		}
}

int cnt(int val) {
	int res = 0;
	while (val)
		res += (val & 1), val >>= 1;
	return res;
}

void solve() {
	cin >> n;
	cin >> a >> b;	
	comp.clear();
	for (int i = 0; i < 20; i++)
		in[i] = out[i] = 0;

	for (int i = 0; i < n; i++)
		if (a[i] != b[i]) {
			out[a[i] - 'a'] |= (1 << (b[i] - 'a'));
			in[b[i] - 'a'] |= (1 << (a[i] - 'a'));
		}

	bool dag[1 << 20];	
	for (int i = 0; i < (1 << 20); i++)
		dag[i] = false;
	dag[0] = true;
	for (int mask = 0; mask < (1 << 20); mask++) {
		for (int i = 0; i < 20; i++)
			if ((mask >> i) & 1) {
				if (((mask ^ (1 << i)) & (in[i])) == 0)
					dag[mask] |= dag[mask ^ (1 << i)];
			}
	}
	get_comp();

	int ans = 0;
	for (auto c : comp) {
		if (viv) {
			for (auto i : c)
				cout << i << ' ';
			cout << endl;			
		}
		int sz = c.size();
		int mx_dag = 0;
		for (int smask = 0; smask < (1 << sz); smask++) {
			int mask = 0;
			for (int i = 0; i < sz; i++) 
				if ((smask >> i) & 1)
					mask ^= (1 << c[i]);
			if (dag[mask])
				mx_dag = max(mx_dag, cnt(mask));
		}
		ans += 2 * sz - mx_dag - 1;
	}
	cout << ans << '\n';
	if (viv)
		cout << "\t____\t____\t" << endl;
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}