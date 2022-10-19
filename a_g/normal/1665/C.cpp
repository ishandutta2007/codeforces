#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int children[N];
int a[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    children[0] = 1;
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      children[p]++;
    }
    sort(children, children+n+1, greater<int>());
    int z = 0;
    while (children[z]) z++;
    int ans = z;
    vector<int> excesses;
    for (int i = 0; i < z; i++) {
      int s = z-i;
      if (s < children[i]) excesses.push_back(children[i]-s);
    }
    sort(excesses.begin(), excesses.end(), greater<int>());
    int low = -1;
    int high = n;
    while (high-low > 1) {
      int mid = (low+high)/2;
      int added = 0;
      for (int k: excesses) {
        if (k > mid) added += k-mid;
      }
      if (added > mid) low = mid;
      else high = mid;
    }
    ans += high;
    cout << ans << '\n';

    fill(children, children+n+1, 0);
  }
}