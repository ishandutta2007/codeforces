/*


Q.E.D.

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
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 300005
int n, m;

int pos[maxn];
bool vis[maxn];

bool check(vector<int> x, vector<int> y) {

  // cout << endl;
  // for (auto i : x) {
  //   cout << i << " ";
  // }
  // cout << endl;
  // for (auto i : y) {
  //   cout << i << " ";
  // }
  // cout << endl;
  // system("pause");

  for (int i = 0; i < n; i++) {
    pos[x[i]] = i;
    vis[i] = false;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i])
      continue;
    ans++;
    for (int j = pos[y[i]]; j != i; j = pos[y[j]])
      vis[j] = true;
    vis[i] = true;
  }
  return n - ans <= m;
}

void solve() {
  scanf("%d%d", &n, &m);
  vector<int> ans, p(n), cnt(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", p.begin() + i);
    ++cnt[(i + 1 - p[i] + n) % n];
  }
  for (int i = 0; i < n; i++) {
    if (cnt[i] >= n - m - m) {

      // cout << i << endl;

      vector<int> std(n);
      for (int j = 1; j <= n; j++)
        std[(j - 1 + i) % n] = j;
      if (check(std, p))
        ans.push_back(i);
    }
  }
  printf("%u ", ans.size());
  for (auto i : ans)
    printf("%d ", i);
  puts("");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
/*
1
4 1
2 3 1 4
*/