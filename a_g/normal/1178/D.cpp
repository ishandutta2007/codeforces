#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
bool prime[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill(prime+2, prime+N, 1);
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      for (int j = 2*i; j < N; j += i) {
        prime[j] = 0;
      }
    }
  }

  int n;
  cin >> n;
  int e = n;
  while (!prime[e]) e++;
  cout << e << '\n';
  for (int i = 0; i < n; i++) {
    cout << i+1 << " " << (i+1)%n+1 << '\n';
  }
  for (int i = 0; i < e-n; i++) {
    cout << i+1 << " " << (i+n/2)%n+1 << '\n';
  }
}