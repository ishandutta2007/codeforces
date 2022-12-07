#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <bitset>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ldouble;
typedef unsigned long long ull;
const int LEN = 100000;
struct fastio {
  int it, len;
  char s[LEN + 5];
  fastio() {
    it = len = 0;
  }
  char get() {
    if(it < len) return s[it++];
    it = 0, len = fread(s, 1, LEN, stdin);
    return len ? s[it++] : EOF;
  }
  bool notend() {
    char c;
    for (c = get();c == ' ' || c == '\n' || c == '\r';c = get());
    if (it) it--;
    return c != EOF;
  }
  void put(char c) {
    if(it == LEN) fwrite(s,1,LEN,stdout), it = 0;
    s[it++] = c;
  }
  void flush() {
    fwrite(s, 1, it, stdout);
  }
}buff, bufo;
inline int getint() {
  char c; int res = 0, sig = 1;
  for (c = buff.get(); c < '0' || c > '9'; c = buff.get()) if(c == '-') sig = -1;
  for (;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline ll getll() {
  char c; ll res = 0, sig = 1;
  for (c = buff.get(); c < '0' || c > '9'; c = buff.get()) if (c == '-') sig = -1;
  for (; c >= '0' && c <= '9'; c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline void putint(int x, char suf) {
  if (!x) bufo.put('0');
  else {
    if (x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[15];
    while (x) {
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for (; k; k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline void putll(ll x, char suf) {
  if (!x) bufo.put('0');
  else {
    if (x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[25];
    while (x) {
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for (; k; k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline char get_char() {
  char c;
  for (c = buff.get(); c == ' ' || c == '\n' || c == '\r'; c = buff.get());
  return c;
}

#define maxn 200005
#define mp make_pair 
typedef pair<int, int> P;

struct Bitset {
  #define SIZ 6250
	unsigned a[SIZ + 5]; // set a value you like.
	void reset() {
		memset(a, 0, sizeof(a));
	}
	Bitset() {
		reset();
	}
	void flip(int x) {
		a[x >> 5] ^= 1 << (x & 31);
	}
	void set(int x) {
		a[x >> 5] |= 1 << (x & 31);
	}
	void reset(int x) {
		a[x >> 5] &= ~(1 << (x & 31));
	}
	int at(int x) {
		return (a[x >> 5] >> (x & 31)) & 1;
	}
	Bitset operator ~() const {
		Bitset ret;
		for (int i = 0; i < SIZ; i++) ret.a[i] = ~a[i];
		return ret;
	}
	Bitset operator & (const Bitset &b) const {
		Bitset ret;
		for (int i = 0; i < SIZ; i++) ret.a[i] = a[i] & b.a[i];
		return ret;
	}
	Bitset operator | (const Bitset &b) const {
		Bitset ret;
		for (int i = 0; i < SIZ; i++) ret.a[i] = a[i] | b.a[i];
		return ret;
	}
	Bitset operator ^ (const Bitset &b) const {
		Bitset ret;
		for(int i = 0; i < SIZ; i++) ret.a[i] = a[i] ^ b.a[i];
		return ret;
	}
	bool operator < (const Bitset &b) const {
	  for (int i = SIZ - 1; i >= 0; i--) {
	    if (a[i] > b.a[i]) return false;
	    if (a[i] < b.a[i]) return true;
	  }
	  return false;
	}
	int count() const {
	  int res = 0;
		for(int i = 0; i < SIZ; i++) res += __builtin_popcount(a[i]);
		return res;
	}
	#undef SIZ
};

int n, m, k, ans;
vector<P> adj[maxn];
Bitset cov[10][10], all, cur;

void bf(int x) {
  if (x > k) {
    ans += (cur.count() == n);
    return;
  }
  for (int i = 1; i <= x; i++) {
    if ((cur & cov[x][i]).count()) continue;
    cur = cur ^ cov[x][i];
    bf(x + 1);
    cur = cur ^ cov[x][i];
  }
}

map<Bitset, int> cnt;
void dfs(int x, int lim) {
  if (x > lim) {
    cnt[cur]++;
    return;
  }
  for (int i = 1; i <= x; i++) {
    if ((cur & cov[x][i]).count()) continue;
    cur = cur ^ cov[x][i];
    dfs(x + 1, lim);
    cur = cur ^ cov[x][i];
  }
}
void check(int x) {
  if (x > k) {
    ans += cnt[all ^ cur];
    return;
  }
  for (int i = 1; i <= x; i++) {
    if ((cur & cov[x][i]).count()) continue;
    cur = cur ^ cov[x][i];
    check(x + 1);
    cur = cur ^ cov[x][i];
  }
}

int main() {
  n = getint(), m = getint(), k = getint();
  for (int i = 0; i < n; i++) all.set(i);
  for (int i = 1; i <= m; i++) {
    int u = getint() - 1, v = getint() - 1, w = getint();
    adj[u].push_back(mp(w, v));
  }
  for (int i = 0; i < n; i++) {
    sort(adj[i].begin(), adj[i].end());
    int deg = adj[i].size();
    for (int j = 0; j < deg; j++) {
      cov[deg][j + 1].set(adj[i][j].second);
    }
  }
  if (k <= 4) {
    bf(1);
  } else {
    int B = k * 2 / 3;
    dfs(1, B);
    check(B + 1);
  }
  putint(ans, '\n');
  bufo.flush();
  return 0;
}