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

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;

	while (t--) {
		int n, x, y, u[3], v[3];
		cin >> n;

		rep(i, 0, 2) {
			cin >> u[i] >> v[i];
		}

		cin >> x >> y;

		rep(i, 0, 2) {
			bool fl = 1;

			rep(j, 0, 2) if (i != j) {
				fl &= abs(u[i] - u[j]) + abs(v[i] - v[j]) == 1;
			}

			if (fl) {
				if ((u[i] == 1 || u[i] == n) && (v[i] == 1 || v[i] == n)) {
					if (x == u[i] || y == v[i]) {
						puts("YES");
					} else {
						puts("NO");
					}
				} else {
					if (((u[i] + v[i]) & 1) == ((x + y) & 1)) {
						puts(((x & 1) == (u[i] & 1) || (y & 1) == (v[i] & 1)) ? "YES" : "NO");
					} else puts("YES");
				}
			}
		}
	}
	return 0;
}