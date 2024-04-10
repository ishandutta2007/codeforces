#include <iostream>
#include <algorithm>

const int INF = 2023456789;

using namespace std;

int main () {
  int blackc;
  cin >> blackc;

  int kingx, kingy;
  cin >> kingx >> kingy;

  pair<char, int> lu ('X', INF), 
    u ('x', INF), 
    ru ('x', INF), 
    r ('x', INF), 
    rd ('x', INF), 
    d ('X', INF), 
    ld ('X', INF), 
    l ('X', INF);
  for (int i = 0; i < blackc; i++) {
    char piece;
    int x, y;
    cin >> piece >> x >> y;

    x -= kingx;
    y -= kingy;

    if (y == 0) {
      if (x < 0 && abs(x) < l.second) {
        l = make_pair(piece, abs(x));
      } else if (x > 0 && abs(x) < r.second) {
        r = make_pair(piece, abs(x));
      }
    } else if (x == 0) {
      if (y < 0 && abs(y) < d.second) {
        d = make_pair(piece, abs(y));
      } else if (y > 0 && abs(y) < u.second) {
        u = make_pair(piece, abs(y));
      }
    } else if (x == y) {
      if (x < 0 && abs(x) < ld.second) {
        ld = make_pair(piece, abs(x));
      } else if (x > 0 && abs(x) < ru.second) {
        ru = make_pair(piece, abs(x));
      }
    } else if (x == -y) {
      if (x < 0 && abs(x) < lu.second) {
        lu = make_pair(piece, abs(x));
      } else if (x > 0 && abs(x) < rd.second) {
        rd = make_pair(piece, abs(x));
      }
    }
  }

  cout << ((u.first == 'R') || (u.first == 'Q') ||
           (d.first == 'R') || (d.first == 'Q') ||
           (l.first == 'R') || (l.first == 'Q') ||
           (r.first == 'R') || (r.first == 'Q') ||
           (ld.first == 'B') || (ld.first == 'Q') ||
           (lu.first == 'B') || (lu.first == 'Q') ||
           (rd.first == 'B') || (rd.first == 'Q') ||
           (ru.first == 'B') || (ru.first == 'Q') ? "YES" : "NO") << endl;
}