#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

typedef long long ll;

int order [200];

int main () {
  order['f'] = 0;
  order['e'] = 1;
  order['d'] = 2;
  order['a'] = 3;
  order['b'] = 4;
  order['c'] = 5;

  string seat;
  cin >> seat;

  char column = seat.back();
  seat.pop_back();
  ll row = atoll(seat.c_str());
  row--;

  ll step = row / 4;
  ll ans = 0;
  ans += order[column];
  ans += step * 16;
  if (row % 2 != 0) {
    ans += 7;
  }
  ans++;

  cout << ans << endl;
}