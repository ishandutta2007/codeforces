/*


Q.E.D.

start thinking:
BULB:
result of thinking:

standard exercise
.

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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 100005
#define maxm 100005
const ll infll = 0x3f3f3f3f3f3f3f3f;
int n, m, p, sumd[maxn], t[maxm];
ll sumt[maxm], f[maxm], nxt[maxm];

Pll operator + (const Pll& a, const Pll& b) {
  return Pll(a.first + b.first, a.second + b.second);
}

bool convex(Pll A, Pll B, Pll C) {
  #define x first
  #define y second
  return 1.0L * (A.x - B.x) * (C.y - B.y) < 1.0L * (A.y - B.y) * (C.x - B.x);
  #undef x
  #undef y
}

int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 2; i <= n; i++) {
    scanf("%d", sumd + i);
    sumd[i] += sumd[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    int u;
    scanf("%d%d", &u, t + i);
    t[i] -= sumd[u];
  }
  if (p >= m) {
    puts("0");
    return 0;
  }
  sort(t + 1, t + m + 1);
  for (int i = 1; i <= m; i++) {
    sumt[i] = sumt[i - 1] + t[i];
    f[i] = (ll)i * t[i] - sumt[i];
  }
  for (int j = 2; j <= p; j++) {
    // memset(nxt, 0x3f, sizeof(nxt));
    deque<Pll> deq;
    for (int i = j; i <= m; i++) {
      Pll p = Pll(i - 1, f[i - 1] + sumt[i - 1]);
      while (deq.size() > 1 && !convex(deq[deq.size() - 2], deq.back(), p))
        deq.pop_back();
      deq.push_back(p);
      while (deq.size() > 1 && convex(deq[0], deq[1], deq[1] + Pll(1, t[i])))
        deq.pop_front();
      nxt[i] = deq[0].second - t[i] * deq[0].first + (ll)i * t[i] - sumt[i];
    }
    memcpy(f, nxt, sizeof(nxt));
  }
  printf("%lld\n", f[m]);
  cerr << "did not RE" << endl;
  return 0;
}