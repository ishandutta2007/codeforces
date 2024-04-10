#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, p;
    cin >> a >> b >> p;
    string s;
    cin >> s;
    int n = s.size();
    int last = n-1;
    int cost = 0;
    char prev = 0;
    for (int i = n-2; i >= 0; i--) {
      if (s[i] != prev) {
        cost += (s[i] == 'A' ? a : b);
        if (cost > p) break;
        prev = s[i];
      }
      last = i;
    }
    cout << last + 1 << endl;
  }
}