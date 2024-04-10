#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<int> pref_max(n);
  pref_max[0] = arr[0];
  for (int i = 1; i < n; i++) {
    pref_max[i] = max(pref_max[i - 1], arr[i]);
  }
  deque<int> d;
  for (int i = 0; i < n; i++) {
    d.push_back(arr[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    int a = d.front();
    d.pop_front();
    int b = d.front();
    d.pop_front();
    d.push_front(max(a, b));
    d.push_back(min(a, b));
  }
  vector<int> arr2;
  for (int el : d) {
    arr2.push_back(el);
  }
  while (q--) {
    int m;
    cin >> m;
    if (m < n) {
      cout << pref_max[m - 1] << " " << arr[m] << endl;
    } else {
      cout << arr2[0] << " " << arr2[(m - 1) % (n - 1) + 1] << endl;
    }
  }
}