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


const ll MOD = ten(9) + 9;
const ll M = ten(8) + 7;
const ll M2 = M * M % MOD;
ll Mtbl[ten(5) + 10];
ll h1[ten(5) + 10], rh1[ten(5) * 10];
ll h2[ten(5) + 10], rh2[ten(5) * 10];
string s;

void init(){
	const int n = sz(s);
	FOR(i, n){
		h1[i + 1] = h1[i] * M % MOD;
		h2[i + 1] = h2[i] * M % MOD;
		if (i % 2 == 0) (h1[i + 1] += s[i]) %= MOD;
		if (i % 2 == 1) (h2[i + 1] += s[i]) %= MOD;
	}
	reverse(s.begin(), s.end());
	FOR(i, n){
		rh1[i + 1] = rh1[i] * M % MOD;
		rh2[i + 1] = rh2[i] * M % MOD;
		if (i % 2 == 0) (rh1[i + 1] += s[i]) %= MOD;
		if (i % 2 == 1) (rh2[i + 1] += s[i]) %= MOD;
	}
	reverse(s.begin(), s.end());

	Mtbl[0] = 1;
	FOR(i, n) Mtbl[i + 1] = (Mtbl[i] * M) % MOD;
}

struct X {
	ll hash;
	int len;
	int l, r;
	X() : hash(0), len(0) {}
	X(ll hash, int l, int r) : hash(hash), len(r - l), l(l), r(r) {
		this->hash %= MOD;
		if (this->hash < 0) this->hash += MOD;
	}

};

bool eq(X u,X v){
	return u.hash == v.hash;
}

//[l,r)
X substr(int l, int r){
	if ((r - l) % 2 == 0) r--;
	if (l % 2 == 0) {
		return X(h1[r] - h1[l] * Mtbl[r - l],l , r);
	} else {
		return X(h2[r] - h2[l] * Mtbl[r - l], l, r);
	}
}
//tnbV
X revsubstr(int l, int r){
	if ((r - l) % 2 == 0) l++;
	if ((sz(s) - l) % 2 == 1) {
		return X(rh1[sz(s) - l] - rh1[sz(s) - r] * Mtbl[r - l], sz(s) - r, sz(s) - l);
	} else {
		return X(rh2[sz(s) - l] - rh2[sz(s) - r] * Mtbl[r - l], sz(s) - r, sz(s) - l);
	}
}


struct Node {
	int last;
	int sum;
	int childs[2];
	Node(){
		last = 0;
		sum = 0;
		memset(childs, -1, sizeof(int) * 2);
	}
};


class trie_tree {

	vector<Node> nodes;

	int add_node(){
		nodes.push_back(Node());
		return sz(nodes) - 1;
	}

public:
	trie_tree(){
		clear();
	}

	void clear(){
		nodes.clear();
		add_node();
	}

	int add(const char* s,vector<int>& marks){
		int cur = 0;
		for (int i = 0; s[i]; i++) {
			int nxt = nodes[cur].childs[s[i] - 'a'];
			if (nxt == -1) {
				nxt = add_node();
				nodes[cur].childs[s[i] - 'a'] = nxt;
			}
			cur = nxt;
			nodes[cur].last += marks[i];
		}
		return cur;
	}

	int dfs(int v){
		FOR(i, 2){
			int nxt = nodes[v].childs[i];
			if (nxt == -1) continue;
			nodes[v].sum += dfs(nxt);
		}
		return nodes[v].sum += nodes[v].last;
	}

	string solve(int k){
		string ans;
		int cur = 0;
		while (k) {
			if (k <= nodes[cur].last) break;
			k -= nodes[cur].last;
			
			int n0 = nodes[cur].childs[0];
			if (n0 != -1) {
				if (k <= nodes[n0].sum) {
					ans.push_back('a');
					cur = n0;
					continue;
				} else {
					k -= nodes[n0].sum;
				}
			}
			int n1 = nodes[cur].childs[1];
			ans.push_back('b');
			cur = n1;
		}

		return ans;
	}
};

int main(){
	cin >> s;
	int k; cin >> k;

	init();

	trie_tree trie;
	const int n = sz(s);
	FOR(i, n){
		vector<int> mark;
		for (int j = i + 1; j <= n; j++) {
			int len = j - i;
			int len2 = (len + 1) / 2;
			X x1 = substr(i, i + len2);
			X x2 = revsubstr(j - len2, j);

			assert(x1.len == x2.len);
			mark.push_back(eq(x1,x2));
		}
		trie.add(s.c_str() + i, mark);
	}

	trie.dfs(0);
	auto ans = trie.solve(k);
	cout << ans << endl;
}