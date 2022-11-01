#include <bits/stdc++.h> 

using namespace std;

int n, a, b, c;
long long sum;

int main (int argc, char const *argv[]) {
  cin >> a >> b >> c >> n;
  for (int i = 0; i < n; ++i) {
    long long x; 
    cin >> x;
    if (x > b and x < c) {
      ++sum;
    }
  }
  cout << sum << '\n';
  return 0;
}