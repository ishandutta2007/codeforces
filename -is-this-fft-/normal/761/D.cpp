#include <iostream>
#include <algorithm>

const int MAX_LEN = 100005;

using namespace std;

int a [MAX_LEN], compr [MAX_LEN], b [MAX_LEN], travord [MAX_LEN];

bool cord (int p, int q) {
  return compr[p] > compr[q];
}

int main () {
  int length, lbound, ubound;
  cin >> length >> lbound >> ubound;

  for (int i = 0; i < length; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < length; i++) {
    cin >> compr[i];
  }

  for (int i = 0; i < length; i++) {
    travord[i] = i;
  }

  sort(travord, travord + length, cord);

  int cbound = 2023456789;
  for (int i = 0; i < length; i++) {
    int curc = min(cbound, ubound - a[travord[i]]);
    cbound = curc - 1;
    b[travord[i]] = a[travord[i]] + curc;
  }

  for (int i = 0; i < length; i++) {
    if (b[i] < lbound) {
      cout << -1 << endl;
      return 0;
    }
  }

  for (int i = 0; i < length; i++) {
    cout << b[i] << (i == length - 1 ? '\n' : ' ');
  }
}