#include <bits/stdc++.h>

using namespace std;

const int MAGIC = 1000010;

int main() {
  long long n, p;
  cin >> n >> p;
  for (int k = 1; k < MAGIC; ++k) {
    long long rem = n - k * p;
    if (rem < k) continue;
    long long req = __builtin_popcountll(rem);
    if (req > k) continue;
    cout << k << '\n';
    return 0;
  } 
  cout << "-1\n";
  return 0;
}