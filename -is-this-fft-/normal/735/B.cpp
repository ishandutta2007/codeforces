#include <iostream>
#include <iomanip>
#include <algorithm>

typedef long double ldouble;

const int MAX_PEOPLE = 100005;

using namespace std;

ldouble people [MAX_PEOPLE];

int main () {
  int peoplec, smallcity, bigcity;
  cin >> peoplec >> smallcity >> bigcity;

  if (smallcity > bigcity) {
    swap(smallcity, bigcity);
  }

  for (int i = 0; i < peoplec; i++) {
    cin >> people[i];
  }

  sort(people, people + peoplec, greater<ldouble> ());

  ldouble ans = 0;
  for (int i = 0; i < smallcity; i++) {
    ans += people[i] / smallcity;
  }

  for (int i = smallcity; i < smallcity + bigcity; i++) {
    ans += people[i] / bigcity;
  }

  cout << fixed << setprecision(12) << ans << endl;
}