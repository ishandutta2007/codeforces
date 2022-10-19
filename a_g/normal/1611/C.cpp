#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (a[0] == n) {
      reverse(a.begin()+1, a.end());
      for (int i: a) cout << i << ' ';
      cout << '\n';
    }
    else if (a[n-1] == n) {
      reverse(a.begin(), a.end()-1);
      for (int i: a) cout << i << ' ';
      cout << '\n';
    }
    else {
      cout << "-1\n";
    }
  }
}