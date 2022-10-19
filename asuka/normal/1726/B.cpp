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
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);

		if (n > m || (n % 2 == 0 && m % 2 != 0)) {
			puts("No");
			continue;
		}

		if (n & 1) {
			puts("Yes");
			rep(i, 1, n - 1) printf("%d ", 1);
			printf("%d\n", m - n + 1);
		} else {
			n /= 2, m /= 2;
			puts("Yes");
			rep(i, 1, n - 1) printf("%d ", 1);
			printf("%d ", m - n + 1);
			rep(i, 1, n - 1) printf("%d ", 1);
			printf("%d\n", m - n + 1);
		}
	}
	return 0;
}