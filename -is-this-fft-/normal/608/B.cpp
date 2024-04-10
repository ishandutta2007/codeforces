#include <iostream>
#include <string>

const int MAX_L = 200005;

using namespace std;

int icount [MAX_L]; // amount of '1' chars in the in the substr of length i;

int inrange (int l, int r) { // amount of '1' chars in [l, r)
  return (icount[r] - icount[l]);
}
  

int main () {
  string small, large;
  cin >> small >> large;

  for (int i = 0; i < small.size(); i++) {
    icount[i + 1] = icount[i] + small.at(i) - '0';
  }

  // cout << large.size() << " " << small.size() << endl;
  long long ans = 0;
  for (int i = 0; i < large.size(); i++) {
    int lp = max(0, i - ((int) large.size() - (int) small.size()));
    int rp = min(i + 1, (int) small.size());
    // cout << lp << ":" << rp << endl;
    if (large.at(i) == '0') {
      ans += inrange(lp, rp);
    } else {
      ans += rp - lp - inrange(lp, rp);
    }
  }

  cout << ans << endl;
}