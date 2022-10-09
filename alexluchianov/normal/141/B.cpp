#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main()
{
  int a, x, y;
  cin >> a >> x >> y;
  int ptr = 0;
  int ystart = 0;
  for(int i = 1; ystart <= y; i++){
    if(i <= 2 || i % 2 == 0){
      ++ptr;
      if(ystart < y && y < ystart + a && -a / 2.0 < x && x < a / 2.0){
        cout << ptr;
        return 0;
      }
    } else {
      ptr += 2;
      if(ystart < y && y < ystart + a && -a < x && x < 0){
        cout << ptr - 1;
        return 0;
      } else if(ystart < y && y < ystart + a && 0 < x && x < a){
        cout << ptr;
        return 0;
      }
    }
    ystart += a;
  }
  cout << -1;
  return 0;
}