#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 107;

string s;
int n = 27;
string ans[2];

void read() {
  cin >> s;
  
  for (int i = 0; i < 2; ++i)
    ans[i].resize(13);

}

void nxt(int &curt, int &curx) {
  if (curt == 0) {
    if (curx < 12) {
      ++curx;
    } else {
      curt = 1;
    }
  } else {
    if (curx > 0) {
      --curx;
    } else {
      curt = 0;
    }
  }
}

void kill() {
  for (int i = 0; i + 1 < n; ++i)
    if (s[i] == s[(i + 1) % n]) {
      cout << "Impossible\n";
      exit(0);
    }

  for (int l = 0; l < n; ++l)
    for (int r = l + 1; r < n; ++r)
      if (s[l] == s[r]) {
        int d = (r - l) - 1;
        assert(d >= 1);

        int curt = 0, curx = 12 - (d / 2);
        int ptr = l;

        for (int i = 0; i < 26; ++i) {
          if (ptr == r)
            ptr = (ptr + 1) % n;

          ans[curt][curx] = s[ptr];

          nxt(curt, curx);

          ptr = (ptr + 1) % n;
        }

        cout << ans[0] << endl;
        cout << ans[1] << endl;

        exit(0);
      }

  assert(false);
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}