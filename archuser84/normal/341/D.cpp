///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 1024;
const int S = 2000;

struct {
	ll x[S];
	int l1[S], r1[S];
	int l2[S], r2[S];
	int sz;
} buf;

ll a[N][N], b[N][N];
int n, m;

void flush()
{
	buf.sz = 0;
	Loop (_,0,2) {
		Loop (j,1,n) a[0][j] ^= a[0][j-1];
		Loop (i,1,n) {
			a[i][0] ^= a[i-1][0];
			Loop (j,1,n) {
				a[i][j] ^= a[i][j-1];
				a[i][j] ^= a[i-1][j];
				a[i][j] ^= a[i-1][j-1];
			}
		}
	}
	Loop (i,0,n) Loop (j,0,n) {
		b[i+1][j+1] ^= a[i][j];
		a[i][j] = 0;
	}
}

void push(ll x, int l1, int r1, int l2, int r2)
{
	int &sz = buf.sz;
	buf.l1[sz] = l1;
	buf.r1[sz] = r1;
	buf.l2[sz] = l2;
	buf.r2[sz] = r2;
	buf.x[sz] = x;
	++sz;
	a[l1][l2] ^= x;
	a[l1][r2] ^= x;
	a[r1][l2] ^= x;
	a[r1][r2] ^= x;
}

int mtl1, mtr1, mtl2, mtr2, mtl, mtr, mtflg = 1;
ll mtans;
void mtget()
{
	while (1) {
		while (mtflg == 1);
		if (mtflg)
			return;
		mtflg = 0;
		int l1 = mtl1, r1 = mtr1, l2 = mtl2, r2 = mtr2;
		int l = mtl, r = mtr;
		ll ans = 0;
		Loop (i,l,r) {
			ll x = buf.x[i];
			int ml1 = max(buf.l1[i], l1);
			int mr1 = min(buf.r1[i], r1);
			int d1 = mr1 - ml1;
			x &= -(d1 & 1);
			x &= -(d1 > 0);
			int ml2 = max(buf.l2[i], l2);
			int mr2 = min(buf.r2[i], r2);
			int d2 = mr2 - ml2;
			x &= -(d2 & 1);
			x &= -(d2 > 0);
			ans ^= x;
		}
		mtans = ans;
		mtflg = 1;
	}
}

ll get(int l1, int r1, int l2, int r2)
{
	ll ans = 0;
	ans ^= b[l1][l2];
	ans ^= b[l1][r2];
	ans ^= b[r1][l2];
	ans ^= b[r1][r2];
	Loop (i,0,buf.sz) {
		ll x = buf.x[i];
		int ml1 = max(buf.l1[i], l1);
		int mr1 = min(buf.r1[i], r1);
		int d1 = mr1 - ml1;
		x &= -(d1 & 1);
		x &= -(d1 > 0);
		int ml2 = max(buf.l2[i], l2);
		int mr2 = min(buf.r2[i], r2);
		int d2 = mr2 - ml2;
		x &= -(d2 & 1);
		x &= -(d2 > 0);
		ans ^= x;
	}
	return ans;
}

void foo() {}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	thread thr(foo);
	thr.join();
	while (m--) {
		int q, l1, r1, l2, r2;
		ll x;
		cin >> q >> l1 >> l2 >> r1 >> r2;
		--l1; --l2;
		if (q == 1) {
			cout << get(l1, r1, l2, r2) << '\n';
		} else {
			cin >> x;
			push(x, l1, r1, l2, r2);
		}
		if (buf.sz == S)
			flush();
	}
}