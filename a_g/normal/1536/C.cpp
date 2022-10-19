#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0;
    int b = 0;
    map<pair<int, int>, int> counts;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'D') a++;
      else b++;
      int g = __gcd(a, b);
      pair<int, int> r = make_pair(a/g, b/g);
      counts[r]++;
      ans[i] = counts[r];
    }
    for (int v: ans) cout << v << " ";
    cout << endl;
  }
}