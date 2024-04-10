#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve () {
  int cardc;
  cin >> cardc;

  vector<string> cards (cardc);
  for (int i = 0; i < cardc; i++) {
    cin >> cards[i];
  }

  int diff = 0;
  for (int i = 1; i < cardc; i++) {
    bool ok = true;
    for (int j = 0; j < cardc; j++) {
      if (i != j && cards[j] == cards[i]) {
        ok = false;
      }
    }

    if (!ok) {
      diff++;
      string ans;
      for (int k = 0; k < 4; k++) {
        for (int l = '0'; l <= '9'; l++) {
          string nu = cards[i];
          nu[k] = l;

          bool nok = true;
          for (int j = 0; j < cardc; j++) {
            if (i != j && cards[j] == nu) {
              nok = false;
            }
          }

          if (nok) {
            ans = nu;
          }
        }
      }
      cards[i] = ans;
    }
  }

  cout << diff << '\n';
  for (string str : cards) {
    cout << str << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int i = 0; i < testc; i++) {
    solve();
  }
}