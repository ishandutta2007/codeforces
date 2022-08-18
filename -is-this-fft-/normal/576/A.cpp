#include <iostream>
#include <vector>

using namespace std;

const int MAX_P = 1e3 + 5;

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
  
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> ans;
  for (int p : primes) {
    int cur = p;
    while (cur <= n) {
      ans.push_back(cur);
      cur *= p;
    }
  }

  cout << (int) ans.size() << endl;
  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;
}