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

int t, n, a[100015];

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		rep(i , 1, n) scanf("%d", a + i);

		int ans = 0;

		for (int l = 1, r; r = l, l <= n; l = r + 1) {
			if (a[l] == 0) continue;

			while (r < n && a[r + 1]) r++;

			ans++;
		}

		printf("%d\n", min(2, ans));
	}

	return 0;
}