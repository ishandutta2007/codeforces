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
#define int long long

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> dept(n);
    forn (i, 0, m) {
    	int v, u, w;
    	cin >> v >> u >> w, v--, u--;
    	if (min(v, u) > 0) {
    		dept[v] -= w;
    		dept[u] += w;
    	}
    	if (v == 0)
    		dept[u] += w;
    	if (u == 0)
    		dept[v] -= w;
    }
    set <pii> a;
    forn (i, 0, n) {
    	//cout << dept[i] << " ";
    	if (dept[i] != 0)
    		a.emplace(dept[i], i);
    }
    vector <vector <int>> ans;
    while (!a.empty() && a.begin() -> fs < 0 && a.rbegin() -> fs > 0) {
    	int w = min(-(a.begin() -> fs), a.rbegin() -> fs);
    	ans.pb({a.begin() -> sc, a.rbegin() -> sc, w});
    	//cout << w << " ";
    	if (-(a.begin() -> fs)  - w != 0)
    		a.emplace(a.begin() -> fs + w, a.begin() -> sc);
    	if (a.rbegin() -> fs  - w != 0)
    		a.emplace(a.rbegin() -> fs - w, a.rbegin() -> sc);
    	a.erase(a.begin());
    	a.erase(--a.end());
    }
    while (!a.empty()) {
    	if (a.begin() -> fs < 0)
    		ans.pb({a.begin() -> sc, 0, -(a.begin() -> fs)});
    	else
    		ans.pb({0, a.begin() -> sc, a.begin() -> fs});
    	a.erase(a.begin());
    }
    cout << sz(ans) << "\n";
    for (auto& i : ans) {
    	forn (j, 0, 3)
    		cout << i[j] + (j != 2) << " ";
    	cout << "\n";
    }
    return 0;
}