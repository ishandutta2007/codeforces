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
    vector<int> s0(n+1), s1(n+1);
    vector<int> indices;
    for (int i = 0; i < n; i++) {
      s0[i+1] = s0[i] + (a[i] == 0);
      s1[i+1] = s1[i] + (a[i] == 1);
      if (a[i] == 1) indices.push_back(i);
    }
    int k = (int)indices.size();
    int low = -1;
    int high = k;
    while (high-low > 1) {
      int mid = (low+high)/2;
      int x = 0;
      if (mid < k) x = s0[n]-s0[indices[mid]];
      if (x > mid) low = mid;
      else high = mid;
    }
    cout << high << '\n';
  }
}