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
  int q;
  cin >> q;
  while (q--) {
    string s, t;
    cin >> s >> t;
    int a = 0, b = 0;
    int n = (int) s.size();
    for (int i = 0; i < n; i++) {
      a |= (1 << (s[i] - 'a'));
      b |= (1 << (t[i] - 'a'));
    }
    if (a & b) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}