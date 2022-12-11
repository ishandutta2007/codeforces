#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
  int x, y;

  Point(int _x = 0, int _y = 0) {
    x = _x;
    y = _y;
  }
};

vector<Point> points;

Point operator - (const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y);
}

long long prod(const Point &a, const Point &b) {
  return a.x * (long long)b.y - a.y * (long long)b.x;
}

long long c2(long long n) {
  return n * (n - 1) / 2;
}

bool operator < (const Point &a, const Point& b) {
  if(a.y >= 0 && b.y < 0)
    return true;
  if(b.y >= 0 && a.y < 0)
    return false;
  long long aire = prod(a, b);
  if(aire >= 0)
    return true;
  else
    return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  int nbPoints;
  cin >> nbPoints;

  for(int iPoint = 0;iPoint < nbPoints;iPoint++) {
    Point p;
    cin >> p.x >> p.y;
    points.push_back(p);
  }

  long long nbPaires = 0;
  for(int iPivot = 0;iPivot < nbPoints;iPivot++) {
    vector<Point> autres;

    for(int iAutre = 0;iAutre < nbPoints;iAutre++) {
      if(iAutre != iPivot) {
	autres.push_back(points[iAutre] - points[iPivot]);
      }
    }

    sort(autres.begin(), autres.end());

    int nbAutres = autres.size();
    int fin = 0;
    for(int deb = 0;deb < nbAutres;deb++) {
      while(fin < deb + nbAutres && prod(autres[deb], autres[fin % nbAutres]) >= 0) {
	fin++;
      }
      nbPaires += c2(fin - deb - 1) * c2(nbAutres - (fin - deb));
    }
  }
  
  cout << nbPaires / 2 << endl;
  return 0;
}