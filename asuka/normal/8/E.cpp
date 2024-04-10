#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n, a[105];
ll f[105][2][2]; // i, top1, top2
ll k;
ll get() {
	memset(f, 0, sizeof f);
	f[0][1][1] = 1;
	rep(i, 1, n / 2) {
		if (a[i] == -1) {
			rep(p, 0, 1) rep(q, 0, 1) rep(t1, 0, p <= q) rep(t2, 0, !(p & q)) {
				f[i][t1 & (p == q)][t2 & (p ^ q)] += f[i - 1][t1][t2];
			}
		} else {
			rep(p, a[i], a[i]) rep(q, 0, 1) rep(t1, 0, p <= q) rep(t2, 0, !(p & q)) {
				f[i][t1 & (p == q)][t2 & (p ^ q)] += f[i - 1][t1][t2];
			}
		}
	}
	bool flag = 1;
	rep(i, 1, n / 2) flag &= a[i] <= 0;
	ll res = 0;
	rep(t1, 0, 1) rep(t2, 0, 1) res += f[n / 2][t1][t2]; // 0 0
	if (n & 1) rep(t1, 0, 1) res += f[n / 2][t1][0]; // 1 1
	return res - flag; // 000000...0000
}
ll Get() {
	memset(f, 0, sizeof f);
	if(n & 1) {
		if(a[n / 2 + 1] != 0) f[0][0][1] = 1; // 1 1
		if(a[n / 2 + 1] != 1) f[0][0][0] = 1; // 0 0
	} else f[0][0][0] = 1;
	rep(i, 1, n / 2) {
		if(a[n - n / 2 + i] == -1) {
			int p = a[n / 2 - i + 1];
			rep(q, 0, 1) rep(t1, 0, 1) rep(t2, 0, 1) {
				f[i][(p < q) ? 0 : (t1 | (p > q))][(!(p | q)) ? 0 : (t2 | (p & q))] += f[i - 1][t1][t2];
			}
		} else {
			int p = a[n / 2 - i + 1];
			rep(q, a[n - n / 2 + i], a[n - n / 2 + i]) rep(t1, 0, 1) rep(t2, 0, 1) {
				f[i][(p < q) ? 0 : (t1 | (p > q))][(!(p | q)) ? 0 : (t2 | (p & q))] += f[i - 1][t1][t2];
			}
		}
	}
	bool flag = 1;
	rep(i, 1, n) flag &= a[i] <= 0;
	return f[n / 2][0][0] - flag;
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> n >> k;
	memset(a, -1, sizeof a);
	rep(i, 1, n / 2) {
		int ans = -1;
		rep(p, 0, i == 1 ? 0 : 1) {
			a[i] = p;
			ll res = get();
			cerr << res << ' ';
			if (res < k) {
				k -= res;
			} else {
				ans = p;
				break;
			}
		}
		cerr << endl;
		if(ans == -1) {
			puts("-1");
			return 0;
		}
		a[i] = ans;
	}
	rep(i, n / 2 + 1, n) {
		int ans = -1;
		rep(p, 0, 1) {
			a[i] = p;
			ll res = Get();
			cerr << res << ' ';
			if (res < k) {
				k -= res;
			} else {
				ans = p;
				break;
			}
		}
		cerr << endl;
		if(ans == -1) {
			puts("-1");
			return 0;
		}
		a[i] = ans;
	}
	rep(i, 1, n) cout << a[i];
	return 0;
}