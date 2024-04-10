#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a), end(a);
/*>_<*/
const int N = 1e5 + 28, inf = 0x3f3f3f3f;
const int S = sqrt(N) + 0.5;
ll s[N], val[N * 3], cnt[N * 3], qa[N];
int tp;
pair<int,pii> p[N];
struct qry
{
	int g, l, r, i;
	bool operator < (const qry & x) const
	{
		return g < x.g || (g == x.g && r < x.r);
	}
} q[N];
int gi(ll v)
{
	return lower_bound(val,val+tp,v) - val;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> s[i];
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		if (s[i] == 2)
			a = -a;
		s[i] = a + s[i-1];
	}
	for (int i = 0; i <= n; ++i) {
		val[tp++] = s[i] - k;
		val[tp++] = s[i];
		val[tp++] = s[i] + k;
	}
	sort(val, val + tp);
	for (int i = 0; i <= n; ++i)
		p[i] = {gi(s[i]), {gi(s[i]-k),gi(s[i]+k)}};
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		q[i] = {l/S,l,r,i};
	}
	sort(q,q+m);
	int l = q[0].l, r = q[0].l-1;
	ll ans = 0;
	for (int i = 0; i < m; ++i) {
		while (r < q[i].r) {
			++r;
			ans += cnt[p[r].S.F];
			++cnt[p[r].F];
		}
		while (l > q[i].l) {
			--l;
			ans += cnt[p[l].S.S];
			++cnt[p[l].F];
		}
		while (r > q[i].r) {
			--cnt[p[r].F];
			ans -= cnt[p[r].S.F];
			--r;
		}
		while (l < q[i].l) {
			--cnt[p[l].F];
			ans -= cnt[p[l].S.S];
			++l;
		}
		qa[q[i].i] = ans;
	}
	for (int i = 0; i < m; ++i)
		cout << qa[i] << '\n';
}