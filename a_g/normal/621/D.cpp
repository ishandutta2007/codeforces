#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string ans;
double best = -1e9;
double eps = 1e-7;

void attempt(string u, double v) {
  if (v > best+eps) {
    best = v;
    ans = u;
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  double x, y, z;
  cin >> x >> y >> z;
  if (max({x, y, z}) > 1.0) {
    if (x > 1.0) {
      attempt("x^y^z", z*log(y)+log(log(x)));
      attempt("x^z^y", y*log(z)+log(log(x)));
      attempt("(x^y)^z", log(y)+log(z)+log(log(x)));
    }
    if (y > 1.0) {
      attempt("y^x^z", z*log(x)+log(log(y)));
      attempt("y^z^x", x*log(z)+log(log(y)));
      attempt("(y^x)^z", log(x)+log(z)+log(log(y)));
    }
    if (z > 1.0) {
      attempt("z^x^y", y*log(x)+log(log(z)));
      attempt("z^y^x", x*log(y)+log(log(z)));
      attempt("(z^x)^y", log(x)+log(y)+log(log(z)));
    }
    cout << ans << endl;
    return 0;
  }
  else if (max({x, y, z}) == 1.0) {
    if (x == 1.0) attempt("x^y^z", 0);
    if (y == 1.0) attempt("y^x^z", 0);
    if (z == 1.0) attempt("z^x^y", 0);
    cout << ans << endl;
    return 0;
  }
  else {
    attempt("x^y^z", -z*log(y)-log(-log(x)));
    attempt("x^z^y", -y*log(z)-log(-log(x)));
    attempt("(x^y)^z", -log(y)-log(z)-log(-log(x)));
    attempt("y^x^z", -z*log(x)-log(-log(y)));
    attempt("y^z^x", -x*log(z)-log(-log(y)));
    attempt("(y^x)^z", -log(x)-log(z)-log(-log(y)));
    attempt("z^x^y", -y*log(x)-log(-log(z)));
    attempt("z^y^x", -x*log(y)-log(-log(z)));
    attempt("(z^x)^y", -log(x)-log(y)-log(-log(z)));
    cout << ans << endl;
    return 0;
  }
}