#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int p, x, y;
  cin >> p >> x >> y;
  vector<set<int>> goodk(501);
  for (int t = 0; t < 475; t++) {
    int u = t;
    for (int j = 0; j < 25; j++) {
      u = (96*u+42) % 475;
      goodk[26+u].insert(t);
    }
  }
  int lowerlim = -((x-y)/50);
  int curr = x/50;
  for (int i = 0; i < 500; i++) {
    if (goodk[p].count(curr+lowerlim+i)) {
      cout << max(0, (lowerlim+i+1)/2) << endl;
      return 0;
    }
  }
}