#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<pair<int, int>> pts(n);
  int x, y;
  bool oddsum = false;
  bool evensum = false;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    pts[i] = {x, y};
    if ((x+y) & 1) oddsum = true;
    else evensum = true;
  }
  while (!(oddsum & evensum)) {
    bool newoddsum = false;
    bool newevensum = false;
    int offset = 0;
    if (oddsum) offset = 1;
    for (int i = 0; i < n; i++) {
      pair<int, int> oldpt = pts[i];
      int x = (oldpt.first+oldpt.second+offset)/2;
      int y = (oldpt.first-oldpt.second+offset)/2;
      pair<int, int> newpt = {x, y};
      if ((x+y) & 1) newoddsum = true;
      else newevensum = true;
      pts[i] = newpt;
    }
    oddsum = newoddsum;
    evensum = newevensum;
  }
  vector<int> A;
  for (int i = 0; i < n; i++) {
    pair<int, int> pt = pts[i];
    if ((pt.first + pt.second) & 1) A.push_back(i+1);
  }
  cout << A.size() << endl;
  for (int i: A) {
    cout << i << " ";
  }
  cout << endl;
}