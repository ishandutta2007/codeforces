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
    vector<ll> ans(n+1, -1);
    vector<int> counts(n+1);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      counts[a]++;
    }

    ll total = 0;
    priority_queue<int> pq;
    for (int i = 0; i <= n; i++) {
      if (i > 0) {
        if (pq.empty()) break;
        int v = pq.top();
        pq.pop();
        total += (i-1-v);
      }

      int c = counts[i];
      ans[i] = c + total;
      for (int j = 0; j < c; j++) pq.push(i);
    }

    for (ll val: ans) cout << val << ' ';
    cout << '\n';
  }
}