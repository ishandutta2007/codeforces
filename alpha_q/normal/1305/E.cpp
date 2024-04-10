#include <bits/stdc++.h>

using namespace std;

// inline int bound (int n) {
//   return (n / 2) * (n - (n / 2) - 1);
// }

const int SHIFT = 11010;
const int BIG = 5e7 + 5;

int n, m;
vector <int> ans;

int main() {
  cin >> n >> m;
  int at = 0, tmp = m;
  while (at < n and at / 2 <= m) {
    m -= at / 2;
    ans.emplace_back(++at);
  }
  if (at == n and m) {
    cout << "-1\n";
    return 0;
  }
  if (m) ans.emplace_back(at + at - 2 * m + 1);
  int cur = BIG;
  while (ans.size() < n) {
    ans.emplace_back(cur);
    cur += SHIFT;
  }
  // int sz = ans.size(), tot = 0;
  // for (int i = 0; i < sz; ++i) {
  //   for (int j = i + 1; j < sz; ++j) {
  //     for (int k = j + 1; k < sz; ++k) {
  //       if (ans[i] + ans[j] == ans[k]) ++tot;
  //     }
  //   }
  // }
  // for (int x : ans) cout << x << " "; cout << endl;
  // assert(tot == tmp);
  for(int x : ans) cout << x << " "; cout << '\n';
  return 0;
}