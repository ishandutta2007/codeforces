#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<vector<ll>> parts;
vector<ll> cumul;
vector<int> added;

bool dfs(int i, ll s) {
  if (i == k) {
    return (s&(s+1)) == 0;
  }
  ll v = parts[i].back();
  int current_ones = __builtin_popcountll(s&v);
  s -= s&v;
  for (int j = current_ones; j <= current_ones + added[i]; j++) {
    if (!dfs(i+1, s | parts[i][j])) return 0;
  }
  return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  parts.resize(k);
  cumul.push_back(0);
  for (int i = 0; i < k; i++) {
    int q;
    cin >> q;
    ll curr = 0;
    parts[i].push_back(0);
    for (int j = 0; j < q; j++) {
      int x;
      cin >> x;
      parts[i].push_back(parts[i].back() | (1LL<<(x-1)));
    }
    cumul.push_back(cumul.back() | parts[i].back());
    added.push_back(__builtin_popcountll(cumul[i+1]) - __builtin_popcountll(cumul[i]));
  }
  if (n != 1 && cumul.back() != ((1LL<<n) - 1)) {
    cout << "REJECTED\n";
    return 0;
  }

  cout << (dfs(0, 0) ? "ACCEPTED" : "REJECTED") << '\n';
}