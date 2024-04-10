#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

char op [MAX_N];
int person [MAX_N];

int status [MAX_N];
// 0 - always or never
// 1 - present at the beginning
// -1 - not present at the beginning

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> op[i] >> person[i];

    if (status[person[i]] == 0) {
      if (op[i] == '+') {
        status[person[i]] = -1;
      } else {
        status[person[i]] = 1;
      }
    }
  }

  set<int> cur;
  for (int i = 1; i <= n; i++) {
    if (status[i] == 1) {
      cur.insert(i);
    }
  }

  set<int> ocs;
  set<int> defno;
  for (int i = 0; i < m; i++) {
    if (op[i] == '+') {
      if (cur.empty()) {
        ocs.insert(person[i]);
      } else {
        defno.insert(person[i]);
      }
      cur.insert(person[i]);
    }

    if (op[i] == '-') {
      cur.erase(person[i]);
      if (cur.empty()) {
        ocs.insert(person[i]);
      } else {
        defno.insert(person[i]);
      }
    }
  }

  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (status[i] == 0) {
      ans.push_back(i);
    }
  }

  if ((int) ocs.size() == 1 && !defno.count(*ocs.begin())) {
    ans.push_back(*ocs.begin());
  }

  sort(ans.begin(), ans.end());

  cout << (int) ans.size() << endl;
  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;
}