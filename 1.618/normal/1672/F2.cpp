/*
start thinking:
BULB:
result of thinking:

: .

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
int n, a[maxn], b[maxn], cnt[maxn], deg[maxn << 1];
vector<int> adj[maxn << 1];

bool solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    cnt[i] = 0;
  for (int i = 1; i <= n * 2; i++)
    adj[i].clear(), deg[i] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    cnt[a[i]]++;
  }
  int mode = max_element(cnt + 1, cnt + n + 1) - cnt;
  for (int i = 1; i <= n; i++) {
    scanf("%d", b + i);
    if (a[i] != mode)
      adj[i].push_back(a[i] + n), ++deg[a[i] + n];
    if (b[i] != mode)
      adj[b[i] + n].push_back(i), ++deg[i];
  }
  queue<int> que;
  for (int i = 1; i <= 2 * n; i++) {
    if (!deg[i])
      que.push(i);
  }
  while (!que.empty()) {
    int u = que.front(); que.pop();
    for (auto v : adj[u]) {
      deg[v]--;
      if (!deg[v])
        que.push(v);
    }
  }
  return *max_element(deg + 1, deg + 2 * n + 1) == 0;
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    puts(solve() ? "AC" : "WA");
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}