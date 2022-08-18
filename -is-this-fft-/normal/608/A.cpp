#include <iostream>

const int MAX_F = 1005;

using namespace std;

int atime [MAX_F];

int main () {
  int passc, floorc;
  
  cin >> passc >> floorc;
  
  for (int i = 0; i < passc; i++) {
    int floor, stime;
    cin >> floor >> stime;
    atime[floor] = max(atime[floor], stime);
  }

  int ans = 0;
  for (int i = floorc; i > 0; i--) {
    if (atime[i] > ans) {
      ans = atime[i];
    }
    ans++;
  }

  cout << ans << endl;
}