#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int B = 2323;
int n, m, a[N];
ll ans[N], f[N], sum[N], cnt[N];
struct fenwick {
	ll D[300015];
	void add(int p, int v) {
		p++;
		for (; p <= m + 1; p += lowbit(p)) D[p] += v;
	}
	ll query(int p) {
		if(p < 0) return 0;
		p = min(p, m);
		p++;
		ll res = 0;
		for (; p; p -= lowbit(p)) res += D[p];
		return res;
	}
}T, S;
int main() {
	// freopen("test.txt","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) sum[i] = sum[i - 1] + a[i];
	m = *max_element(a + 1, a + n + 1);
	rep(i, 1, n) {
		ans[i] = ans[i - 1];
		int p = a[i];
		// a[j] % a[i]
		if (p <= B) {
			ans[i] += f[p];
		} else {
			ans[i] += sum[i - 1];
			for (int k = 0; k * p <= m; ++k) {
				ll tmp = T.query((k + 1) * p - 1) - T.query(k * p - 1); //[k * p, (k + 1) * p)
				ans[i] -= tmp * k * p;
			}
		}
		// a[i] % a[j]
		rep(k, 1, B) ans[i] += cnt[k] * (p % k);
		ans[i] += cnt[B + 1] * p + S.query(p);
		// update
		rep(k, 1, B) f[k] += (p % k);
		T.add(p, 1);
		cnt[min(p, B + 1)]++;
		if(p > B) {
			for(int k = 0; k * p <= m; ++k) { //[k * p, (k + 1) * p - 1) - k * p
				S.add(k * p, -k * p);
				if((k + 1) * p <= m) S.add((k + 1) * p, k * p);
			}
		}
	}
	rep(i, 1, n) printf("%lld ", ans[i]);
	return 0;
}