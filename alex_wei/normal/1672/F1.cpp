#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
inline int read() {
  int x = 0;
  char s = getchar();
  while(!isdigit(s)) s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return x;
}
constexpr int N = 2e5 + 5;
int n, a[N], cnt[N];
vector<int> buc[N];
void solve() {
  n = read();
  for(int i = 1; i <= n; i++) cnt[i] = 0, buc[i].clear();
  for(int i = 1; i <= n; i++) buc[++cnt[a[i] = read()]].push_back(i);
  for(int i = 1; i <= n; i++) {
    sort(buc[i].begin(), buc[i].end(), [&](int x, int y) {return a[x] < a[y];});
    for(int j = 1; j < buc[i].size(); j++) swap(a[buc[i][j - 1]], a[buc[i][j]]);
  }
  for(int i = 1; i <= n; i++) cout << a[i] << " ";
  cout << "\n";
}
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}