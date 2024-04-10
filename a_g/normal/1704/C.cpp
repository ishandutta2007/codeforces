#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int& x: a) cin >> x;
    sort(a.begin(), a.end());
    vector<int> segs;
    for (int i = 0; i < m-1; i++) {
      segs.push_back(a[i+1]-a[i]-1);
    }
    if (m == 1) segs.push_back(n-1);
    else segs.push_back(a[0]+n-a[m-1]-1);
    sort(segs.begin(), segs.end(), greater<int>());
    int saved = 0;
    for (int i = 0; i < m; i++) {
      segs[i] -= 4*i;
      if (segs[i] <= 0) break;
      if (segs[i] == 1) {
        saved++;
        break;
      }
      saved += segs[i]-1;
    }
    cout << n-saved << '\n';
  }
}