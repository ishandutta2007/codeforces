#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 200000, logN = 18, K = 350;

vector <int> adj[N], back_degree(N, 0);
 
vector <int> toposort(int n) {
	vector <int> degree(n), ans;
	queue <int> q;
	for (int i = 0; i < n; ++i) {
		degree[i] = back_degree[i];
		if (degree[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		int v = q.front(); q.pop();
		ans.push_back(v);
		for (int u : adj[v]) {
			degree[u]--;
			if (degree[u] == 0) q.push(u);
		}
	}
	if (ans.size() != n) {
		ans.clear();
		ans.push_back(-1);
	}
	return ans;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  lli a[n], c[n];
  int b[n];
  fop (i,0,n) cin >> a[i], c[i] = a[i];
  fop (i,0,n) {
    cin >> b[i];
    if (b[i] != -1) adj[i].pb(--b[i]), back_degree[b[i]]++;
  }
  vector <int> topo = toposort(n);
  vector <int> p, p2;
  lli ans = 0;
  for (int i : topo) {
    if (a[i] >= 0) {
      p.pb(i + 1);
      ans += a[i];
      if (b[i] != -1) a[b[i]] += a[i];
    } else {
      p2.pb(i + 1);
      ans += a[i];
    }
  }
  cout << ans << endl;
  FOP (i,p2.size(),0) p.pb(p2[i]);
  lli ans2 = 0;
  for (int i : p) {
    ans2 += c[i - 1];
    if (b[i - 1] != -1) c[b[i - 1]] += c[i - 1];
  }
  assert(ans == ans2);
  printv(p);
}