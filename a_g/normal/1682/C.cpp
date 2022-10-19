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
    sort(a.begin(), a.end());
    map<int, int> freq;
    for (int x: a) freq[x]++;
    int s = freq.size();
    int ones = 0;
    for (const pair<int, int>& p: freq) {
      if (p.second == 1) {
        ones++;
      }
    }

    int ans = s;
    if (ones) {
      ans = 1+(2*s-ones-1)/2;
    }
    cout << ans << '\n';

  }
}