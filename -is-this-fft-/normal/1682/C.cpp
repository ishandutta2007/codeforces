#include <iostream>
#include <map>

using namespace std;

void solve () {
  int n;
  cin >> n;

  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    cnt[x]++;
  }

  int one = 0, many = 0;
  for (auto pr : cnt) {
    if (pr.second == 1) one++;
    else if (pr.second > 1) many++;
  }

  int tone = (one + 1) / 2;
  
  cout << tone + many << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}