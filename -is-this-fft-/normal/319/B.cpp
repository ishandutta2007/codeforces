#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> cands;
  set<int> alive; // i, not arr[i]
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    alive.insert(i);
    cands.push_back(i);
  }

  for (int k = 0; true; k++) {
    vector<int> killers;
    vector<int> to_del;
    for (int u : cands) {
      auto it = alive.find(u);
      if (it == alive.end()) {
        continue;
      }

      auto nxt = next(it);
      if (nxt == alive.end()) {
        continue;
      }

      if (arr[u] > arr[*nxt]) {
        killers.push_back(u);
        to_del.push_back(*nxt);
      }
    }

    if (killers.empty()) {
      cout << k << endl;
      return 0;
    }

    for (int u : to_del) {
      alive.erase(u);
    }
    cands = killers;
  }
}