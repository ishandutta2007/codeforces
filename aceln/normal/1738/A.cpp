#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v0, v1, a(n), b(n);
    for (int &i : a)
      cin >> i;
    for (int &i : b)
      cin >> i;

    long long ans;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0)
        v0.push_back(b[i]);
      else
        v1.push_back(b[i]);
    }
    int n0 = v0.size(), n1 = v1.size();
    int len = min(n0, n1);

    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());
    reverse(v0.begin(), v0.end());
    reverse(v1.begin(), v1.end());
    if (n0 == n1) {
      long long sum = 0;
      for (int i : v0)
        sum += i;
      for (int i : v1)
        sum += i;
      cout << sum * 2 - min(v0[n0 - 1], v1[n1 - 1]) << '\n';
    } else {
      long long sum = 0;
      for (int i : v0)
        sum += i;
      for (int i : v1)
        sum += i;
      for (int i = 0; i < len; i++)
        sum += v0[i], sum += v1[i];
      cout << sum << '\n';
    }
  }
}