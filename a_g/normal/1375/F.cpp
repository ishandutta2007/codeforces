#include <bits/stdc++.h>
using namespace std;

long long vals[3];
long long s, m, ans;
int k;

void upd() {
  s = accumulate(vals, vals+3, 0LL);
  m = *max_element(vals, vals+3);
  ans = 3*m-s;
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> vals[0] >> vals[1] >> vals[2];
  cout << "First" << endl;

  upd();
  for (int t = 0; t < 2; t++) {
    cout << ans << endl;
    cin >> k;
    if (!k) return 0;

    vals[k-1] += ans;
    upd();
    for (int i = 0; i < 3; i++) {
      if (3*vals[i] == s) {
        cout << m-vals[i] << endl;
        cin >> k;
        return 0;
      }
    }
  }
}