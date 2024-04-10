#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld long double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500007, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void solve() {
	int n, m;
	cin >> n >> m;
	string a[n + 2];
	fop (i,0,m + 2) a[0].pb('#');
	fop (i,0,m + 2) a[n + 1].pb('#');
	fop (i,1,n + 1) {
		cin >> a[i];
		a[i] = '#' + a[i] + '#';
	}
	bool is = true;
	fop (i,1,n + 1) fop (j,1,m + 1) {
		if (a[i][j] == 'B') {
			fop (k,0,4) {
				if (a[i + dx[k]][j + dy[k]] == 'G') {
					is = false;
				} else if (a[i + dx[k]][j + dy[k]] != 'B') {
					a[i + dx[k]][j + dy[k]] = '#';
				}
			}
		}
	}
                queue <pii> q;
		int x, y;
		bool vis[n + 2][m + 2];
		fop (_,0,n + 2) fop ($,0,m + 2) vis[_][$] = false;
           if (a[n][m] != '#') {
		q.push({n, m});
		vis[n][m] = true;
		while (q.size()) {
			tie(x, y) = q.front(); q.pop();
			fop (k,0,4) if (a[x + dx[k]][y + dy[k]] != '#' and !vis[x + dx[k]][y + dy[k]]) {
				vis[x + dx[k]][y + dy[k]] = true;
				q.push({x + dx[k], y + dy[k]});
			}
		}
        }
	fop (i,1,n + 1) fop (j,1,m + 1) if (a[i][j] == 'G') {
		
		if (!vis[i][j]) is = false;
	}
	cout << (is ? "Yes\n" : "No\n");
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}