#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<int> runs;
  bool ascending = true;
  int steps = 0;
  for (int i = 0; i < n-1; i++) {
    if (ascending) {
      if (p[i+1] > p[i]) steps++;
      else {
        ascending = false;
        runs.push_back(steps);
        steps = 1;
      }
    }
    else {
      if (p[i+1] < p[i]) steps++;
      else {
        ascending = true;
        runs.push_back(steps);
        steps = 1;
      }
    }
  }
  runs.push_back(steps);
  if (ascending) runs.push_back(0);

  int maxrun = 0;
  for (int i: runs) maxrun = max(i, maxrun);
  int count = 0;
  for (int i: runs) {
    if (i == maxrun) {
      count++;
    }
  }
  if (count != 2 || maxrun % 2) {
    cout << 0 << endl;
    return 0;
  }
  else {
    int index = -1;
    for (int i = 0; i < runs.size(); i++) {
      if (runs[i] == maxrun) {
        index = i;
        break;
      }
    }
    if (runs[index+1] != maxrun || index % 2) {
      cout << 0 << endl;
      return 0;
    }
    cout << 1 << endl;
  }
}