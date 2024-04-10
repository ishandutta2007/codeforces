#include <iostream>
#include <string>
#include <math.h>
#include <map>

using namespace std;

string sizes [9] = {string("XXXS"), string("XXS"), string("XS"), string("S"), string("M"), string("L"), string("XL"), string("XXL"), string("XXXL")};

int main () {
  map<string, int> old_sh, new_sh;

  for (int i = 0; i < 9; i++) {
    old_sh[sizes[i]] = 0;
    new_sh[sizes[i]] = 0;
  }

  int shirtc;
  cin >> shirtc;

  for (int i = 0; i < shirtc; i++) {
    string shirt;
    cin >> shirt;

    old_sh[shirt]++;
  }

  for (int i = 0; i < shirtc; i++) {
    string shirt;
    cin >> shirt;

    new_sh[shirt]++;
  }

  int ans = 0;
  for (int i = 0; i < 9; i++) {
    ans += abs(old_sh[sizes[i]] - new_sh[sizes[i]]);
  }

  cout << ans / 2 << endl;
}