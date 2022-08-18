#include <iostream>

using namespace std;

const int MAX_N = 1e6 + 5;

int val [MAX_N];

int calc (int x) {
  int prod = 1;
  while (x != 0) {
    if (x % 10 != 0) {
      prod *= x % 10;
    }
    x /= 10;
  }

  return val[prod];
}

int cum [10][MAX_N];

int main () {
  for (int i = 1; i < 10; i++) {
    val[i] = i;
  }
  for (int i = 10; i < MAX_N; i++) {
    val[i] = calc(i);
  }

  for (int i = 0; i < MAX_N; i++) {
    cum[val[i]][i]++;
  }

  for (int k = 0; k < 10; k++) {
    for (int i = 1; i < MAX_N; i++) {
      cum[k][i] += cum[k][i - 1];
    }
  }

  ios::sync_with_stdio(false);
  
  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int l, r, k;
    cin >> l >> r >> k;

    cout << cum[k][r] - cum[k][l - 1] << '\n';
  }
}