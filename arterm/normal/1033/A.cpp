#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

#define by dklfajsdf


int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n;
  int ax, ay, bx, by, cx, cy;

  cin >> n
    >> ax >> ay
    >> bx >> by
    >> cx >> cy
    ;

  if ((ax < bx) == (ax < cx) && (ay < by) == (ay < cy)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

}