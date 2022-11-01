#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

const ll P = 29;
const int N = 100005;
const int MOD = 1e9 + 9;

string s, t[N];
int n, m, f[N], id[N], nxt[N];
unordered_map <ll, int> h;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> s >> m;
  for (int it = 0; it < m; ++it) {
    cin >> t[it];
    ll cur = 0;
    for (int i = t[it].size() - 1; i >= 0; --i) {
      ll ch = (t[it][i] >= 'a' ? t[it][i] - 'a' : t[it][i] - 'A') + 1;
      cur = (cur * P + ch) % MOD;
    }
    h[cur] = it;
  }
  f[n + 1] = 1;
  for (int i = n; i > 0; --i) {
    ll cur = 0;
    for (int j = i; j <= n; ++j) {
      ll ch = s[j - 1] - 'a' + 1;
      cur = (cur * P + ch) % MOD;
      if (f[j + 1] and h.find(cur) != h.end()) {
        f[i] = 1, id[i] = h[cur], nxt[i] = j + 1;
        break;
      }
    }
  }
  assert(f[1]);
  for (int i = 1; i <= n; i = nxt[i]) {
    cout << t[id[i]] << " ";
  }
  cout << '\n';
  return 0;
}