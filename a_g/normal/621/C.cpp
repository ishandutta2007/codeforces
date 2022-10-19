#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
  int n, p;
  cin >> n >> p;
  vector<double> probs(n+1);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    int count = r/p-(l-1)/p;
    probs[i] = (double)(count)/(r-l+1);
  }
  probs[n] = probs[0];
  double ans = 0;
  for (int i = 0; i < n; i++) {
    ans += 2000*(probs[i]+probs[i+1]-probs[i]*probs[i+1]);
  }
  cout << ans << endl;
}