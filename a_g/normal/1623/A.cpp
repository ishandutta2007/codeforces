#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int t1 = (rd >= rb ? rd-rb : 2*n-rb-rd);
    int t2 = (cd >= cb ? cd-cb : 2*m-cb-cd);
    cout << min(t1, t2) << '\n';
  }
}