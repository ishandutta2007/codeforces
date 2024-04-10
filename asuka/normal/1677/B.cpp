#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 2e6 + 1;

int n, m, a[N], buc[N], pre[N];

void solve() {
	scanf("%d%d", &n, &m);
	fill(buc, buc + n * m + 1, 0);
	fill(pre, pre + n * m + 1, 0);

	rep(i, 1, n * m) scanf("%1d", &a[i]);

	{
		int cnt = 0;

		rep(r, 1, n * m) {
			int l = max(1, r - m + 1);
			cnt += a[r]; cnt -= a[l - 1];

			if (cnt == 0) buc[r]++;
		}

		rep(i, m, n * m) buc[i] += buc[i - m];
	}

	{
		rep(i, 1, m) {
			int cnt = 0;

			for (int j = i; j <= n * m; j += m) {
				cnt += a[j];

				if (cnt == 0) pre[j]++, pre[j + m]--;
			}
		}

		rep(i, 1, n * m) pre[i] += pre[i - 1];
	}

	rep(i, 1, n * m) {
		int res = n + m - buc[i] - pre[i] - max(m - i, 0) - (n - (i + m - 1) / m);

		printf("%d ", res);
	}

	printf("\n");
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int t;

	for (scanf("%d", &t); t; t--) solve();

	return 0;
}