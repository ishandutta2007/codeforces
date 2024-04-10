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
int a[111111];

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);

		if (n == 1) {
			printf("0\n");
			continue;
		}

		int ans = a[n] - a[1];
		rep(i, 1, n) ans = max(ans, a[i] - a[i % n + 1]);
		ans = max(ans, *max_element(a + 2, a + n + 1) - a[1]);
		ans = max(ans, a[n] - *min_element(a + 1, a + n));		
		printf("%d\n", ans);
	}

	return 0;
}