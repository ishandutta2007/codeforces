#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
  li n, m;
  cin >> n >> m;

  vector<li> moments;
  for (li i = 0; i < n; ++i) {
    li moment = 0;
    for (li j = 0; j < m; ++j) {
      li x;
      cin >> x;
      moment += x * (li)j;
    }
    moments.push_back(moment);
  }

  li k = max_element(all(moments)) - moments.begin();
  li any = (k + 1) % moments.size();
  for (li i = 0; i < n; ++i) {
    if (i != k) {
      assert(moments[i] == moments[any]);
    }
  }

  li d = moments[k] - moments[any];
  cout << k + 1 << " " << d << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#if 1
  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }
#endif

  //solve(false);

  return 0;
}