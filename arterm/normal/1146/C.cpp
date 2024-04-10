#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
  //ios_base::sync_with_stdio(false);


  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int ans = 0;

    for (int k = 0; k < 9; ++k) {
      vector<int> a, b;
      for (int i = 0; i < n; ++i)
        if ((i >> k) & 1)
          b.push_back(i);
        else
          a.push_back(i);

      if (!a.empty() && !b.empty()) {
        cout << a.size() << " " << b.size() << " ";
        for (int x : a)
          cout << x + 1 << " ";
        for (int y : b)
          cout << y + 1 << " ";
        cout << endl;

        int res;
        cin >> res;
        if (res == -1) {
          exit(0);
        }

        ans = max(ans, res);
      }
    }

    cout << -1 << " " << ans << endl;
  }

}