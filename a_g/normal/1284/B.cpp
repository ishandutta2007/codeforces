#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int has_ascent = 0;
  vector<int> starts, ends;
  for (int i = 0; i < n; i++) {
    int l, p;
    bool ascent = 0;
    cin >> l >> p;
    int start = p;
    int end = p;
    l--;
    while (l--) {
      cin >> end;
      if (end > p) ascent = 1;
      p = end;
    }
    if (ascent) {
      has_ascent++;
    }
    else {
      starts.push_back(start);
      ends.push_back(end);
    }
  }
  long long ans = 1LL*has_ascent*has_ascent+2LL*has_ascent*(n-has_ascent);
  sort(ends.begin(), ends.end());
  for (int x: starts) {
    ans += lower_bound(ends.begin(), ends.end(), x)-ends.begin();
  }
  cout << ans << '\n';
}