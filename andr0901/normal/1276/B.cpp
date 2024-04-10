#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

vector <vector <int>> gr;
vector <int> used;

void dfs(int v, int cur) {
	used[v] = cur;
	for (int u : gr[v])
		if (!used[u])
			dfs(u, cur);
}

set <int> inter(set <int>& a, set <int>& b) {
	set <int> ans;
	for (int i : a)
		if (b.find(i) != b.end())
			ans.insert(i);
	return ans;
}

void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b, a--, b--;
	gr = vector <vector <int>> (n);
	vector <int> A, B;
	forn (i, 0, m) {
		int v, u;
		cin >> v >> u, v--, u--;
		if (v != a && v != b &&
			u != a && u != b)
			gr[v].pb(u), gr[u].pb(v);
		if (v == a)
			A.pb(u);
		if (v == b)
			B.pb(u);
		if (u == a)
			A.pb(v);
		if (u == b)
			B.pb(v);
	}
	int cur = 1;
	used = vector <int> (n);
	forn (i, 0, n)
		if (!used[i])
			dfs(i, cur++);
	vector <int> cols(cur);
	forn (i, 0, n) {
		//cout << i << " " << used[i] << "\n";
		cols[used[i]]++;
	}
	set <int> connected_to_a;
	for (int v : A)
		connected_to_a.insert(used[v]);
	set <int> connected_to_b;
	for (int v : B)
		connected_to_b.insert(used[v]);
	set <int> banned = inter(connected_to_a, connected_to_b);
	banned.insert(used[a]), banned.insert(used[b]);
	forn (i, 0, sz(used))
			if (banned.find(used[i]) != banned.end()) {
				//cout << i << " ";
				n--;
			}
	/*cout << n << ":\n";
	for (int i : banned)
		cout << i << " ";
	cout << "\n";*/
	/*banned.insert(used[a]), banned.insert(used[b]);
	n -= 2;*/
	/*cout << "\n";
	for (int i :banned)
		cout << i << " ";
	cout << "\n";
	cout << n << "\n";*/
	/*long long ans = 0;
	forn (i, 0, cur) {
		//cout << cols[i] << " ";
		if (banned.find(i) != banned.end()) {
			//cout << i << " " << cols[i] << "\n";;
			ans += max(0LL, 1LL * cols[i] * (n - cols[i]));
		}
	}
	cout << ans / 2 << "\n";*/
	int sum_a = 0, sum_b = 0;
	forn (i, 0, cur) {
		if (i == used[a] || i == used[b])
			continue;
		if (connected_to_a.find(i) != connected_to_a.end() &&
			connected_to_b.find(i) == connected_to_b.end())
			sum_a += cols[i];
		if (connected_to_a.find(i) == connected_to_a.end() &&
			connected_to_b.find(i) != connected_to_b.end())
			sum_b += cols[i];
		//cout << sum_a << " " << sum_b << "\n";
	}
	cout << 1LL * sum_a * sum_b << "\n";
	//cout << "\n\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}