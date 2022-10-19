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
const int N = 200015;
int n, m, a[N], b[N], r[N], d[N], p, q;

bool check(int k) {
	r[0] = m, d[0] = n;

	rep(i, 1, n) {
		r[i] = r[i - 1];
		while (r[i] && a[i] + b[r[i]] > k)
			r[i]--;
	}

	rep(j, 1, m) {
		d[j] = d[j - 1];
		while (d[j] && b[j] + a[d[j]] > k)
			d[j]--;
	}

	ll ans = 0, cur = 0, sum = 0;
	rep(i, 1, n)
		sum += m - r[i];
	ans = cur = sum;

	for (int i = 1, j = 0; i <= n; ++i) {
		cur += min(j, r[i]) - (m - max(r[i], j));

		while (j < m) {
			int o = min(d[j + 1], i) - (n - max(d[j + 1], i));
			if (o < 0) break;
			cur += o, j++;
		}
		
		ans = max(ans, cur);
	}

	cur = sum;

	for (int i = 1, j = 0; i <= n; ++i) {
		cur += min(j, r[i]) - (m - max(r[i], j));

		while (j < m) {
			int o = min(d[j + 1], i) - (n - max(d[j + 1], i));
			if (o < 0) break;
			cur += o, j++;
		}
		
		if (cur == ans && (i >= p || j >= q)) return 1;
	}


	return 0;
}

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, m) scanf("%d", &b[i]);
	p = a[1], q = b[1];
	sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
	rep(i, 1, n) if (a[i] == p) { p = i;  break; }
	rep(i, 1, m) if (b[i] == q) { q = i;  break; }
	int lb = 1, rb = a[p] + b[q] - 1, ans = rb + 1;

	while (lb <= rb) {
		int mid = (lb + rb) >> 1;
		if (check(mid)) ans = mid, rb = mid - 1;
		else lb = mid + 1;
	}

	printf("%d\n", ans);
	return 0;
}