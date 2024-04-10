#include <iostream>

using namespace std;

const int MAX_N = 100005;

int uptime [MAX_N];
int rev_uptime [MAX_N];
int seg_end [MAX_N];

int main () {
  int length, offt;
  cin >> length >> offt;

  for (int i = 1; i <= length; i++) {
    cin >> seg_end[i];

    if (i % 2 == 1) {
      uptime[i] = seg_end[i] - seg_end[i - 1];
    } else {
      rev_uptime[i - 1] = seg_end[i] - seg_end[i - 1];
    }
  }

  seg_end[length + 1] = offt;
  if ((length + 1) % 2 == 1) {
    uptime[length + 1] = seg_end[length + 1] - seg_end[length];
  } else {
    rev_uptime[length] = seg_end[length + 1] - seg_end[length];
  }

  for (int i = 1; i <= length + 1; i++) {
    uptime[i] += uptime[i - 1];
  }

  for (int i = length; i >= 0; i--) {
    rev_uptime[i] += rev_uptime[i + 1];
  }

  
  int ans = uptime[length + 1];
  for (int i = 0; i <= length; i++) {
    if (seg_end[i + 1] - seg_end[i] != 1) {
      ans = max(uptime[i] + rev_uptime[i + 1] + seg_end[i + 1] - seg_end[i] - 1, ans);
    }
  }

  cout << ans << endl;
}