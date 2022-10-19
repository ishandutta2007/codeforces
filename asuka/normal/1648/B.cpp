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
int T, n, c;
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &T);

	while (T--) {
		scanf("%d%d", &n, &c);
		vector<int> sum(c + 1, 0);
		rep(i, 1, n) {
			int x;
			scanf("%d", &x);
			sum[x] = 1;
		}
		rep(i, 1, c) sum[i] += sum[i - 1];
		bool flag = 1;
		rep(i, 1, c) {
			if (sum[i] > sum[i - 1]) continue;

			for (int j = 1; j * i <= c; ++j) {
				if (sum[j] > sum[j - 1] && sum[min(c, (i + 1) * j - 1)] > sum[i * j - 1]) flag = 0;
			}
		}
		puts(flag ? "Yes" : "No");
	}

	return 0;
}