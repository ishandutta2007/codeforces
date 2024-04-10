#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+5;
int freq[N];

vector<int> query(int l, int r) {
  cout << "? " << l << " " << r << endl;
  vector<int> ans(r-l+1);
  for (int& x: ans) cin >> x;
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int low = 0;
    int high = n;
    while (high-low > 1) {
      int mid = (low+high)/2;
      for (int i = 1; i <= mid; i++) {
        freq[i]++;
      }
      for (int k: query(1, mid)) {
        freq[k]++;
      }
      int z = 0;
      for (int i = 1; i <= n; i++) {
        if (freq[i] == 2) {
          z++;
        }
        freq[i] = 0;
      }
      if (z&1) high = mid;
      else low = mid;
    }
    cout << "! " << high << endl;
  }
}