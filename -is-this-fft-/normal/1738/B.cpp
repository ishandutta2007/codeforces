#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve () {
  int n, K;
  cin >> n >> K;

  vector<ll> sums (K);
  for (int i = 0; i < K; i++) {
    cin >> sums[i];
  }

  for (int i = K - 1; i > 0; i--) {
    sums[i] -= sums[i - 1];
  }

  for (int i = 2; i < K; i++) {
    if (sums[i] < sums[i - 1]) {
      cout << "No" << '\n';
      return;
    }
  }

  if (K == 1) {
    cout << "YES" << '\n';
    return;
  }
  
  if (n == K) {
    if (sums[1] < sums[0]) {
      cout << "NO" << '\n';
    } else {
      cout << "yES" << '\n';
    }
    
    return;
  }

  // can n - K + 1 numbers <= sums[1] add up to sums[0]?
  if ((ll) (n - K + 1) * sums[1] < sums[0]) {
    cout << "nO" << '\n';
  } else {
    cout << "yes" << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}