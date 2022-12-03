/*
start thinking:
BULB:
result of thinking: Pure.

cnt + TLE on 15 1e9+7.
upd:  /fn /fn 
uupd: gp_hash_table...
: cc_hash_table.

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}
const int LEN = 500000;
struct fastio {
  char s[LEN + 5];
  int len, it;
  fastio() {
    it = len = 0;
  }
  char get() {
    if (it < len)
      return s[it++];
    it = 0, len = fread(s, 1, LEN, stdin);
    return len ? s[it++] : EOF;
  }
  bool notend() {
    char c;
    for (c = get(); c == ' ' || c == '\n'; c = get())
      ;
    if (it)
      it--;
    return c != EOF;
  }
  void put(char c) {
    if (len == LEN)
      fwrite(s, 1, LEN, stdout), len = 0;
    s[len++] = c;
  }
  void flush() {
    fwrite(s, 1, len, stdout);
    len = 0;
  }
} buff, bufo;
inline int getint() {
  char c;
  int res = 0, sig = 1;
  for (c = buff.get(); c < '0' || c > '9'; c = buff.get())
    if (c == '-')
      sig = -1;
  for (; c >= '0' && c <= '9'; c = buff.get())
    res = (res << 3) + (res << 1) + (c - '0');
  return sig * res;
}
inline void putll(ll x) {
  if (!x)
    bufo.put('0');
  //  else if(x < 0) bufo.put('-'), x = -x;
  static char s[25];
  int k = 0;
  while (x) {
    s[++k] = x % 10 + '0';
    x /= 10;
  }
  for (int i = k; i >= 1; i--)
    bufo.put(s[i]);
}
 
#define maxn 300005
int n, a[maxn], m;
set<P> bad;
vector<int> lis[maxn];
map<int, int> cnt;

void solve() {
  bad.clear();
  cnt.clear();
  n = getint(), m = getint();
  for (int i = 1; i <= n; i++) {
    a[i] = getint();
    cnt[a[i]]++;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[i - 1])
      lis[cnt[a[i]]].push_back(a[i]);
  }
  for (int i = 1; i <= m; i++) {
    int x = getint(), y = getint();
    bad.insert({x, y});
    bad.insert({y, x});
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (lis[i].size() >= 2) {
      int foo = lis[i].size();
      priority_queue<pair<int, P>> que;
      set<P> app;
      que.push({lis[i][foo - 1] + lis[i][foo - 2], {foo - 2, foo - 1}});
      while (que.size() && bad.count({lis[i][que.top().second.first], 
          lis[i][que.top().second.second]})) {
        auto p = que.top();
        que.pop();
        if (app.count(p.second))
          continue;
        app.insert(p.second);
        if (p.second.first > 0)
          que.push({lis[i][p.second.first - 1] + lis[i][p.second.second],
                    {p.second.first - 1, p.second.second}});
        if (p.second.second > p.second.first + 1)
          que.push({lis[i][p.second.first] + lis[i][p.second.second - 1],
                    {p.second.first, p.second.second - 1}});
      }
      if (que.size())
        chmax(ans, ll(lis[i][que.top().second.first]
                + lis[i][que.top().second.second]) * (i + i));
    }
  }
  vector<int> on;
  for (int i = 1; i <= n; i++) {
    if (lis[i].size())
      on.push_back(i);
  }
  for (auto i : on) {
    for (auto j : on) {
      if (i >= j)
        continue;
      int foo = lis[i].size(), bar = lis[j].size();
      priority_queue<pair<int, P>> que;
      set<P> app;
      que.push({lis[i][foo - 1] + lis[j][bar - 1], {foo - 1, bar - 1}});
      while (que.size() && bad.count({lis[i][que.top().second.first], 
          lis[j][que.top().second.second]})) {
        auto p = que.top();
        que.pop();
        if (app.count(p.second))
          continue;
        app.insert(p.second);
        if (p.second.first)
          que.push({lis[i][p.second.first - 1] + lis[j][p.second.second],
                    {p.second.first - 1, p.second.second}});
        if (p.second.second)
          que.push({lis[i][p.second.first] + lis[j][p.second.second - 1],
                    {p.second.first, p.second.second - 1}});
      }
      if (que.size())
        chmax(ans, ll(lis[i][que.top().second.first]
                + lis[j][que.top().second.second]) * (i + j));
    }
  }
  putll(ans);
  bufo.put('\n');
  for (int i = 1; i <= n; i++)
    lis[i].clear();
}
int main() {
  // freopen("E.in", "r", stdin);
  int t = getint();
  while (t--) 
    solve();
  bufo.flush();
  return 0;
}