#include <iostream>
#include <iomanip>
#include <math.h>

typedef long double ldouble;


using namespace std;

const int MAX_DISK = 1005;
const ldouble EPS = 0.1;


ldouble diskx [MAX_DISK], disky [MAX_DISK];

ldouble collides (ldouble cx, ldouble cy, ldouble nx, ldouble radius) {
  if (fabs(cx - nx) > 2 * radius) {
    return -100;
  } else {
    ldouble b = -2 * cy;
    ldouble c = (cx - nx) * (cx - nx) + cy * cy - 4 * radius * radius;
    
    ldouble ans = (-b + sqrt(b * b - 4 * c)) / 2;
    return ans;
  }
}

int main () {
  int diskc;
  ldouble radius;

  cin >> diskc >> radius;

  for (int i = 0; i < diskc; i++) {
    cin >> diskx[i];
  }

  for (int i = 0; i < diskc; i++) {
    disky[i] = radius;
    for (int j = 0; j < i; j++) {
      disky[i] = max(disky[i], collides(diskx[j], disky[j], diskx[i], radius));
    }
  }

  cout << fixed << setprecision(12);
  for (int i = 0; i < diskc; i++) {
    cout << disky[i] << ' ';
  }
  cout << endl;
}