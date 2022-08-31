#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 5e5;

ll _ans [2 * MAX_N];
ll& ans (int idx) {
  return _ans[idx + MAX_N];
}

int main () {
  ios::sync_with_stdio(false);

  ll tot = 0;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;

    ans(x - i) += x;
    tot = max(tot, ans(x - i));
  }

  cout << tot << endl;
}