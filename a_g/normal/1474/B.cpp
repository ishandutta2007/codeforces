#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
bool is_prime[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = 2; i < N; i++) is_prime[i] = 1;
  for (int i = 2; i < N; i++) {
    if (is_prime[i]) {
      for (int j = 2*i; j < N; j += i) is_prime[j] = 0;
    }
  }

  int T;
  cin >> T;
  while (T--) {
    int d;
    cin >> d;
    int p;
    for (int i = d+1; i < N; i++) {
      if (is_prime[i]) {
        p = i;
        break;
      }
    }
    int q;
    for (int j = p+d; j < N; j++) {
      if (is_prime[j]) {
        q = j;
        break;
      }
    }
    cout << 1LL * p * q << '\n';
  }
}