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
const long long inf = ml * ml * ml + 7;
 
 
ll n, root;
vector<ll> p, v, sz, q, ans, col;
vector<vector<ll>> reb;
bool viv = false;

void bad() {
	cout << "NO\n";
	exit(0);
}

void DFS(ll v, ll c) {
	col[v] = c;
	for (auto s : reb[v])
		if (col[s] == -1) {
			DFS(s, c + 1);
			sz[v] += sz[s];
		}
	q.push_back(v);
}

void solve(ll vr, vector<ll> left) {
	if (viv) {
		cout << "Solve " << vr << " with: ";
		for (auto i : left)
			cout << i << ' ';
		cout << endl;
	}
	ans[vr] = left[v[vr]];
	if (v[vr] >= left.size())
		bad();
	left.erase(left.begin() + v[vr], left.begin() + v[vr] + 1);
	for (auto s : reb[vr])
		if (col[s] > col[vr]) {
			vector<ll> push;
			for (ll i = 0; i < sz[s]; i++) {
				if (left.empty())
					bad();
				push.push_back(left.back());
				left.pop_back();
			}
			reverse(push.begin(), push.end());
			solve(s, push);
		}
}

void solve() {
	cin >> n;
	reb.resize(n);
	root = -1;
	for (ll i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		if (a == -1)
			root = i;
		p.push_back(a);
		if (a != -1) {
			reb[i].push_back(a);
			reb[a].push_back(i);
		}
		v.push_back(b);
	}
	sz.resize(n, 1);
	col.resize(n, -1);
	DFS(root, 0);
	vector<ll> all;
	for (ll i = 1; i <= n; i++)
		all.push_back(i);
	ans.resize(n, 0);
	solve(root, all);
	cout << "YES\n";
	for (auto i : ans)
		cout << i << ' ';
	cout << endl;
}


int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
 //   cin >> t;
    while (t--)
    	solve();


    return 0;
}