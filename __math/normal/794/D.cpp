#include <bits/stdc++.h>

using namespace std;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
int reader(string& c) { int i; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c.push_back(i); for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c.push_back(i); }; return sz(c); }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }
void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const string& x, char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }
template<class T> void writerArr(vector<T>& x) { writerArr(x.data(), (int)x.size()); }

template<class T> void chmin(T& a, const T& b) { if (a > b) a = b; }
template<class T> void chmax(T& a, const T& b) { if (a < b) a = b; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
ll mod_pow(ll a, ll n, ll mod) {
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
template<class T> T CRT(T m1, T r1, T m2, T r2) { T a1, a2; extgcd(m1, m2, a1, a2); T ret = (m1*a1*r2 + m2*a2*r1) % (m1*m2); return ret < 0 ? ret + m1 * m2 : ret; }


int main() {
	int n, m; reader(n, m);
	vector<pair<int, vector<int>>> vp(n);
	FOR(i, m) {
		int a, b; reader(a, b); a--; b--;
		vp[a].second.push_back(b);
		vp[b].second.push_back(a);
	}
	FOR(i, n) vp[i].second.push_back(i);
	FOR(i, n) {
		vp[i].first = i;
		sort(vp[i].second.begin(), vp[i].second.end());
	}
	sort(vp.begin(), vp.end(), [](const pair<int, vector<int>>& l, const pair<int, vector<int>>& r) {
		return l.second < r.second;
	});
	vector<int> icolor(n);
	static vector<int> icolor2vp[ten(5) * 3 + 10];
	{
		int cur = 1;
		FOR(i, n) {
			if (i != 0) {
				if (vp[i - 1].second != vp[i].second) {
					cur++;
				}
			}
			icolor[vp[i].first] = cur;
			icolor2vp[cur].push_back(i);
		}
	}

	int start_color = -1;
	FOR(i, sz(vp)) {
		set<int> to_color;
		auto& kv = vp[i];
		for (auto to : kv.second) {
			if (icolor[kv.first] != icolor[to]) to_color.insert(icolor[to]);
		}
		if (sz(to_color) <= 1) {
			start_color = icolor[kv.first];
			break;
		}
	}
	if (start_color == -1) {
		puts("NO");
		return 0;
	}

	static int color_map[ten(5) * 3 + 10];
	{
		int actual_color = 1;
		queue<int> coldq;
		coldq.push(start_color);
		while (!coldq.empty()) {
			const int col = coldq.front(); coldq.pop();
			color_map[col] = actual_color++;

			const int vp_index = icolor2vp[col][0];
			const auto& tov = vp[vp_index].second;
			set<int> to_color;
			for (auto to : tov) {
				if (color_map[icolor[to]] == 0) to_color.insert(icolor[to]);
			}
			if (sz(to_color) >= 2) {
				puts("NO");
				return 0;
			}
			for (auto nxt : to_color) {
				coldq.push(nxt);
			}
		}
	}

	vector<int> ans(n);
	FOR(i, n) ans[i] = color_map[icolor[i]];
	static int csum[ten(5) * 3 + 10];
	FOR(i, n) csum[ans[i]]++;

	for (auto& kv : vp) {
		int cnt = 0;
		const int c = ans[kv.first];
		for (auto to : kv.second) {
			if (abs(c - ans[to]) > 1) {
				puts("NO");
				return 0;
			}
			cnt++;
		}
		if (cnt != csum[c - 1] + csum[c] + csum[c + 1]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	writerArr(ans);

	return 0;
}