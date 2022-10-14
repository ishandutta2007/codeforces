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
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 1000087, logN = 17, K = 500;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

bool vis[50][50];

string ss[50];
int n;

void bfs (pii a) {
	queue <pii> q;
	q.push(a);
	vis[a.X][a.Y] = true;
	while (q.size()) {
		pii a = q.front(); q.pop();
		fop (k,0,4) {
			pii b = {a.X + dx[k], a.Y + dy[k]};
			if (b.X >= 0 && b.X < n && b.Y >= 0 && b.Y < n) {
				if (!vis[b.X][b.Y] && ss[b.X][b.Y] == '0') q.push(b), vis[b.X][b.Y] = true;
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int r1, c1, r2, c2;
	cin >> n >> r1 >> c1 >> r2 >> c2, r1--, c1--, r2--, c2--;
	fop (i,0,n) cin >> ss[i];
	fop (i,0,n) fop (j,0,n) vis[i][j] = false;
	vector <pii> s, t;
	bfs({r1, c1});
	fop (i,0,n) fop (j,0,n) {
		if (vis[i][j]) {
			s.eb(i, j);
			vis[i][j] = false;
		}
	}
	bfs({r2, c2});
	fop (i,0,n) fop (j,0,n) {
		if (vis[i][j]) {
			t.eb(i, j);
			vis[i][j] = false;
		}
	}
	int ans = 1 << 30;
	for (pii A : s) {
		for (pii B : t) {
			ans = min(ans, (A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y));
		}
	}
	cout << ans;
}