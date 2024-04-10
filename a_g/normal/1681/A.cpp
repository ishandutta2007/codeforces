#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    int m;
    cin >> m;
    vector<int> b(m);
    for (int& x: b) cin >> x;
    int A = *max_element(a.begin(), a.end());
    int B = *max_element(b.begin(), b.end());
    cout << (A >= B ?  "Alice" : "Bob") << '\n';
    cout << (B >= A ?  "Bob" : "Alice") << '\n';
  }
}