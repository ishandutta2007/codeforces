#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

ll arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll D = 0;
  for (int i = 0; i < n - 1; i++) {
    D = gcd(D, abs(arr[i + 1] - arr[i]));
  }
  
  for (int i = 0; i < m; i++) {
    ll B;
    cin >> B;

    cout << gcd(arr[0] + B, D) << ' ';
  }
  cout << '\n';
}