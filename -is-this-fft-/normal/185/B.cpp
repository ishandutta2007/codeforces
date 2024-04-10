#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef long double ld;

int main () {
  int S, a, b, c;
  cin >> S >> a >> b >> c;

  vector<vector<int>> eq = {{c + a, a, S * a},
                            {b, c + b, S * b}};

  cout << fixed << setprecision(12);
  int D = eq[0][0] * eq[1][1] - eq[0][1] * eq[1][0];
  if (D == 0) {
    // c = 0
    if (a + b == 0) {
      // whatever
      cout << 0 << " " << 0 << " " << 0 << endl;
    } else {
      ld x = (ld) (a * S) / (ld) (a + b);
      ld y = S - x;
      ld z = 0;
      cout << x << " " << y << " " << z << endl;
    }
    return 0;
  }

  int Dx = eq[0][2] * eq[1][1] - eq[0][1] * eq[1][2];
  int Dy = eq[0][0] * eq[1][2] - eq[0][2] * eq[1][0];
  ld x = (ld) Dx / (ld) D;
  ld y = (ld) Dy / (ld) D;
  ld z = S - x - y;
  cout << x << " " << y << " " << z << endl;
}