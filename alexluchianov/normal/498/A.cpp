#include <iostream>
#include <cmath>

using namespace std;
using ld = long double;
struct Point{
  ld x;
  ld y;
};

ld det3(Point a, Point b, Point c){
  ld resultplus = a.x * b.y + a.y * c.x + b.x * c.y;
  ld resultminus = a.x * c.y + a.y * b.x + b.y * c.x;
  return resultplus - resultminus;
}

int main()
{
  int n;
  Point p1, p2;
  cin >> p1.x >> p1.y;
  cin >> p2.x >> p2.y;
  int result = 0;
  cin >> n;
  for(int i = 1;i <= n; i++){
    ld a, b, c;
    cin >> a >> b >> c;
    Point x, y;
    if(0 != b){
      x = {0, -c / b};
      y = {1, -(c + a) / b};
    } else{
      x = {-c / a, 0};
      y = {-c / a, 1};
    }

    if(0 < det3(x, y, p1) && det3(x, y, p2) < 0)
      result++;
    else if(det3(x, y, p1) < 0 && 0 < det3(x, y, p2))
      result++;
  }
  cout << result;
  return 0;
}