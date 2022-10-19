#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> freq(26);
    for (char c: s) freq[c-'a']++;
    int pairs = 0;
    int singles = 0;
    for (int val: freq) {
      pairs += val/2;
      singles += val&1;
    }
    int ans = 2*(pairs/k);
    singles += 2*pairs-k*ans;
    //cout << pairs << " " << singles << '\n';
    if (singles >= k) ans++;
    cout << ans << '\n';
  }
}