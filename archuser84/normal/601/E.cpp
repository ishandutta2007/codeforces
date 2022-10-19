///
///   There's a reason for your defeat, DIO. One simple reason...
///   You pissed me off.
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 40'010;
const int lgN = 18;
const int K = 1010;
int lst[N], gv[N], gw[N];
int n, k;

vector<pii> t[N<<2];

void add(int l, int r, int v, int w, int i=0, int b=0, int e=N)
{
	if (l >= r) return;
	if (l <= b && e <= r) {t[i].push_back({v, w}); return;}
	if (r <= b || e <= l) return;
	add(l,r,v,w,2*i+1,b,(b+e)/2);
	add(l,r,v,w,2*i+2,(b+e)/2,e);
}

ll kn[lgN][K];
void kn_init(int i) {Loop (j,0,k+1) kn[i][j] = kn[i-1][j];}
void kn_add(int i, int v, int w) {LoopR (j,w,k+1) kn[i][j] = max(kn[i][j], kn[i][j-w] + v);}
ll kn_calc(int i) {
	const int p = 1e7+19, q = 1e9+7;
	ll cur = 1;
	ll ans = 0;
	Loop (j,1,k+1) {
		ans = (ans + kn[i][j]*cur) % q;
		cur = cur*p % q;
	}
	return ans;
}

ll ans[N];

void dfs(int d=0, int i=0, int b=0, int e=N)
{
	kn_init(d+1);
	for (auto [v, w] : t[i])
		kn_add(d+1, v, w);
	if (e-b == 1) {ans[b] = kn_calc(d+1); return;}
	dfs(d+1,2*i+1,b,(b+e)/2);
	dfs(d+1,2*i+2,(b+e)/2,e);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> k;
	Loop (i,0,n)
		cin >> gv[i] >> gw[i];
	int q, cnt3 = 0;
	cin >> q;
	while (q--) {
		int t, x, y;
		cin >> t;
		switch (t) {
		case 1:
			cin >> x >> y;
			lst[n] = cnt3;
			gv[n] = x;
			gw[n] = y;
			++n;
			break;
		case 2:
			cin >> x; --x;
			add(lst[x], cnt3, gv[x], gw[x]);
			lst[x] = -1;
			break;
		case 3:
			cnt3++;
			break;
		}
	}
	Loop (i,0,n) {
		if (lst[i] != -1)
			add(lst[i], cnt3, gv[i], gw[i]);
	}
	dfs();
	Loop (i,0,cnt3)
		cout << ans[i] << '\n';
}