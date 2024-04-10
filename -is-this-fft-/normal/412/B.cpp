#include <iostream>
#include <algorithm>

const int MAX_COMP = 105;

using namespace std;

int speed [MAX_COMP];

int main () {
  int compc, partc;
  cin >> compc >> partc;

  for (int i = 0; i < compc; i++) {
    cin >> speed[i];
  }

  sort(speed, speed + compc);
  cout << speed[compc - partc] << endl;
}