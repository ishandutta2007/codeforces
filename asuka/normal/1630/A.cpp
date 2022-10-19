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

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, k;
		scanf("%d%d", &n, &k);
		if (k == n - 1) {
			if (n == 4) puts("-1");
			else {
				printf("%d %d\n", n - 1, n - 2);
				printf("%d %d\n", 0, 1);
				printf("%d %d\n", 2, n - 1 - 3);
				printf("%d %d\n", 3, n - 1 - 2);
				rep(i, 4, n / 2 - 1) printf("%d %d\n", i, n - 1 - i);
			}
			continue;
		}
		vector<pii> vec;
		rep(i, 0, n - 1) {
			if (i == 0) {
				vec.emplace_back(0, (~k) & (n - 1));
			} else if (i == k) vec.emplace_back(k, n - 1);
			else {
				if (i == ((~k) & (n - 1)) || i == n - 1) continue;
				if (i < ((~i) & (n - 1))) vec.emplace_back(i, (~i) & (n - 1));
			}
		}
		for (auto [x, y] : vec) printf("%d %d\n", x, y);
	}
	return 0;
}