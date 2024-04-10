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
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 100015;
int n, In[N], Out[N], Cross[N], sx[N << 1], sy[N << 1];
vector<array<int, 3>> o;
int D[N << 1];
void add(int p, int v) {for(; p <= n + n; p += lowbit(p)) D[p] += v;}
int query(int p) {int res = 0; for(; p; p -= lowbit(p)) res += D[p]; return res;}
void calc(int res[], vector<array<int, 3>> vec, bool fx, bool fy) {
	memset(D, 0, sizeof D);
	for(auto &x : vec) {
		if(fx) x[0] = n + n - x[0] + 1;
		if(fy) x[1] = n + n - x[1] + 1;
	}
	sort(all(vec));
	for(auto p : vec) {
		int y = p[1], i = p[2];
		res[i] = query(y);
		add(y, 1);
	}
}
int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	scanf("%d", &n);
	rep(i, 1, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(x > y) swap(x, y);
		o.pb({x, y, i});
		sx[x] = sy[y] = 1;
	}
	rep(i, 1, n + n) sy[i] += sy[i - 1];
	per(i, 1, n + n) sx[i] += sx[i + 1];
	calc(In, o, 1, 0); calc(Out, o, 0, 1);
	ll ans = (ll) n * (n - 1) * (n - 2) / 6, tmp = 0;
	rep(i, 1, n) {
		int x = o[i - 1][0], y = o[i - 1][1];
		Out[i] += sy[x - 1] + sx[y + 1];
		Cross[i] = (y - x - 1) - In[i] * 2;
		tmp += (ll) Cross[i] * (n - 2);
		ans += (ll) Cross[i] * (Cross[i] - 1) / 2;
		ans -= (ll) In[i] * Out[i]; 
	}
	printf("%lld\n", ans - tmp / 2);
	return 0;
}