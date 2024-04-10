#include <iostream>

using namespace std;

int const nmax = 1000000;


int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  for(int x = 0; x <= nmax; x++){
    int y = b - x;
    int z = a - x;
    if(x + z == a && x + y == b && y + z == c){
      if(0 <= x && 0 <= y && 0 <= z){
        cout << x << " " << y << " " << z << '\n';
        return 0;
      }
    }
  }
  cout << "Impossible";
  return 0;
}