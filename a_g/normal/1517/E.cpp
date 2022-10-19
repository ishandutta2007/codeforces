#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> pref(n+1);
    vector<vector<long long>> pref_p(2, vector<long long>(n+1));
    for (int& x: a) cin >> x;

    for (int i = 0; i < n; i++) {
      pref[i+1] = pref[i] + a[i];
      for (int j = 0; j < 2; j++) {
        pref_p[j][i+1] = pref_p[j][i];
      }
      pref_p[i&1][i+1] += a[i];
    }
    long long tot = accumulate(a.begin(), a.end(), 0LL);
    long long target = tot/2+1;
    long long ans = 0;

    // case 1: the Ps form a prefix
    for (int i = n; i >= 0; i--) {
      if (pref[i] >= target) ans++;
      else break;
    }

    // two variables for other case: whether the P block starts at n or n-1, and
    // whether position 1 is taken
    for (int z: {n, n-1}) {
      for (bool left: {0, 1}) {
        for (int j = z; j >= 2; j--) {
          // j is the position where the block ends
          if (left && j <= 2) continue;
          long long cur = pref[z]-pref[j-1] + (left ? a[0] : 0);
          // now we have the alternating section, which takes positions j-2,
          // j-4, ... up to 2 (if not left) or 3 (if left). How many do we need
          // to take?
          
          // Binary search works (linear time possible with two pointers)
          int leftmost = (left ? 3 : 2);
          if (leftmost%2 != j%2) leftmost++;
          int high = j;
          int low = leftmost;
          auto query = [&] (int x) {
            return cur+ pref_p[1-j&1][j-1]-pref_p[1-j&1][x-1];
          };
          
          if (query(leftmost) < target) continue;
          while (high-low > 1) {
            int mid = (low+high)/2;
            if (query(mid) >= target) low = mid;
            else high = mid;
          }

          int best = (cur >= target ? j : low);
          ans += (best-leftmost)/2+1;
        }
      }
    }

    cout << ans%MOD << '\n';

  }
}