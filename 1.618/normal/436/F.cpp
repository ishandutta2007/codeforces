/*
start thinking:
BULB:
result of thinking: Lost.

CF436F
d[1...m] (m  1e5), .
d[kB, (k+1)B), 
 (), , 
max.
n*sqrt(n)log.

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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 100005
const int B = 317;
const int blkNum = 316;

// d[i]: p = ip
int n, w, add[325], opt[325];
ll d[101005];
vector<int> as[maxn];
vector<Pll> buc[325];

bool convex(Pll x, Pll y, Pll z) {
  assert(x.first < y.first && y.first < z.first);
  return (y.second - x.second) * (z.first - y.first)
           > (z.second -  y.second) * (y.first - x.first);
}

// x: 
void redo(int x) {
  for (int i = x * B; i < (x + 1) * B; i++)
    d[i] += (ll)add[x] * i;
  add[x] = 0;
  buc[x].clear();
  for (int i = x * B; i < (x + 1) * B; i++) {
    Pll v = {i, d[i]};
    while (buc[x].size() >= 2 && !convex(buc[x].end()[-2], buc[x].end()[-1], v))
      buc[x].pop_back();
    buc[x].push_back(v);
  }
  opt[x] = 0;
}

void update(int x) {
  for (int i = 0; i < x / B; i++)
    add[i]++;
  for (int i = x / B * B; i <= x; i++)
    d[i] += i;
  redo(x / B);

  // cout << x << endl;
  // for (auto i : buc[x / B]) {
  //   cout << i.first << " " << i.second << endl;
  // }
  // system("pause");

}

// (max, argmax)
Pll qmax() {
  Pll res = {-1, -1};
  for (int i = 0; i < blkNum; i++) {
    while (opt[i] < (int)buc[i].size() - 1) {
      auto cur = buc[i][opt[i]], nxt = buc[i][opt[i] + 1];
      if (cur.second + cur.first * add[i] < nxt.second + nxt.first * add[i])
        opt[i]++;
      else
        break;
    }
    auto cur = buc[i][opt[i]];
    chmax(res, {cur.second + cur.first * add[i], cur.first});
  }
  return res;
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &w);
  for (int i = 1; i <= n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    as[b].push_back(a);
  }
  for (int i = 0; i < blkNum; i++) {
    buc[i].push_back({i * B, 0});
    buc[i].push_back({(i + 1) * B - 1, 0});
  }
  int freeUser = n;
  for (int i = 0; i <= 100001; i++) {
    auto ans = qmax();

    // cout << ans.first << " " << ans.second << endl;
    // system("pause");

    printf("%lld %lld\n", ans.first + (ll)i * w * freeUser, ans.second);
    if (!freeUser)
      break;
    freeUser -= as[i].size();
    for (auto a : as[i]) {
      update(a);
    }
  }
  return 0;
}
/*
5 1
0 5
4 0
1 2
4 4
1 0

0 5
7 4
10 4
10 4
12 4
13 4
8 4
*/