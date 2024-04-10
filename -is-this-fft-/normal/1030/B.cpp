#include <iostream>

using namespace std;

int main () {
  int n, d;
  cin >> n >> d;

  int sl = d;
  int sr = n + n - d;
  int dl = -d;
  int dr = d;

  int queryc;
  cin >> queryc;

  //cout << sl << " " << sr << " " << dl << " " << dr << endl;

  for (int i = 0; i < queryc; i++) {
    int x, y;
    cin >> x >> y;

    int s = x + y;
    int d = x - y;

    //cout << s << " " << d << endl;
    if (sl <= s && s <= sr && dl <= d && d <= dr) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}