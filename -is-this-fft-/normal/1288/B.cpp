#include <iostream>

using namespace std;

typedef long long ll;

void solve () {
  ll A, B;
  cin >> A >> B;

  ll curk = 10;
  ll bc = 0;
  while (curk - 1 <= B) {
    bc++;
    curk *= 10;
  }

  cout << A * bc << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int t = 0; t < testc; t++) {
    solve();
  }
}