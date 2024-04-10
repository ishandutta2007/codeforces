#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_P = 4e6 + 5;

int sieve [MAX_P];
vector<int> smallp;

int main () {
  for (int i = 2; i < MAX_P; i++) {
    if (!sieve[i]) {
      smallp.push_back(i);
      for (int j = i; j < MAX_P; j += i) {
        sieve[j] = 1;
      }
    }
  }

  ll x;
  cin >> x;

  vector<ll> divs;
  for (int p : smallp) {
    while (x % p == 0) {
      x /= p;
      divs.push_back(p);
    }
  }

  if (x != 1) {
    divs.push_back(x);
  }

  if ((int) divs.size() == 2) {
    cout << 2 << endl;
    return 0;
  }

  if ((int) divs.size() < 2) {
    cout << 1 << endl;
    cout << 0 << endl;
    return 0;
  }

  cout << 1 << endl;
  cout << divs[0] * divs[1] << endl;
}