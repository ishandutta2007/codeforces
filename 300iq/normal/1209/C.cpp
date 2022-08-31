#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string d;
    cin >> d;
    for (auto &c : d) {
      c -= '0';
    }
    auto god = [&] (string s) {
      for (int i = 1; i < (int) s.size(); i++) {
        if (s[i] < s[i - 1]) {
          return false;
        }
      }
      return true;
    };
    bool good = false;
    for (int split = 0; split <= 9; split++) {
      string str = "";
      for (int i = 0; i < n; i++) {
        if (d[i] < split) {
          str += '0';
        } else if (d[i] == split) {
          str += '1';
        } else {
          str += '2';
        }
      }
      int last = -1;
      for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
          last = i;
        }
      }
      vector <int> col(n);
      for (int i = 0; i < n; i++) {
        if (str[i] == '1') {
          if (i < last) {
            col[i] = 1;
          } else {
            col[i] = 0;
          }
        } else {
          if (str[i] == '0') col[i] = 0;
          else col[i] = 1;
        }
      }
      string a = "", b = "";
      for (int i = 0; i < n; i++) {
        if (!col[i]) a += d[i];
        else b += d[i];
      }
      if (god(a) && god(b)) {
        for (int i= 0; i < n; i++) {
          cout << col[i] + 1;
        }
        cout << '\n';
        good = true;
        break;
      }
    }
    if (!good) {
      cout << '-' << '\n';
      continue;
    }
  }
}