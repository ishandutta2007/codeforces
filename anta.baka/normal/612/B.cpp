#include <bits/stdc++.h>

using namespace std;

int main() {
  //freopen("in.txt", "r", stdin);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x - 1] = i;
  }
  int last = a[0];
  long long ans = 0;
  for(int i = 1; i < n; i++) {
    ans += abs(a[i] - last);
    last = a[i];
  }
  cout << ans;
}