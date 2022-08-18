#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 105;

vector<int> add [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, T;
  cin >> n >> T;

  for (int i = 0; i < n; i++) {
    int t, q;
    cin >> t >> q;

    add[t].push_back(q);
  }

  vector<int> last;
  for (int i = 1; i <= T; i++) {
    sort(last.begin(), last.end(), greater<int>());

    vector<int> cur;
    for (int j = 0; j < (int) last.size(); j += 2) {
      if (j + 1 == (int) last.size()) {
        cur.push_back(last[j]);
      } else {
        cur.push_back(last[j] + last[j + 1]);
      }
    }

    cur.insert(cur.end(), add[i].begin(), add[i].end());
    last = cur;
  }

  sort(last.begin(), last.end(), greater<int>());
  cout << last[0] << endl;
}