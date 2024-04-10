#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> best(10, -1);
    for (int i = 0; i < n; i++) {
      int b, d;
      cin >> b >> d;
      best[d-1] = max(best[d-1], b);
    }
    if (*min_element(best.begin(), best.end()) == -1) {
      cout << "MOREPROBLEMS\n";
    }
    else {
      cout << accumulate(best.begin(), best.end(), 0) << '\n';
    }
  }
}