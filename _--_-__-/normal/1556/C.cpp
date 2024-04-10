#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, c[100005];
LL ans;

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &c[i]);
	
	rep(i, n) if(!(i & 1)) {
		LL cs = 0, cm = 0;
		for(int j = i + 1; j < n; j ++) {
			if(j & 1) {
				LL ts = cs, tm = cm, t0 = c[i], t1 = c[j];
				if(ts < 0) {
					t0 += ts; tm = min(tm - ts, 0LL);
				} else if(ts > 0) t1 -= ts;
				if(t0 > 0 && t1 > 0 && t0 + tm >= 0 && t1 + tm >= 0) ans += min(t0, t1) + min(tm + 1, 0LL);
			}
			cs += j & 1 ? -c[j] : c[j];
			cm = min(cm, cs);
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}