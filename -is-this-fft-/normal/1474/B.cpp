#include <iostream>
#include <set>

using namespace std;

const int MAX_P = 3e4 + 5;

set<int> primes;
int sieve [MAX_P];

void solve () {
  int D;
  cin >> D;

  int p = *primes.lower_bound(D + 1);
  int q = *primes.lower_bound(D + p);
  cout << p * q << '\n';
}

int main () {
  for (int i = 2; i < MAX_P; i++) {
    if (!sieve[i]) {
      primes.insert(i);
      for (int j = i; j < MAX_P; j += i) {
        sieve[j] = 1;
      }
    }
  }
  
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}