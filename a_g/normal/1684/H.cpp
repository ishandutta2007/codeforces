#include <bits/stdc++.h>
using namespace std;

// https://artofproblemsolving.com/community/c6h1472066p8547136
//

// https://codeforces.com/contest/1684/submission/163006774
// Strategy: pick a target sum to attain, and greedily place cuts as late as
// possible to get closer to that target. Why does this work? IDK

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    int c = count(s.begin(), s.end(), '1');
    if (c == 0) {
      cout << "-1\n";
      continue;
    }
    for (int target = 1; ; target <<= 1) {
      if (target >= c) {
        vector<bool> cut(n); // cut[i] = cut after s[i]
        cut[n-1] = 1;
        int deficit = target-c;
        int v = 0;
        for (int i = 0; i < n-1; i++) {
          v += s[i]=='1';
          if (v <= deficit) {
            deficit -= v;
            v *= 2;
          }
          else {
            v = 0;
            cut[i] = 1;
          }
        }
        if (deficit == 0) {
          cout << accumulate(cut.begin(), cut.end(), 0) << '\n';
          int l = 1;
          for (int i = 0; i < n; i++) {
            if (cut[i]) {
              cout << l << " " << i+1 << '\n';
              l = i+2;
            }
          }
          break;
        }
      }
    }
  }
}