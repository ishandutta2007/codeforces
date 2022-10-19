#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> primes;

const int maxn = 1e5+5;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  vector<bool> isprime(maxn, 1);
  for (int i = 2; i < maxn; i++) {
    if (isprime[i]) {
      for (int j = 2*i; j < maxn; j+= i) isprime[j] = 0;
    }
  }
  for (int i = 2; i < maxn; i++) {
    if (isprime[i]) primes.push_back(i);
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int p = n;
    for (int q: primes) {
      if (n % q == 0){ 
        p = q;
        break;
      }
    }
    cout << n/p << " " << (n/p)*(p-1) << endl;
  }
}