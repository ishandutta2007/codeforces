#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int nombre;
  cin >> nombre;

  for(int iLig = 0;nombre != 0;iLig++) {
    if(nombre > 0) {
      cout << iLig << " " << 0 << endl;
      nombre--;
    }
    if(nombre > 0 && iLig % 2 == 1) {
      cout << iLig << " " << 3 << endl;
      nombre--;
    }
  }

  return 0;
}