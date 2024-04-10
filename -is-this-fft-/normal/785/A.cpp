#include <iostream>
#include <string>

using namespace std;

int main () {
  int length;
  cin >> length;

  int ans = 0;
  for (int i = 0; i < length; i++) {
    string body;
    cin >> body;

    if (body == "Tetrahedron") {
      ans += 4;
    } else if (body == "Cube") {
      ans += 6;
    } else if (body == "Octahedron") {
      ans += 8;
    } else if (body == "Dodecahedron") {
      ans += 12;
    } else if (body == "Icosahedron") {
      ans += 20;
    }
  }
  cout << ans << endl;
}