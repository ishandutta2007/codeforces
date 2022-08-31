#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 1e3 + 5;

typedef long long ll;

ll sq (ll x) {
  return x * x;
}

ll A [MAX_N];
ll B [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, k1, k2;
  cin >> n >> k1 >> k2;

  int K = k1 + k2;

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }

  set<pair<ll, int>> diffs;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    diffs.insert(make_pair(abs(A[i] - B[i]), i));
    ans += sq(A[i] - B[i]);
  }

  for (int k = 0; k < K; k++) {
    auto big = *diffs.rbegin();
    ll val = big.first;
    int idx = big.second;
    diffs.erase(big);
    ans -= sq(val);
    if (val == 0) {
      val++;
    } else {
      val--;
    }
    ans += sq(val);
    diffs.insert(make_pair(val, idx));
  }

  cout << ans << endl;
}