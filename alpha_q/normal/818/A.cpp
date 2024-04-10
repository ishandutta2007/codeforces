#include <bits/stdc++.h> 

using namespace std;

long long n, k;

int main() {
  cin >> n >> k;
  long long x = n / (2LL * (k + 1));
  long long y = k * x;
  long long z = n - x - y;
  cout << x << " " << y << " " << z << endl;
  return 0;
}