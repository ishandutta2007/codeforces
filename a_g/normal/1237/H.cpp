#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string a, b;
    cin >> a >> b;
    int n = (int)a.size();
    int c00 = 0, c01 = 0, c11 = 0;
    int bal_a = 0, bal_b = 0;
    for (int i = 0; i < n; i += 2) {
      if (a[i] != a[i+1]) {
        c01++;
        if (a[i] == '0') bal_a++;
        else bal_a--;
      }
      else if (a[i] == '0') c00++;
      else c11++;

      if (b[i] != b[i+1]) {
        c01--;
        if (b[i] == '0') bal_b++;
        else bal_b--;
      }
      else if (b[i] == '0') c00--;
      else c11--;
    }
    if (c00 || c01 || c11) {
      cout << "-1\n";
      continue;
    }

    vector<int> ans;
    auto op = [&] (int k) {
      if (k == 0) return;
      ans.push_back(k);
      reverse(a.begin(), a.begin()+k);
    };

    int end_step = 0;
    if (abs(bal_b) > abs(bal_a)) {
      int d = 0;
      for (int i = 0; i < n; i += 2) {
        if (b[i] != b[i+1]) {
          if (b[i] == '0') d++;
          else d--;
        }
        if (bal_b-2*d == -bal_a) {
          end_step = i+2;
          reverse(b.begin(), b.begin()+i+2);
          break;
        }
      }
      assert(end_step);
    }
    else {
      int d = 0;
      for (int i = 0; i < n; i += 2) {
        if (a[i] != a[i+1]) {
          if (a[i] == '0') d++;
          else d--;
        }
        if (bal_a-2*d == -bal_b) {
          op(i+2);
          break;
        }
      }
    }

    for (int i = 0; i < n; i += 2) {
      // before: a[:i] = b[n-i:]
      for (int j = i; j < n; j += 2) {
        if (a[j] == b[n-i-1] && a[j+1] == b[n-i-2]) {
          op(j);
          op(j+2);
          break;
        }
      }
    }

    if (end_step) ans.push_back(end_step);
    cout << (int)ans.size() << '\n';
    for (int x: ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}