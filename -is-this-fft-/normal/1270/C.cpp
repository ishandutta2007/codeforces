#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve () {
  ll sum = 0, xsum = 0;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    
    sum += x;
    xsum ^= x;
  }

  cout << 2 << '\n';
  cout << xsum << ' ';
  
  sum += xsum;
  xsum ^= xsum;

  cout << sum << '\n';
  
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}