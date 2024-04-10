#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 505;

bool ask (pair<int, int> pr) {
  int u = pr.first;
  int v = pr.second;

  cout << "? " << v + 1 << " " << u + 1 << endl;

  string ans;
  cin >> ans;

  return ans[0] == 'Y';
}

void report (pair<int, int> pr) {
  cout << "! " << pr.first + 1 << " " << pr.second + 1 << endl;
}

int indeg [MAX_N];

int diff (pair<int, int> pr) {
  return indeg[pr.second] - indeg[pr.first];
}

bool bydiff (pair<int, int> u, pair<int, int> v) {
  if (diff(u) != diff(v)) {
    return diff(u) > diff(v);
  }
  return u < v;
}

int main () {
  int n;
  cin >> n;

  vector<pair<int, int>> ord; // <indeg, i>
  for (int i = 0; i < n; i++) {
    cin >> indeg[i];
    ord.push_back(make_pair(indeg[i], i));
  }

  sort(ord.begin(), ord.end());

  vector<pair<int, int>> pairs;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      pairs.push_back(make_pair(ord[i].second, ord[j].second));
    }
  }

  sort(pairs.begin(), pairs.end(), bydiff);

  for (auto pr : pairs) {
    if (ask(pr)) {
      report(pr);
      return 0;
    }
  }

  cout << "! 0 0" << endl;
}