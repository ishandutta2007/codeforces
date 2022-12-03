/*
start thinking:
BULB:
result of thinking:

 gcd,  v_p , ,  v_p .
 0 . (1, 1), (2, 2) .
, v_p(target) = v_p(a_i)  + ,  a_i 
 / , .
 3 * 5 * 7 * 11 * 13 * 17 * 19 > 1e6, \omega(target) <= 7.
v_{target }  2  a_i ,  while ( target
 a_i )  a_i  2 .
 <= 14  a_i,  target .
?  v_p(target) = min v_p(a_i)  min-max ,
, v_p(target) = min + min2  min-max ,  81950 ,
 630812.

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 100005
const int A = 1000000;
bool notp[A + 5];

void sieve() {
  notp[1] = true;
  for (int i = 2; i <= A; i++) {
    if (!notp[i]) {
      for (ll j = (ll)i * i; j <= A; j += i)
        notp[j] = true;
    }
  }
}

vector<P> lis[A + 5]; // (exponential, id)
bool vis[A + 5], app[maxn], cho[maxn];

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  sieve();
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    for (int j = 2; j * j <= a; j++) {
      if (a % j == 0) {
        int cnt = 0;
        while (a % j == 0) {
          a /= j;
          cnt++;
        }
        lis[j].push_back({cnt, i});
      }
    }
    if (a > 1) {
      lis[a].push_back({1, i});
    }
  }
  for (int i = 1; i <= A; i++) {
    if (notp[i])
      continue;
    if ((int)lis[i].size() == n) {
      sort(lis[i].begin(), lis[i].end());
      cho[lis[i][0].second] = true;
      cho[lis[i][1].second] = true;
      vis[i] = true;
    } else if ((int)lis[i].size() == n - 1) {
      memset(app, 0, sizeof(app));
      for (auto j : lis[i])
        app[j.second] = true;
      for (int j = 1; j <= n; j++) {
        if (!app[j])
          cho[j] = true;
      }
      cho[min_element(lis[i].begin(), lis[i].end())->second] = true;
      vis[i] = true;
    }
  }
  while (true) {
    bool ok = true;
    int cruNum = count(cho + 1, cho + n + 1, true);
    for (int i = 1; i <= A; i++) {
      if (notp[i] || vis[i])
        continue;
      int foo = 0;
      for (auto j : lis[i])
        foo += cho[j.second];
      if (foo == cruNum) {
        memset(app, 0, sizeof(app));
        for (auto j : lis[i])
          app[j.second] = true;
        for (int j = 1; j <= n; j++) {
          if (!app[j]) {
            cho[j] = true;
            cruNum++;
            if (foo < cruNum - 1)
              break;
          }
        }
        ok = false;
        vis[i] = true;
        break;
      } else if (foo == cruNum - 1) {
        memset(app, 0, sizeof(app));
        for (auto j : lis[i])
          app[j.second] = true;
        for (int j = 1; j <= n; j++) {
          if (!app[j] && !cho[j]) {
            cho[j] = true;
            break;
          }
        }
        ok = false;
        vis[i] = true;
        break;
      }
    }
    if (ok)
      break;
  }
  vector<int> cru;
  for (int i = 1; i <= n; i++) {
    if (cho[i])
      cru.push_back(i);
  }
  vector<P> ans;
  for (int i = 1; i < (1 << cru.size()); i++) {
    int coe = __builtin_popcount(i);
    if (coe & 1)
      coe = 2 - coe;
    else
      coe = coe - 2;
    for (int j = 1; j <= abs(coe); j++) {
      ans.push_back({coe < 0, i});
    }
  }
  printf("%d\n", int(ans.size()));
  for (auto i : ans) {
    printf("%d %d ", i.first, __builtin_popcount(i.second));
    for (int j = 0; j < (int)cru.size(); j++) {
      if (i.second >> j & 1)
        printf("%d ", cru[j]);
    }
    puts("");
  }
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}