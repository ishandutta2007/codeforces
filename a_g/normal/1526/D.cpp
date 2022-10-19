#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int conv(char c) {
  if (c == 'A') return 0;
  if (c == 'N') return 1;
  if (c == 'T') return 2;
  if (c == 'O') return 3;
  return 4;
}

vector<vector<int>> perms;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);

  // not recommended
  for (int a = 0; a < 4; a++) {
    for (int b = 0; b < 4; b++) {
      for (int c = 0; c < 4; c++) {
        for (int d = 0; d < 4; d++) {
          if (a == b || a == c || a == d || b == c || b == d || c == d) continue;
          perms.push_back({a, b, c, d});
        }
      }
    }
  }

  int T;
  cin >> T;
  while (T--) {
    string a;
    cin >> a;
    vector<vector<int>> indices(4);
    for (int i = 0; i < a.size(); i++) {
      int c = conv(a[i]);
      indices[c].push_back(i);
    }

    ll best = -1;
    int bestindex;

    for (int i = 0; i < 24; i++) {
      ordered_set<int> o;
      ll inv = 0;
      for (int j: perms[i]) {
        for (int k: indices[j]) {
          inv += o.size() - o.order_of_key(k);
          o.insert(k);
        }
      }
      if (inv > best) {
        best = inv;
        bestindex = i;
      }
    }
    for (int j: perms[bestindex]) {
      cout << string(indices[j].size(), "ANTO"[j]);
    }
    cout << '\n';
  }
}