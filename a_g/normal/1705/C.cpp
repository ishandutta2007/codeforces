#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;
    vector<pair<long long, long long>> z(c);
    for (pair<long long, long long>& p: z) {
      cin >> p.first >> p.second;
    }
    vector<long long> len(c+1);
    len[0] = n;
    for (int i = 0; i < c; i++) {
      len[i+1] = len[i] + z[i].second-z[i].first+1;
    }

    function<char(long long)> query = [&] (long long k) {
      if (k <= n) return s[k-1];
      int j = lower_bound(len.begin(), len.end(), k)-len.begin();
      assert(j > 0);
      return query(k-len[j-1]+z[j-1].first-1);
    };

    while (q--) {
      long long k;
      cin >> k;
      cout << query(k) << '\n';
    }
  }
}