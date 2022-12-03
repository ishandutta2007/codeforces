/*
start thinking:
BULB:
result of thinking:

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
template <class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template <class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
int n, a[maxn], b[maxn];
vector<int> pos[maxn];

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    pos[i].clear();
  set<int> alive;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    pos[a[i]].push_back(i);
    alive.insert(a[i]);
  }
  while (alive.size()) {
    vector<int> foo, bar;
    for (auto i : alive) {
      foo.push_back(pos[i].back());
      pos[i].pop_back();
      if (pos[i].empty())
        bar.push_back(i);
    }
    for (int i = 0; i + 1 < (int)foo.size(); i++)
      b[foo[i]] = a[foo[i + 1]];
    b[foo.back()] = a[foo[0]];
    for (auto i : bar) {
      alive.erase(i);
    }
  }
  for (int i = 1; i <= n; i++)
    printf("%d%c", b[i], " \n"[i == n]);
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}