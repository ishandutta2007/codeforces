#include <iostream>
#include <vector>
#include <set>

using namespace std;

void failure () {
  cout << "REJECTED" << endl;
  exit(0);
}

vector<vector<int>> qs;

void dfs (const vector<int> &cur, int pos) {
  if (pos == (int) qs.size()) {
    for (int i = 0; i < (int) cur.size() - 1; i++) {
      if (cur[i] > cur[i + 1]) {
        failure();
      }
    }
  } else {
    const auto& q = qs[pos];
    int zeros = 0, ones = 0, indets = 0;
    for (int u : q) {
      if (cur[u] == 0) zeros++;
      else if (cur[u] == 1) ones++;
      else indets++;
    }

    vector<int> nxt = cur;
    for (int i = 0; i < (int) q.size(); i++) {
      if (i < zeros) {
        nxt[q[i]] = 0;
      } else {
        nxt[q[i]] = 1;
      }
    }

    dfs(nxt, pos + 1);
    for (int i = zeros; i < zeros + indets; i++) {
      nxt[q[i]] = 0;
      dfs(nxt, pos + 1);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, K;
  cin >> n >> K;

  if (n == 1) {
    cout << "ACCEPTED" << endl;
    return 0;
  }
  
  set<int> unseen;
  for (int i = 0; i < n; i++) {
    unseen.insert(i);
  }
  
  qs = vector<vector<int>> (K);
  for (int i = 0; i < K; i++) {
    int k;
    cin >> k;

    qs[i] = vector<int> (k);
    for (int j = 0; j < k; j++) {
      cin >> qs[i][j];
      qs[i][j]--;
      unseen.erase(qs[i][j]);
    }
  }

  if (!unseen.empty()) {
    failure();
  }
  
  vector<int> cur (n, -1);
  dfs(cur, 0);

  cout << "ACCEPTED" << endl;
}