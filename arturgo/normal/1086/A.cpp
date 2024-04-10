#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int my;

void write(int x, int y) {
  if(y == my) {
    return;
  }
  if(y < my) {
    for(int i = y;i < my;i++) {
      cout << x << " " << i << endl;
    }
  }
  if(y > my) {
    for(int i = my + 1;i <= y;i++) {
      cout << x << " " << i << endl;
    }
  } 
}

int main() {
  int ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;

  vector<int> xs;
  xs.push_back(ax);
  xs.push_back(bx);
  xs.push_back(cx);
  sort(xs.begin(), xs.end());

  vector<int> ys;
  ys.push_back(ay);
  ys.push_back(by);
  ys.push_back(cy);
  sort(ys.begin(), ys.end());

  my = ys[1];
  cout << ys[2] - ys[0] + xs[2] - xs[0] + 1 << endl;

  for(int x = xs[0];x <= xs[2];x++) {
    cout << x << " " << ys[1] << endl;
  }
  
  write(ax, ay);
  write(bx, by);
  write(cx, cy);
  return 0;
}