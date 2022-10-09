#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define MAX(a , b) (((a) < (b)) ? (b) : (a))
#define MIN(a , b) (((a) < (b)) ? (a) : (b))

struct Point{
  int x;
  int y;
  bool operator == (Point const &a) const{
    return (x == a.x) && (y == a.y);
  }
};

Point v[10];
Point v2[10];

/*
a.x a.y 1 a.x a.y 1
b.x b.y 1 b.x b.y 1
c.x c.y 1 c.x c.y 1
*/

int det3(Point a , Point b , Point c){
  int splus = (a.x * b.y) + (a.y * c.x) + (b.x * c.y);
  int sminus = (a.x * c.y) + (a.y * b.x) + (b.y * c.x);
  return splus - sminus;
}
bool lineintersect(Point a , Point b , Point c , Point d){
  if(0 < det3(a , b , c) && 0 < det3(a , b , d))
    return 0;
  else if(det3(a , b , c) < 0 && det3(a , b , d) < 0)
    return 0;
  else if(0 < det3(c , d , a) && 0 < det3(c , d , b))
    return 0;
  else if(det3(c , d , a) < 0&& det3(c , d , b) < 0)
    return 0;
  return 1;
}
bool pointinside2(Point a , Point b , Point c , Point d , Point p){
  int x = MIN(MIN(a.x , b.x) ,MIN(c.x , d.x));
  int x2 = MAX(MAX(a.x , b.x) ,MAX(c.x , d.x));
  int y = MIN(MIN(a.y , b.y), MIN(c.y , d.y));
  int y2 = MAX(MAX(a.y , b.y), MAX(c.y , d.y));
  return (x <= p.x && p.x <= x2) && (y <= p.y && p.y <= y2);
}

bool pointonline(Point a , Point b , Point p){
  return det3(a , b , p) == 0 && pointinside2(a , b , a , b , p) == 1;
}
bool pointinside(Point a , Point b , Point c , Point d , Point p){
  if(pointonline(a , b , p) == 1)
    return 1;
  else if(pointonline(b , c , p) == 1)
    return 1;
  else if(pointonline(c , d , p) == 1)
    return 1;
  else if(pointonline(d , a , p) == 1)
    return 1;

  Point p2 = {-10000 + rand() % 1000, -10000 + rand() % 1000};
  int sum = 0;
  sum += lineintersect(p , p2 , a , b);
  sum += lineintersect(p , p2 , b , c);
  sum += lineintersect(p , p2 , c , d);
  sum += lineintersect(p , p2 , d , a);

  if(0 == det3(p , p2 , a))
    return pointinside(a , b ,c , d , p);
  else if(0 == det3(p , p2 , b))
    return pointinside(a , b ,c , d , p);
  else if(0 == det3(p , p2 , c))
    return pointinside(a , b ,c , d , p);
  else if(0 == det3(p , p2 , d))
    return pointinside(a , b ,c , d , p);
  else
    return (sum % 2 == 1);
}
int main()
{
  srand(time(0));
  cin >> v[0].x >> v[0].y >> v[1].x >> v[1].y >> v[2].x >> v[2].y >> v[3].x >> v[3].y;
  cin >> v2[0].x >> v2[0].y >> v2[1].x >> v2[1].y >> v2[2].x >> v2[2].y >> v2[3].x >> v2[3].y;
  bool ok = 0;
  for(int i = -100 ; i <= 100 ;i++){
    for(int j = -100 ; j <= 100 ;j++){
      if(pointinside2(v[0] , v[1] , v[2] , v[3] , {i , j}) == 1 && pointinside(v2[0] , v2[1] , v2[2] , v2[3] , {i , j})){
        ok = 1;
        //cout << i  << " "  << j << '\n';
      }
    }
  }
  if(ok == 1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}