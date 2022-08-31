#include <iostream>
#include <map>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  
  int length;
  cin >> length;

  map<int, int> evencnt;
  map<int, int> oddcnt;
  int pref = 0;
  oddcnt[0] = 1;
  long long ans = 0;
  for (int i = 0; i < length; i++) {
    int ai;
    cin >> ai;

    pref ^= ai;
    if (i % 2 == 0) {
      if (evencnt.count(pref) == 0) {
        evencnt[pref] = 0;
      }

      ans += evencnt[pref];
      evencnt[pref]++;
    } else {
      if (oddcnt.count(pref) == 0) {
        oddcnt[pref] = 0;
      }

      ans += oddcnt[pref];
      oddcnt[pref]++;
    }
  }

  cout << ans << endl;
}