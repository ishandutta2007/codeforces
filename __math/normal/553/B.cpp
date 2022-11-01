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

// #pragma comment(linker,"/STACK:36777216")

#ifdef _WIN32
#   define mygc(c) (c)=getchar()
#   define mypc(c) putchar(c)
#else
#   define mygc(c) (c)=getchar_unlocked()
#   define mypc(c) putchar_unlocked(c)
#endif

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

template<class T> void chmax(T& l, const T r){ l = max(l, r); }
template<class T> void chmin(T& l, const T r){ l = min(l, r); }

template<class T> T extgcd(T a, T b, T& x, T& y){ for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m){ T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }


vector<int> f(vector<int>& x){
	vector<int> ret;
	bool used[51] = {};

	vector<vector<int>> z;
	FOR(i, sz(x)){
		if (used[i]) continue;
		vector<int> tmp;
		int to = x[i];
		tmp.push_back(to);
		while (to != i+1) {
			to = x[to-1];
			tmp.push_back(to);
		}
		int id = max_element(tmp.begin(), tmp.end()) - tmp.begin();
		vector<int> tmp2;
		FOR(i, sz(tmp)){
			int u = tmp[(id + i + sz(tmp)) % sz(tmp)];
			tmp2.push_back(u);
			used[u-1] = true;
		}

		z.push_back(tmp2);
	}

	sort(z.begin(), z.end());
	for (auto& a : z) {
		for (auto& b : a) {
			ret.push_back(b);
		}
	}

	return ret;
}

vector<int> solve(int n, ll k){
	k--;
	bool used[50] = {};
	vector<int> ans;

	ll fib[52] = {};
	fib[0] = 0; fib[1] = 1;
	for (int i = 2; i < 52; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		// if (fib[i] > k) fib[i] = k + 10;
	}

	FOR(i, n - 1){
		int cnt = 0;
		if (k >= fib[n - i]) {
			k -= fib[n - i];
			cnt++;
		}

		FOR(j, n){
			if (used[j]) continue;
			if (cnt == 0) {
				used[j] = true;
				ans.push_back(j + 1);
				break;
			} else {
				cnt--;
			}
		}
	}
	FOR(i, n) if (!used[i]) ans.push_back(i + 1);
	return ans;
}

int test(int lp){

	vector<vector<int>> anses;
	vector<int> x;
	FOR(i, lp) x.push_back(i + 1);
	do {
		auto y = f(x);
		if (x == y) {
			anses.push_back(x);
		}
	}
	while (next_permutation(x.begin(), x.end()));

	FOR(i, sz(anses)){
		auto a = solve(sz(x), i + 1);
		if (anses[i] != a) {
			cout << "?";
		}
	}

	return 0;
}

void test2(){
	int n = 6;
	FOR(i, 1 << (n-1)){
		auto ans = solve(n, i + 1);
		writerArr(&ans[0], sz(ans));
	}
}

int main(){

	int n; ll k; cin >> n >> k;
	auto ans = solve(n, k);
	writerArr(&ans[0],sz(ans));
}