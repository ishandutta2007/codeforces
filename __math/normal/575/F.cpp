#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <ctime>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)

void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }

void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }

ll mod_pow(ll a, ll n, ll mod) {ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
template<class T> T extgcd(T a, T b, T& x, T& y){ for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m){ T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }

int n;

vector<int> cm;
ll dp[2][ten(5) * 2];

int id(int x){
	return lower_bound(cm.begin(), cm.end(), x) - cm.begin();
}

int main(){
	reader(n);
	memset(dp, 0x1f, sizeof(dp));
	auto cur = dp[0], nt = dp[1];

	int x; reader(x);
	cm.push_back(x);
	vector<Pii> vp;
	FOR(i, n){
		int a, b; reader(a, b);
		vp.emplace_back(a, b);
		cm.push_back(a);
		cm.push_back(b);
	}
	sort(cm.begin(), cm.end());
	cm.erase(unique(cm.begin(), cm.end()), cm.end());
	
	x = id(x);
	FOR(i, n){
		vp[i].first = id(vp[i].first);
		vp[i].second = id(vp[i].second);
	}

	cur[x] = 0;
	FOR(i, n){
		memset(nt, 0x1f, sizeof(cur[0]) * sz(cm));
		int l, r; tie(l, r) = vp[i];
		deque<Pll> right_deq;
		FOR(i, sz(cm)){
			ll cur_cost = cur[i] + cm[i];
			while (sz(right_deq) && right_deq.back().first >= cur_cost)
				right_deq.pop_back();
			right_deq.push_back(Pll(cur_cost, i));
		}

		ll left_min = ll(ten(9)) * ten(8);

		FOR(i, sz(cm)){
			if (sz(right_deq) && right_deq.front().second < i)
				right_deq.pop_front();

			ll add_cost = 0;
			if (i < l) add_cost = cm[l] - cm[i];
			else if (r < i) add_cost = cm[i] - cm[r];

			ll right_cost = ll(ten(9)) * ten(8);
			if (sz(right_deq)) {
				right_cost = right_deq.front().first - cm[i];
			}
			
			ll left_cost = left_min + cm[i];
			nt[i] = min(right_cost,left_cost) + add_cost;

			left_min = min(left_min, cur[i] - cm[i]);
		}

		//FOR(i, sz(cm)){
		//	printf("%d:%d ,", cm[i],nt[i]);
		//}
		//puts("");
		swap(cur, nt);
	}

	ll ans = numeric_limits<ll>::max();
	FOR(i, sz(cm)) ans = min(ans, cur[i]);

	cout << ans << endl;

	return 0;
}