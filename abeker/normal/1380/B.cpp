#include <bits/stdc++.h>
using namespace std;

const string rsp = "RSP";

int main() {
  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    int occ[3] = {0};
    for (auto it : s)
      occ[rsp.find(it)]++;
    cout << string(s.size(), rsp[(max_element(occ, occ + 3) - occ + 2) % 3]) << endl;
  }
  return 0;
}