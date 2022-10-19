#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 1015;
int n, d[N], fa[N];
bool vis[N];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void solve() {
	cin >> n;
	rep(i, 1, n) cin >> d[i];
	rep(i, 1, n) fa[i] = i, vis[i] = 0;

	while (1) {
		int u = -1;

		rep(i, 1, n) if (!vis[i])
			if (u == -1 || d[i] > d[u])
				u = i;

		if (u == -1) break;
		vis[u] = 1;

		rep(_, 1, d[u]) {
			int v;
			cout << "? " << u << endl;
			cin >> v;
			fa[find(u)] = find(v);
			if (vis[v]) break;
			else vis[v] = 1;
		}
	}

	cout << "! ";
	rep(i, 1, n) cout << find(i) << ' ';
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}