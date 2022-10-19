#include <bits/stdc++.h>
using namespace std;

int score(vector<int>& a, int x, bool high) {
  // x is number of additional stages
  int exclude = (x+a.size())/4;
  int s = accumulate(a.begin(), a.end(), 0);
  if (high) {
    return x*100+ s - accumulate(a.begin(), a.begin()+exclude, 0);
  }
  else {
    if (exclude <= x) return s;
    else {
      exclude -= x;
      return s-accumulate(a.begin(), a.begin()+exclude, 0);
    }
  }
}

int solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (score(a, 0, 1) >= score(b, 0, 0)) return 0;
  int low = 0;
  int high = 3*n;
  while (low + 1 < high) {
    int mid = (low+high)/2;
    if (score(a, mid, 1) >= score(b, mid, 0)) high = mid;
    else low = mid;
  }
  return high;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cout << solve() << '\n';
  }
}