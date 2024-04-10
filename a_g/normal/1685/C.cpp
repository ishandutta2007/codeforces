#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    bool pos = 1;
    vector<int> h(2*n+1);
    for (int i = 0; i < 2*n; i++) {
      h[i+1] = h[i] + (s[i] == '(' ? 1 : -1);
    }
    auto it = max_element(h.begin(), h.end());
    int l = 0;
    for (int i = 0; i <= 2*n; i++) {
      if (h[i] < 0) {
        l = i;
        break;
      }
    }
    int r = 2*n;
    for (int i = 2*n; i >= 0; i--) {
      if (h[i] < 0) {
        r = i;
        break;
      }
    }

    if (l == 0) {
      cout << "0\n";
      continue;
    }
    int ml = 0;
    int pl = 0;
    int mr = 0;
    int pr = 2*n;
    for (int i = 0; i < l; i++) {
      if (h[i] > ml) {
        ml = h[i];
        pl = i;
      }
    }
    for (int i = 2*n; i > r; i--) {
      if (h[i] > mr) {
        mr = h[i];
        pr = i;
      }
    }
    if (ml+mr >= *it) {
      cout << "1\n";
      cout << pl+1 << " " << pr << '\n';
      continue;
    }
    cout << "2\n";
    cout << pl+1 << " " << it-h.begin() << '\n';
    cout << it-h.begin()+1 << " " << pr << '\n';
  }
}