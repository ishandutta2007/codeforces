#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve () {
  int length;
  cin >> length;

  int rc, pc, sc;
  cin >> rc >> pc >> sc;

  string bob;
  cin >> bob;

  int brc = 0, bpc = 0, bsc = 0;
  for (char c : bob) {
    if (c == 'R') brc++;
    if (c == 'P') bpc++;
    if (c == 'S') bsc++;
  }

  int wins = min(rc, bsc) + min(pc, brc) + min(sc, bpc);
  if (wins < (length + 1) / 2) {
    cout << "NO" << '\n';
    return;
  }

  int wrc = min(rc, bsc);
  int wpc = min(pc, brc);
  int wsc = min(sc, bpc);
  vector<char> leftover;
  for (int i = wrc; i < rc; i++) leftover.push_back('R');
  for (int i = wpc; i < pc; i++) leftover.push_back('P');
  for (int i = wsc; i < sc; i++) leftover.push_back('S');

  cout << "YES" << '\n';
  for (char c : bob) {
    bool ok = false;
    if (c == 'S') {
      if (wrc > 0) {
        wrc--;
        cout << 'R';
        ok = true;
      }
    }

    if (c == 'R') {
      if (wpc > 0) {
        wpc--;
        cout << 'P';
        ok = true;
      }
    }

    if (c == 'P') {
      if (wsc > 0) {
        wsc--;
        cout << 'S';
        ok = true;
      }
    }

    if (!ok) {
      cout << leftover.back();
      leftover.pop_back();
    }
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int i = 0; i < testc; i++) {
    solve();
  }
}