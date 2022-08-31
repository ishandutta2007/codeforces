#include <iostream>

const int MAX_DAY = 370;

using namespace std;

int mcount [MAX_DAY];
int fcount [MAX_DAY];

int main () {
  int peoplec;
  cin >> peoplec;

  for (int i = 0; i < peoplec; i++) {
    char gender;
    int lo, hi;
    cin >> gender >> lo >> hi;
    
    if (gender == 'M') {
      mcount[lo]++;
      mcount[hi + 1]--;
    } else {
      fcount[lo]++;
      fcount[hi + 1]--;
    }
  }
 
  for (int i = 1; i <= 366; i++) {
    mcount[i] = mcount[i - 1] + mcount[i];
    fcount[i] = fcount[i - 1] + fcount[i];
  }

  int ans = 0;
  for (int i = 0; i <= 366; i++) {
    ans = max(ans, 2 * min(fcount[i], mcount[i]));
  }

  cout << ans << endl;
}