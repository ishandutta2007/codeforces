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
const int N = 100015;

vector<int> vx[N], vy[N];

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		rep(j, 1, m) {
			int c;
			scanf("%d", &c);
			vx[c].pb(i); vy[c].pb(j);
		}
	}

	ll ans = 0;

	rep(i, 1, 100000) {
		rep(_, 0, 1) {
			sort(all(vx[i]));
			ll sum = 0, cnt = 0;

			for (int x : vx[i]) {
				ans += cnt * x - sum;
				cnt++; sum += x;
			}

			swap(vx[i], vy[i]);
		}
	}

	printf("%lld\n", ans);

	return 0;
}