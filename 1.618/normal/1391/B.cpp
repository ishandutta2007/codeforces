#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <string>
#define maxn 105
using namespace std;
typedef long long ll;
typedef long double ldouble;

string s[maxn];
int n, m;
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  int ans = 0;
  ans += count(s[n - 1].begin(), s[n - 1].end() - 1, 'D');
  for (int i = 0; i < n - 1; i++) ans += (s[i].back() == 'R');
  cout << ans << endl; 
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}