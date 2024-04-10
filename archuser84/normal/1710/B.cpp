#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 200'032;
const int S = 2048;
int n, m;
int big_x[N], p[N];
int x[N], x_len;
int i0[N], i1[N], i2[N];
bool ans[N];
int sum[N];

#define OPTIM __attribute__((optimize("O3,unroll-loops"),target("avx2")))

template<int side>
OPTIM
int add(int l, int r, int x, int p)
{
	int neg = 0;
	x = -x * side;
	const int x_p = x+p;
	Loop (i,l,r) {
		int tmp = x_p + side*::x[i];
		sum[i] = sum[i] + tmp;
		neg |= -(sum[i] < 0);
	}
	return neg;
}

OPTIM
bool is_all_less(int l, int r, int m)
{
	int ans = -1;
	Loop (i,l,r)
		ans &= -(sum[i] <= m);
	return ans;
}

OPTIM
bool is_greater(int l, int r, int m)
{
	int ans = 0;
	Loop (i,l,r)
		ans |= -(sum[i] > m);
	return ans;
}

template<int side>
OPTIM
bool is_greater_plus(int l, int r, int p, int x, int m)
{
	x = -x * side;
	const int x_p = x+p;
	int ans = 0;
	Loop (i,l,r) {
		int tmp = x_p + side*::x[i];
		ans |= -(sum[i] - tmp > m);
	}
	return ans;
}

template<class T>
T limit(T l, T x, T r)
{
	return x < l? l:
	       x > r? r:
	       x;
}

void solve()
{
	cin >> n >> m;
	fill(sum, sum+n, 0);
	fill(ans, ans+n, 1);
	Loop (i,0,n) {
		cin >> big_x[i] >> p[i];
		x[i] = big_x[i];
	}
	sort(x, x+n);
	x_len = unique(x, x+n) - x;
	Loop (i,0,n) {
		i0[i] = upper_bound(x, x+x_len, big_x[i]-p[i]) - x;
		i1[i] = lower_bound(x, x+x_len, big_x[i]) - x;
		i2[i] = lower_bound(x, x+x_len, big_x[i]+p[i]) - x;
	}
	bool is_neg = 0;
	for (int l = 0; l < x_len; l += S) {
		int r = min(x_len, l+S);
		Loop (i,0,n) {
			int i0 = limit(l, ::i0[i], r);
			int i1 = limit(l, ::i1[i], r);
			int i2 = limit(l, ::i2[i], r);
			is_neg |= add< 1>(i0, i1, big_x[i], p[i]);
			is_neg |= add<-1>(i1, i2, big_x[i], p[i]);
		}
	}
	if (is_neg) {
		Loop (i,0,n)
			cout << "0";
		cout << '\n';
		return;
	}
	for (int l = 0; l < x_len; l += S) {
		int r = min(l+S, x_len);
		if (is_all_less(l, r, m))
			continue;
		Loop (i,0,n) {
			if (!ans[i])
				continue;
			int i0 = limit(l, ::i0[i], r);
			int i1 = limit(l, ::i1[i], r);
			int i2 = limit(l, ::i2[i], r);
			if (i0 == r || i2 == l) {
				ans[i] = 0;
				continue;
			}
			ans[i] &= !is_greater(l, i0, m);
			ans[i] &= !is_greater_plus< 1>(i0, i1, p[i], big_x[i], m);
			ans[i] &= !is_greater_plus<-1>(i1, i2, p[i], big_x[i], m);
			ans[i] &= !is_greater(i2, r, m);
		}
	}
	Loop (i,0,n)
		cout << ans[i];
	cout << '\n';
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
		solve();
}