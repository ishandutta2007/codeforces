#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), end_freq(n), freq(n);
    for (int& x: a) {
      cin >> x;
      x--;
      freq[x]++;
    }
    int m = *max_element(freq.begin(), freq.end());
    if (m > (n+1)/2) {
      cout << "-1\n";
      continue;
    }
    int ans = 0;
    end_freq[a[0]]++;
    end_freq[a[n-1]]++;
    for (int i = 1; i < n; i++) {
      if (a[i] == a[i-1]) {
        end_freq[a[i]] += 2;
        ans++;
      }
    }
    m = *max_element(end_freq.begin(), end_freq.end());
    ans += max(0, m-ans-2);
    cout << ans << '\n';
  }
}