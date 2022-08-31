#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1005;

int enterc [MAX_N];
int exitc [MAX_N];
int segId [MAX_N];

int main () {
  int length, factc;
  cin >> length >> factc;

  vector<pair<int, int>> checks;
  for (int i = 0; i < factc; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    l--;
    r--;

    if (t == 1) {
      enterc[l]++;
      exitc[r]++;
    } else {
      checks.push_back(make_pair(l, r));
    }
  }

  int curId = 0;
  int curDepth = 0;
  for (int i = 0; i < length; i++) {
    curDepth += enterc[i];
    if (curDepth == enterc[i]) {
      curId++;
    }
    if (curDepth == 0) {
      segId[i] = 0;
    } else {
      segId[i] = curId;
    }
    curDepth -= exitc[i];
  }

  for (pair<int, int> pr : checks) {
    if (segId[pr.first] == segId[pr.second] && segId[pr.first] != 0) {
      cout << "NO" << '\n';
      return 0;
    }
  }

  int cur = 1000000000 - 1000 - 10;
  cout << "YES" << '\n';
  for (int i = 0; i < length; i++) {
    if (segId[i] == 0 || (i > 0 && segId[i] != segId[i - 1])) {
      cur -= 1005;
      cout << cur << " ";
    } else {
      cur++;
      cout << cur << " ";
    }
  }

  cout << '\n';
}