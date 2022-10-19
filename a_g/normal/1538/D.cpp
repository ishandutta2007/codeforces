#include <bits/stdc++.h>
using namespace std;

const int N = 4e4;
bool is_prime[N];
vector<int> primes;

int wt(int x) {
  int ans = 0;
  for (int p: primes) {
    if (p*p > x) break;
    while (x%p == 0) {
      ans++;
      x /= p;
    }
  }
  if (x != 1) ans++;
  return ans;
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill(is_prime+2, is_prime+N, 1);
  for (int i = 2; i < N; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = 2*i; j < N; j += i) {
        is_prime[j] = 0;
      }
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int a, b, k;
    cin >> a >> b >> k;
    if (k == 1)  {
      cout << (a != b && (a%b == 0 || b%a == 0) ? "Yes" : "No") << '\n';
      continue;
    }
    cout << (wt(a)+wt(b) >= k ? "Yes" : "No") << '\n';
  }
}