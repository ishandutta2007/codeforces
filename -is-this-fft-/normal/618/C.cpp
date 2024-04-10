#include <iostream>
#include <algorithm>

const int MAX_STAR = 100005;
const long double EPS = 0.000001;

using namespace std;

struct star {
  long long x, y, index;
};

bool operator< (star a, star b) {
  if (a.x == b.x) {
    return a.y < b.y;
  } else {
    return a.x < b.x;
  }
}

bool sameline (star a, star b, star c) {
  long long area = a.x * (b.y - c.y) 
    + b.x * (c.y - a.y)
    + c.x * (a.y - b.y);
  if (area == 0) {
    return true;
  } else {
    return false;
  }
}

star constel [MAX_STAR];

int main () {
  int starc;
  cin >> starc;

  for (int i = 0; i < starc; i++) {
    cin >> constel[i].x >> constel[i].y;
    constel[i].index = i + 1;
  }

  sort(constel, constel + starc);

  star stra = constel[0];
  star strb = constel[1];
  star strc;
  for (int i = 2; ; i++) {
    if (!sameline(stra, strb, constel[i])) {
      strc = constel[i];
      break;
    }
  }

  cout << stra.index << " " << strb.index << " " << strc.index << endl;
}