#include <iostream>

using namespace std;

typedef long long ll;

void solve () {
  ll x;
  cin >> x;

  if (x < 14) {
    cout << "NO" << '\n';
  } else if (x % 14 == 0) {
    cout << "NO" << '\n';
  } else if (x % 14 > 6) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
  }
}

int main (){
  ios::sync_with_stdio(false);

  int testc;
  cin >>testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}