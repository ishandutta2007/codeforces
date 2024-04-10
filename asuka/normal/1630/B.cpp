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
const int N = 200015;
int T, n, k, a[N], cnt[N];
bool check(int x) {
	int Max = 0;
	rep(i, 1, n) Max = max(Max, cnt[i + x] - cnt[i - 1]);
	return Max * 2 >= n + k;
}
void fuck(int ans) {
	pii Max = mp(0, 0);
	rep(i, 1, n) Max = max(Max, mp(cnt[i + ans] - cnt[i - 1], i));
	int x = Max.se, y = Max.se + ans;
	rep(i, 1, n) {
		if (x <= a[i] && a[i] <= y) a[i] = 1;
		else a[i] = -1;
	}
	int sum = 0, lst = 0;
	vector<pii> res;
	rep(i, 1, n) {
		sum += a[i];
		if (sum > 0) {
			if (SZ(res) + 1 < k || i == n) {
				res.emplace_back(lst + 1, i);
				lst = i; sum = 0;
			}
		}
	}
	printf("%d %d\n", x, y);
	for (auto [a, b] : res) printf("%d %d\n", a, b);
}
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) cnt[a[i]]++;
		rep(i, 1, n) cnt[i] += cnt[i - 1];
		int l = 0, r = n - 1, ans = n - 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		fuck(ans);
		rep(i, 1, n) cnt[i] = 0;
	}
	return 0;
}