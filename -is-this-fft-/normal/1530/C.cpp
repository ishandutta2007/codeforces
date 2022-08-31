#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void solve () {
  int n;
  cin >> n;

  deque<int> you (n), oth (n);
  for (int i = 0; i < n; i++) {
    cin >> you[i];
  }
  sort(you.begin(), you.end(), greater<int>());
  
  for (int i = 0; i < n; i++) {
    cin >> oth[i];
  }
  sort(oth.begin(), oth.end(), greater<int>());

  int cnt = n - n / 4;
  int yous = 0, oths = 0;
  for (int i = 0; i < cnt; i++) {
    yous += you[i];
  }
  for (int i = 0; i < cnt; i++) {
    oths += oth[i];
  }

  if (yous >= oths) {
    cout << 0 << '\n';
    return;
  }

  for (int k = 1; true; k++) {
    you.push_front(100);
    yous += 100;
    yous -= you[cnt];

    oth.push_back(0);

    n++;
    if (n - n / 4 > cnt) {
      yous += you[cnt];
      oths += oth[cnt];
      cnt = n - n / 4;
    }

    if (yous >= oths) {
      cout << k << '\n';
      return;
    }
  }
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