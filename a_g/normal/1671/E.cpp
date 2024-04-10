#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int ans = 1;
  function<string(int, int)> dfs = [&] (int lvl, int v) -> string {
    if (lvl == n-1) {
      return string(1, s[v-1]);
    }
    string a = dfs(lvl+1, 2*v);
    string b = dfs(lvl+1, 2*v+1);
    if (a != b) {
      ans = (2*ans) % MOD;
    }
    if (a < b) {
      return s[v-1]+a+b;
    }
    return s[v-1]+b+a;
  };
  dfs(0, 1);
  cout << ans << '\n';
}