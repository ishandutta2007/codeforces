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
    long long tot = accumulate(a.begin(), a.end(), 0LL);
    if ((2*tot)%n != 0) {
      cout << "0\n";
      continue;
    }
    int z = (2*tot)/n;
    map<int, int> freq;
    for (int x: a) freq[x]++;
    long long ans = 0;
    for (const pair<int, int>& p: freq) {
      if (2*p.first < z) {
        ans += 1LL * p.second * freq[z-p.first];
      }
    }
    if (z%2 == 0) {
      ans += 1LL * freq[z/2] * (freq[z/2]-1)/2;
    }
    cout << ans << '\n';

  }
}