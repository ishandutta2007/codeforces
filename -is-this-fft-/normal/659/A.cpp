#include <iostream>

using namespace std;

int main () {
  int entrl, home, walk;
  cin >> entrl >> home >> walk;
  home--;
  home += walk;
  home %= entrl;
  if (home < 0) home += entrl;
  cout << home + 1 << endl;
}