#include <bits/stdc++.h>
using namespace std;

int query(int d) {
  vector<pair<int, int>> pts;
  int k = 1<<d;
  for (int i = 1; i <= 200; i++) {
    if (i % k == 0) {
      for (int j = 1; j <= 200; j++) {
        pts.push_back({i, j});
      }
    }
  }
  cout << "? " << pts.size() << endl;
  for (pair<int, int> p: pts) {
    cout << p.first << " " << p.second << " ";
  }
  cout << endl;
  int ans;
  cin >> ans;
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  vector<int> answers(9, 0);
  answers[0] = query(0);
  int low = 0;
  int high = 8;
  int mid = (low+high)/2;
  while (low + 1 < high) {
    answers[mid] = query(mid);
    if (answers[mid]<<mid == answers[0]) low = mid;
    else high = mid;
    mid = (low+high)/2;
  }
  int h = abs(2*answers[low+1]-(answers[0]>>low));
  int b = answers[0]/h;
  cout << "! " << 2*(h+b)-4 << endl;
}