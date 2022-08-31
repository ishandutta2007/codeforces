#include <iostream>

using namespace std;

int main () {
  int vertexc, leafc;
  cin >> vertexc >> leafc;

  if ((vertexc - 1) % leafc == 0) {
    cout << 2 * ((vertexc - 1) / leafc) << '\n';
  } else if ((vertexc - 1) % leafc == 1) {
    cout << 2 * ((vertexc - 1) / leafc) + 1 << '\n';
  } else {
    cout << 2 * ((vertexc - 1) / leafc) + 2 << '\n';
  }
  
  for (int i = leafc + 1; i < vertexc; i++) {
    cout << i << " " << i - leafc << '\n';
  }

  for (int i = vertexc - leafc; i < vertexc; i++) {
    cout << i << " " << vertexc << '\n';
  }
}