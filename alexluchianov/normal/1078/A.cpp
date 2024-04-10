#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long
#define ld long double
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const inf = 1000000000;

ld dist(ld x , ld y , ld x2 , ld y2){
  return sqrt((x - x2) * (x - x2) + (y2 - y) * (y2 - y));
}


int main()
{
  ld a , b , c;
  cin >> a >> b >> c;
  ld x , y , x2 , y2;
  cin >> x >> y >> x2 >> y2;
  ld result = fabs(x - x2) + fabs(y2 - y);

  if(a != 0 && b != 0){
    ld astartx = (-c - b * y) / a;
    ld astarty = (-c - a * x) / b;

    ld bstartx = (-c - b * y2) / a;
    ld bstarty = (-c - a * x2) / b;


    result = MIN(result , fabs(x - astartx) + fabs(y2 - bstarty) + dist(astartx , y , x2 , bstarty));
    result = MIN(result , fabs(y - astarty) + fabs(y2 - bstarty) + dist(x , astarty , x2 , bstarty));
    result = MIN(result , fabs(x - astartx) + fabs(x2 - bstartx) + dist(astartx , y , bstartx , y2));
    result = MIN(result , fabs(y - astarty) + fabs(x2 - bstartx) + dist(x , astarty , bstartx , y2));
  }
  cout << setprecision(8) << fixed << result;

  return 0;
}