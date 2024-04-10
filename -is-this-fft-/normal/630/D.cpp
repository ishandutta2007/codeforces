#include <iostream>

using namespace std;

int main () {
  long long maxdist;
  cin >> maxdist;
  cout << 3 * maxdist * (maxdist + 1) + 1 << endl;
}