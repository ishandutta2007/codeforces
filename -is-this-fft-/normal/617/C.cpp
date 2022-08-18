#include <iostream>
#include <vector>
#include <algorithm>

const long long INF = 1e+18 + 1000;

using namespace std;

struct point {
  long long x, y;
  
  point () {
    x = 0;
    y = 0;
  }
};

long long distsq (point a, point b) {
  return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

int main () {
  int flowerc;
  point fount1, fount2;
  cin >> flowerc >> fount1.x >> fount1.y >> fount2.x >> fount2.y;
  
  vector<point> flowers (flowerc);
  for (int i = 0; i < flowerc; i++) {
    cin >> flowers[i].x >> flowers[i].y;
  }

  vector<pair<long long, long long> > dist (flowerc);
  for (int i = 0; i < flowerc; i++) {
    dist[i].first = distsq(fount1, flowers[i]);
    dist[i].second = distsq(fount2, flowers[i]);
  }

  sort(dist.begin(), dist.end());
  
  long long ans = INF;
  for (int i = 0; i <= flowerc; i++) { // First point where .second is considered
    long long intens1, intens2 = 0;
    if (i > 0) {
      intens1 = dist[i - 1].first;
    } else {
      intens1 = 0;
    }
    for (int j = i; j < flowerc; j++) {
      intens2 = max(dist[j].second, intens2);
    }

    if (intens1 + intens2 < ans) {
      ans = intens1 + intens2;
    }
  }

  cout << ans << endl;
}