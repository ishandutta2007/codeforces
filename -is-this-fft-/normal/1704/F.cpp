#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 5e5 + 5;
const int MAX_G = 10;

int grundy [MAX_N];

void solve () {
  int n;
  cin >> n;

  string s;
  cin >> s;
  
  int ca = 0, cb = 0, cur = 0, gru = 0;
  char last = 'X';
  for (char c : s) {
    if (c == 'R') ca++;
    if (c == 'B') cb++;
    if (c == last) {
      gru ^= grundy[cur];
      cur = 0;
    }
    cur++;
    last = c;
  }
  gru ^= grundy[cur];

  if (ca > cb) {
    cout << "Alice" << '\n';
  } else if (ca < cb) {
    cout << "Bob" << '\n';
  } else {
    cout << (gru == 0 ? "Bob" : "Alice") << '\n';
  }
}

int main () {
  grundy[0] = 0;
  grundy[1] = 0;
  for (int i = 2; i < MAX_N; i++) {
    if (i > 1000) {
      grundy[i] = grundy[i - 34];
      continue;
    }
    vector<int> unseen (MAX_G, 1);
    for (int j = 0; j <= i - j - 2; j++) {
      int x = grundy[j] ^ grundy[i - j - 2];
      if (x < MAX_G) 
        unseen[x] = 0;
    }

    grundy[i] = -1;
    for (int j = 0; j < MAX_G; j++) {
      if (unseen[j]) {
        grundy[i] = j;
        break;
      }
    }
  }

  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}