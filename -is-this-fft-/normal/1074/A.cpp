#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  int vertc, horc;
  cin >> vertc >> horc;

  vector<int> verts (vertc);
  for (int i = 0; i < vertc; i++) {
    cin >> verts[i];
  }
  verts.push_back(1000000000);
  
  sort(verts.begin(), verts.end());

  vector<int> hors;
  for (int i = 0; i < horc; i++) {
    int xl, xr, y;
    cin >> xl >> xr >> y;

    if (xl == 1 && xr >= verts[0]) {
      hors.push_back(xr);
    }
  }

  sort(hors.begin(), hors.end());
  
  vector<int> cum (vertc + 1, 0);
  int vptr = 0;
  for (int h : hors) {
    while (vptr != vertc && h >= verts[vptr + 1]) {
      vptr++;
    }
    cum[vptr]++;
  }

  for (int i = vertc - 1; i >= 0; i--) {
    cum[i] += cum[i + 1];
  }

  int ans = 300005;
  for (int i = 0; i <= vertc; i++) {
    ans = min(ans, i + cum[i]);
  }
  cout << ans << endl;
}