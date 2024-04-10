#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_LG = 60;

int lvl (ll val) {
  return 63 - __builtin_clzll(val);
}

ll shift [MAX_LG];

void shiftby (ll X, ll K) {
  int h = lvl(X);
  K %= 1LL << h;
  if (K < 0) K += 1LL << h;
  shift[h] += K;
  shift[h] %= 1LL << h;
}

void shiftdn (ll X, ll K) {
  int h = lvl(X);
  K %= 1LL << h;
  if (K < 0) K += 1LL << h;

  for (int i = h; i < MAX_LG; i++) {
    shift[i] += K;
    shift[i] %= 1LL << i;
    K *= 2;
  }
}

ll getpos (ll X) {
  int h = lvl(X);
  X -= 1LL << h;
  X += shift[h];
  X %= 1LL << h;
  X += 1LL << h;
  return X;
}

ll getval (ll X) {
  int h = lvl(X);
  X -= 1LL << h;
  X -= shift[h];
  X %= 1LL << h;
  if (X < 0) {
    X += 1LL << h;
  }
  X += 1LL << h;
  return X;
}

void query (ll X) {
  cout << X << " ";
  if (X == 1) {
    cout << '\n';
    return;
  }

  query(getval(getpos(X) / 2));
}

int main () {
  ios::sync_with_stdio(false);

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int op;
    cin >> op;

    if (op == 1) {
      ll X, K;
      cin >> X >> K;

      shiftby(X, K);
    } else if (op == 2) {
      ll X, K;
      cin >> X >> K;

      shiftdn(X, K);
    } else {
      ll X;
      cin >> X;

      query(X);
    }
  }
}