#include <bits/stdc++.h>
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int m;
    cin >> m;
    vector<int> top(m);
    vector<int> bottom(m);
    long long topsum = 0;
    for (int i = 0; i < m; i++) {
      cin >> top[i];
      topsum += top[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> bottom[i];
    }

    topsum -= top[0];
    long long ans = 999999999999;
    long long bottomsum = 0;
    int i = 0;
    while (topsum >= bottomsum) {
      ans = min(ans, max<long long>(topsum, bottomsum));
      bottomsum += bottom[i];
      topsum -= top[i+1];
      i++;
    }
    ans = min(ans, max<long long>(topsum, bottomsum));
    cout << ans << endl;
  }
}