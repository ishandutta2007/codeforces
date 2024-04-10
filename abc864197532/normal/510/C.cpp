#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
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
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 26, logN = 17;

vector <int> adj[N], radj[N];

vector <int> toposort(int n) {
	vector <int> degree(n), ans;
	queue <int> q;
	for (int i = 0; i < n; ++i) {
		degree[i] = radj[i].size();
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
    string pre, s;
    cin >> n >> pre;
    bool is = true;
	for (int i = 0; i < n - 1; ++i) {
    	cin >> s;
    	int aa = min(int(s.size()), int(pre.size()));
    	for (int i = 0;; ++i) {
    		if (i == aa) {
    			if (int(s.size()) < int(pre.size())) is = false;
    			break;
			}
    		if (pre[i] != s[i]) {
    			adj[pre[i] - 'a'].pb(s[i] - 'a');
    			radj[s[i] - 'a'].pb(pre[i] - 'a');
    			break;
			}
		}
    	pre = s;
	}
	if (!is) {
		cout << "Impossible\n";
	} else {
		vector <int> ans = toposort(N);
		if (ans.back() == -1) {
			cout << "Impossible\n";
		} else {
			for (int i = 0; i < N; ++i) cout << char('a' + ans[i]);
			cout << '\n';
		}
	}
}