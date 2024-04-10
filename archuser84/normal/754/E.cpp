///
///   There's a reason for your defeat, DIO. One simple reason...
///   You pissed me off.
///

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 410;

bitset<N> bs[N][N];
bitset<N> ch[26][N];
char a[N][N], b[N][N];
int n, m, r, c;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	Loop(i,0,n) Loop(j,0,m) {
		cin >> a[i][j];
		ch[a[i][j] - 'a'][i][j] = 1;
	}
	cin >> r >> c;
	Loop(i,0,r) cin >> b[i];
	Loop(i,0,n) Loop(j,0,r) {
		bs[i][j].set();
		bs[i][j] ^= bs[i][j] << m;
		Loop(k,0,c) {
			if (b[j][k] == '?')
				continue;
			char c = b[j][k]-'a';
			int kk = k%m;
			bs[i][j] &= (ch[c][i]>>kk) ^ (ch[c][i]<<(m-kk));
		}
	}
	Loop(i,0,n) {
		Loop(j,0,m) {
			bool ans = 1;
			Loop(k,0,r)
				ans = ans && bs[(i+k)%n][k][j];
			cout << ans;
		}
		cout << '\n';
	}
}