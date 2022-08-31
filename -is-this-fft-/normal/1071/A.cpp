#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll nws (ll x) {
  return x * (x + 1) / 2;
}

const int MAX_N = 1e5 + 5;

int avis [MAX_N];

int main () {
  int a, b;
  cin >> a >> b;

  int k = 0;
  for (int i = 1 << 30; i != 0; i /= 2) {
    if (nws(k + i) <= a + b) {
      k += i;
    }
  }

  vector<int> asol;
  for (int i = k; i >= 1; i--) {
    if (a - i >= 0) {
      asol.push_back(i);
      a -= i;
      avis[i] = 1;
    }
  }

  vector<int> bsol;
  for (int i = 1; i <= k; i++) {
    if (!avis[i]) {
      bsol.push_back(i);
    }
  }

  cout << (int) asol.size() << '\n';
  for (int u : asol) {
    cout << u << " ";
  } cout << '\n';
  cout << (int) bsol.size() << '\n';
  for (int u : bsol) {
    cout << u << " ";
  }
  cout << '\n';
}