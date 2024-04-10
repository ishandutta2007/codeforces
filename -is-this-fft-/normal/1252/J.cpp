#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_P = 1e6 + 5;

int sieve [MAX_P];

int main () {
  vector<int> primes;
  for (int i = 2; i < MAX_P; i++) {
    if (!sieve[i]) {
      primes.push_back(i);
      for (int j = i; j < MAX_P; j += i) {
        sieve[j] = 1;
      }
    }
  }

  ll length;
  cin >> length;

  if (length == 1) {
    cout << 1 << endl;
    return 0;
  }

  vector<ll> divs;
  for (int p : primes) {
    if (length % p == 0) {
      divs.push_back(p);
      while (length % p == 0) {
        length /= p;
      }
    }
  }
  if (length != 1) {
    divs.push_back(length);
  }

  if ((int) divs.size() == 1) {
    cout << divs[0] << endl;
  } else {
    cout << 1 << endl;
  }
}