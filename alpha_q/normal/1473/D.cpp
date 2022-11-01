#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

char s[N];
int t, n, m, pfVal[N];
pair <int, int> pfRange[N];
pair <int, int> sfRange[N];

pair <int, int> unite (pair <int, int> one, pair <int, int> two) {
  return make_pair(min(one.first, two.first), max(one.second, two.second));
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d %s", &n, &m, s + 1);
    pfVal[0] = 0, pfRange[0] = make_pair(0, 0);
    for (int i = 1; i <= n; ++i) {
      pfVal[i] = pfVal[i - 1];
      if (s[i] == '+') ++pfVal[i];
      else --pfVal[i];
      pfRange[i] = pfRange[i - 1];
      pfRange[i].first = min(pfRange[i].first, pfVal[i]);
      pfRange[i].second = max(pfRange[i].second, pfVal[i]);
    }
    sfRange[n + 1] = make_pair(0, 0);
    for (int i = n, cur = 0; i >= 1; --i) {
      sfRange[i] = sfRange[i + 1];
      if (s[i] == '+') ++sfRange[i].first, ++sfRange[i].second;
      else --sfRange[i].first, --sfRange[i].second;
      sfRange[i].first = min(0, sfRange[i].first);
      sfRange[i].second = max(0, sfRange[i].second);
    }
    while (m--) {
      int l, r;
      scanf("%d %d", &l, &r);
      int val = pfVal[l - 1];
      auto sf = sfRange[r + 1];
      sf.first += val, sf.second += val;
      auto yo = unite(pfRange[l - 1], sf);
      printf("%d\n", yo.second - yo.first + 1);
    }
  }
  return 0;
}