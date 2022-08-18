#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;
const int INF = 1e9 + 5;

int n;
int arr [MAX_N];
int cnt [MAX_N][2];
vector<int> pos [2];

vector<pair<int, int>> ans;
void solve (int K) {
  vector<int> sets (2, 0);

  int cur = -1;
  while (true) {
    vector<int> cpos (2, 0);
    if (cur == -1) {
      cpos = {0, 0};
    } else {
      cpos = {cnt[cur][0], cnt[cur][1]};
    }

    vector<int> nxt (2);
    for (int k = 0; k < 2; k++) {
      if (cpos[k] + K - 1 >= (int) pos[k].size()) {
        nxt[k] = INF;
      } else {
        nxt[k] = pos[k][cpos[k] + K - 1];
      }
    }

    int nxtp = min(nxt[0], nxt[1]);
    if (nxtp == INF) {
      return;
    }

    int lastmx = max(sets[0], sets[1]);
    if (nxt[0] < nxt[1]) {
      sets[0]++;
    } else {
      sets[1]++;
    }

    if (nxtp == n - 1) {
      if (lastmx < max(sets[0], sets[1])) {
        ans.push_back(make_pair(max(sets[0], sets[1]), K));
      }
      return;
    }
    cur = nxtp;
  }
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i]--;

    pos[arr[i]].push_back(i);
    cnt[i][arr[i]]++;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cnt[i][j] += cnt[i - 1][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    solve(i);
  }

  sort(ans.begin(), ans.end());
  cout << (int) ans.size() << endl;
  for (auto pr : ans) {
    cout << pr.first << " " << pr.second << '\n';
  }
}