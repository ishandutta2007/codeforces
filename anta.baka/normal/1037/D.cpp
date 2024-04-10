#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using vi = vector<int>;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define x first
#define y second
#define pb push_back

const int maxn = 5e5;
const int inf = 1e9;
const int mod = 1e9 + 7;
const ll inf64 = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-6;

vi g[maxn];
int a[maxn];
bool was[maxn];

main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++) {
    	int u, v; cin >> u >> v; u--; v--;
    	g[u].pb(v); g[v].pb(u);
    }
    for(int i = 0; i < n; i++) cin >> a[i], a[i]--;
	if(a[0] != 0) return cout << "No", 0;
	queue<set<int>> wa;
	wa.push({a[0]});
	for(int i = 0; i < n; i++) {
		if(wa.front().find(a[i]) == wa.front().end()) return cout << "No", 0;
		wa.front().erase(a[i]);
		if(wa.front().empty()) wa.pop();
		was[a[i]] = 1;
		set<int> nxt;
		for(int j : g[a[i]]) if(was[j] == 0) nxt.insert(j);
		if(!nxt.empty()) wa.push(nxt);
	}
	cout << "Yes";
}