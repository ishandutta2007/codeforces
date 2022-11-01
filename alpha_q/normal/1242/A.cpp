#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  vector <long long> vec;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      vec.emplace_back(i);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) vec.emplace_back(n);
  if (vec.size() > 1) cout << "1\n";
  else cout << vec[0] << '\n';
  return 0;
}