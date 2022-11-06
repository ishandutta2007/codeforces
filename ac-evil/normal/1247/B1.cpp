#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (int i = a, end = b; i >= end; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)

const int maxn = 200000 + 5;

int T;
int N, K, D;
int a[maxn];

int cnt[maxn * 5], sgm = 0;

void add(int x) { if (!cnt[a[x]]) sgm++; cnt[a[x]]++; }
void del(int x) { cnt[a[x]]--; if (!cnt[a[x]]) sgm--; }

int wty(int x) {
	int ans = 1;
	for (register int l = 1, r = 1; l <= N; del(l++)) {
		while (sgm <= x && r <= N) add(r++);
		if (sgm > x) del(--r);
		chkmax(ans, r-l);
	}
	return ans;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &N, &K, &D);
		rep(i, 1, N) scanf("%d", &a[i]);
		int l = 1, r = N;
		while (l < r) {
			int mid = l+r>>1;
			if (wty(mid) >= D) r = mid; else l = mid+1;
		}
		printf("%d\n", r);
	}
	return 0;
}