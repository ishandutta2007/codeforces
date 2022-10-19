#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    b[i] = val-b[i];
    if (i == 0) b[i]++;
  }

  ll ans = 0;
  vector<int> d;
  vector<int> ops(n, 0);
  vector<int> mu(n, 0);
  mu[0] = 1;
  for (int i = 0; i < n; i++) {
    ops[i] += b[i];
    for (int j = 2*i+1; j < n; j += i+1) {
      ops[j] -= ops[i];
      mu[j] -= mu[i];
    }
    if (mu[i] == 0) {
      ans += abs(ops[i]);
    }
    else {
      d.push_back(-mu[i]*ops[i]);
      ans += d.back();
    }
  }

  sort(d.begin(), d.end());
  int k = d.size();
  vector<ll> s(k+1, 0);
  for (int i = 0; i < k; i++) {
    s[i+1] = s[i] + d[i];
  }

  int q;
  cin >> q;
  while (q--) {
    ll x;
    cin >> x;
    int m = lower_bound(d.begin(), d.end(), x)-d.begin();
    cout << ans - 2*s[m] + (2*m-k)*x << '\n';
  }

}