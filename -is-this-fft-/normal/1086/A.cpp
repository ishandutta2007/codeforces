#include <iostream>
#include <set>
#define x first
#define y second

using namespace std;

typedef pair<int, int> point;

int manh (point p, point q) {
  return abs(p.x - q.x) + abs(p.y - q.y);
}

int main () {
  ios::sync_with_stdio(false);
  
  point A, B, C;
  cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

  pair<int, point> bestctr = make_pair(100000, make_pair(-1, -1));
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= 1000; j++) {
      point P = make_pair(i, j);

      bestctr = min(bestctr, make_pair(manh(P, A) + manh(P, B) + manh(P, C), P));
    }
  }

  point P = bestctr.second;

  set<point> path;
  for (int i = min(A.x, P.x); i <= max(A.x, P.x); i++) {
    path.insert(make_pair(i, P.y));
  }

  for (int i = min(A.y, P.y); i <= max(A.y, P.y); i++) {
    path.insert(make_pair(A.x, i));
  }

  for (int i = min(B.x, P.x); i <= max(B.x, P.x); i++) {
    path.insert(make_pair(i, P.y));
  }

  for (int i = min(B.y, P.y); i <= max(B.y, P.y); i++) {
    path.insert(make_pair(B.x, i));
  }

  for (int i = min(C.x, P.x); i <= max(C.x, P.x); i++) {
    path.insert(make_pair(i, P.y));
  }

  for (int i = min(C.y, P.y); i <= max(C.y, P.y); i++) {
    path.insert(make_pair(C.x, i));
  }

  cout << (int) path.size() << '\n';
  for (point P : path) {
    cout << P.x << " " << P.y << '\n';
  }
}