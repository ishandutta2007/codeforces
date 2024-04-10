#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int c[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  vector<int> smallprimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
  for (int i = 0; i < (int)smallprimes.size(); i++) {
    int p = smallprimes[i];
    for (int j = 2*p; j < N; j += p) {
      c[j] = i+1;
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      ans[i] = c[a];
    }
    vector<int> b = ans;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end())-b.begin());
    for (int& x: ans) {
      x = lower_bound(b.begin(), b.end(), x)-b.begin()+1;
    }
    cout << b.size() << '\n';
    for (int x: ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}