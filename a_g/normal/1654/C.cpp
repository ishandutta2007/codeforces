#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    priority_queue<long long> pq;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long tot = accumulate(a.begin(), a.end(), 0LL);
    pq.push(tot);
    sort(a.begin(), a.end());
    bool win = 1;
    while (pq.size()) {
      long long x = pq.top();
      pq.pop();
      if (x < a.back()) {
        win = 0;
        break;
      }
      if (x == a.back()) {
        a.pop_back();
        continue;
      }
      pq.push(x/2);
      pq.push((x+1)/2);
    }
    cout << (win ? "YES" : "NO") << '\n';
  }
}