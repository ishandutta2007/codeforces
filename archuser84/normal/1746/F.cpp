#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

typedef unsigned long long u64;
const int N = 300'010;
const int K = 32;

valarray<u64> fen[N];
valarray<u64> a[N];
const valarray<u64> zero(0ull, K);

static uint64_t hsh(uint64_t x) {
	// http://xorshift.di.unimi.it/splitmix64.c
	x += 0x9e3779b97f4a7c15;
	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
	x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
	return x ^ (x >> 31);
}


valarray<u64> to_arr(u64 x)
{
	static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
	x += FIXED_RANDOM;
	valarray<u64> ans(0ull, K);
	Loop (i,0,K)
		ans[i] = hsh(x + i*i*i + i) % (1ull<<32);
	return ans;
}

void fen_add(int i, valarray<u64> x)
{
	++i;
	while (i < N) {
		fen[i] += x;
		i += i & -i;
	}
}

valarray<u64> fen_get(int r)
{
	valarray<u64> ans(0ull, K);
	while (r > 0) {
		ans += fen[r];
		r -= r & -r;
	}
	return ans;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	Loop (i,0,N)
		fen[i] = zero;
	int n, q;
	cin >> n >> q;
	Loop (i,0,n) {
		int x;
		cin >> x;
		auto y = to_arr(x);
		a[i] = y;
		fen_add(i, y);
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int i, x;
			cin >> i >> x;
			--i;
			auto y = to_arr(x);
			fen_add(i, y - a[i]);
			a[i] = y;
		} else {
			int l, r, k;
			cin >> l >> r >> k;
			--l;
			auto y = fen_get(r);
			y -= fen_get(l);
			bool ans = 1;
			Loop (i,0,K) {
				ans &= y[i]%k == 0;
			}
			cout << (ans? "YES": "NO") << '\n';
		}
	}
}