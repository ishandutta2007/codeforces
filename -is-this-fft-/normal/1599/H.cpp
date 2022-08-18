#include <iostream>

using namespace std;

const int N = 1'000'000'000;
const int B = 29;

int ask (int x, int y) {
  cout << "? " << 1 + x << " " << 1 + y << endl;

  int resp;
  cin >> resp;

  if (resp == -1) {
    exit(0);
  }

  return resp;
}

void report (int x1, int y1, int x2, int y2) {
  cout << "! " << 1 + x1 << " " << 1 + y1 << " " << 1 + x2 << " " << 1 + y2 << endl;
  exit(0);
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int cdist = ask(0, 0);

  int x1 = 0;
  for (int k = 1 << B; k != 0; k /= 2) {
    if (x1 + k < N && ask(x1 + k, 0) + x1 + k == cdist) {
      x1 += k;
    }
  }

  int y1 = ask(x1, 0);
  int y2 = N - 1 - ask(x1, N - 1);
  int x2 = N - 1 - ask(N - 1, y1);
  report(x1, y1, x2, y2);
}