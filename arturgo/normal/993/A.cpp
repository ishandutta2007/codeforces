#include <cmath>
#include <iostream>
#include <vector>
using namespace std;


template<typename Type>
class point {
public:
  Type x, y;
  point(Type _x = 0, Type _y = 0);
};

template<typename Type>
point<Type> operator + (const point<Type> &a, const point<Type> &b);

template<typename Type>
point<Type> operator - (const point<Type> &a, const point<Type> &b);

template<typename Type>
point<Type> operator * (const Type &a, const point<Type> &b);

template<typename Type>
Type operator * (const point<Type> &a, const point<Type> &b);

template<typename Type>
Type operator ^ (const point<Type> &a, const point<Type> &b);

template<typename Type>
long double operator ! (const point<Type> &a);

template<typename Integer>
int sign(Integer a);


template<typename Segment>
bool intersects(const Segment &a, const Segment &b);


template<typename Point, typename Polygon>
bool is_in(const Point &a, const Polygon &b, long long sizeS = 2000 * 1000 * 1000);


vector<point<long long>> read_poly() {
  vector<point<long long>> points;
  for(int iPoint = 0;iPoint < 4;iPoint++) {
    int a, b;
    cin >> a >> b;
    points.push_back(point<long long>(a, b));
  }
  return points;
}
    

int main() {
  vector<point<long long>> polyA = read_poly();
  vector<point<long long>> polyB = read_poly();

  for(int cA = 0;cA < 4;cA++) {
    for(int cB = 0;cB < 4;cB++) {
      int nA = (cA + 1) % 4;
      int nB = (cB + 1) % 4;
      if(intersects(make_pair(polyA[nA], polyA[cA]), make_pair(polyB[nB], polyB[cB]))) {
	cout << "YES" << endl;
	return 0;
      }
    }
  }

  bool AinB = true;
  for(int cA = 0;cA < 4;cA++) {
    if(!is_in(polyA[cA], polyB)) {
      AinB = false;
    }
  }

  bool BinA = true;
  for(int cB = 0;cB < 4;cB++) {
    if(!is_in(polyB[cB], polyA)) {
      BinA = false;
    }
  }

  if(AinB || BinA) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
  return 0;
}


template<typename Type>
point<Type> operator + (const point<Type> &a, const point<Type> &b) {
  return point<Type>(a.x + b.x, a.y + b.y);
}

template<typename Type>
point<Type> operator - (const point<Type> &a, const point<Type> &b) {
  return point<Type>(a.x - b.x, a.y - b.y);
}

template<typename Type>
point<Type> operator * (const Type &a, const point<Type> &b) {
  return point<Type>(a * b.x, a * b.y);
}

template<typename Type>
Type operator * (const point<Type> &a, const point<Type> &b) {
  return a.x * b.x + a.y * b.y;
}

template<typename Type>
Type operator ^ (const point<Type> &a, const point<Type> &b) {
  return a.x * b.y - a.y * b.x;
}

template<typename Type>
long double operator ! (const point<Type> &a) {
  return sqrt(a * a);
}

template<typename Type>
point<Type>::point(Type _x, Type _y) {
  x = _x;
  y = _y;
}


template<typename Integer>
int sign(Integer a) {
  if(a < 0)
    return -1;
  if(a > 0)
    return 1;
  return 0;
}

template<typename Segment>
bool intersects(const Segment &a, const Segment &b) {
  return sign((a.second - a.first) ^ (b.first - a.first)) != sign((a.second - a.first) ^ (b.second - a.first)) && sign((b.second - b.first) ^ (a.first - b.first)) != sign((b.second - b.first) ^ (a.second - b.first));
}

template<typename Point, typename Polygon>
bool is_in(const Point &a, const Polygon &b, long long sizeS) {
  pair<Point, Point> segment = make_pair(a, a + Point(1, sizeS));

  int count = 0;

  for(int c = 0;c < (int)b.size();c++) {
    int n = (c + 1) % b.size();
    if(intersects(segment, make_pair(b[c], b[n]))) {
      count++;
    }
  }

  if(count % 2 == 0)
    return false;
  return true;
}