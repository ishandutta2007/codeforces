/*
start thinking:
BULB:
result of thinking: Lost

Hint 1, 2
sqrt(n)
!

start coding: 19:20
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

#define maxn 200005
int n, h[maxn], ans[maxn];
vector<int> adj[maxn];
vector<int> plat[maxn];

void calc(int ch) {

  // cout << ch << endl;

  // f[u]: uh=ch
  static int f[maxn];
  memset(f, 0x3f, sizeof(f));
  queue<int> que;
  for (auto i : plat[ch]) {
    f[i] = 0;
    que.push(i);

    // cout << i << " ";
  }

  // cout << endl;
  // system("pause");

  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (auto v : adj[u]) {
      if (h[v] == h[u]) {
        if (chmin(f[v], f[u] + 1))
          que.push(v);
      } else if (h[v] > h[u]) {
        if (chmin(f[v], max(0, f[u] - 1)))
          que.push(v);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!f[i])
      chmin(ans[i], ch);
  }
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  memset(h, 0x3f, sizeof(h));
  queue<int> que;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (x == 1) {
      h[i] = 0;
      que.push(i);
    }
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (auto v : adj[u]) {
      if (chmin(h[v], h[u] + 1))
        que.push(v);
    }
  }
  for (int i = 1; i <= n; i++) {
    bool ok = false;
    for (auto v : adj[i]) {
      if (h[v] == h[i])
        ok = true;
    }
    if (ok)
      plat[h[i]].push_back(i);
  }
  memset(ans, 0x3f, sizeof(ans));
  for (int i = 0; i < n; i++) {
    if (plat[i].size())
      calc(i);
  }
  for (int i = 1; i <= n; i++)
    printf("%d%c", ans[i] == inf ? h[i] : 2 * h[i] - ans[i], " \n"[i == n]);
  return 0;
}