#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u-1].push_back(v-1);
      adj[v-1].push_back(u-1);
    }
    vector<int> ans(n, 0);
    vector<int> available;
    int index;
    vector<int> nums;
    for (int k = 1; k < 20; k++) {
      if ((1<<(k-1))-1 < n) {
        available.push_back(min(1<<(k-1), n-((1<<(k-1))-1)));
        nums.push_back(1<<(k-1));
        index = k-1;
      }
      else break;
    }

    vector<bool> is_found(n, 0);
    vector<int> markednbrs(n, 0);
    vector<unordered_set<int>> disallowed(n);
    queue<int> leaves;
    for (int i = 0; i < n; i++) {
      if (adj[i].size() <= 1) {
        is_found[i] = 1;
        leaves.push(i);
      }
    }
    while (!leaves.empty()) {
      int v = leaves.front();
      //cout << v << endl;
      leaves.pop();
      int used = 1e9;
      while (available[index] == 0) {
        index--;
      }
      for (int i = index; i >= 0; i--) {
        if (!disallowed[v].count(i) && available[i] > 0) {
          //cout << v << " " << i << "X" << endl;
          ans[v] = nums[i];
          nums[i]++;
          available[i]--;
          used = i;
          break;
        }
      }
      assert(used != 1e9);
      for (int u: adj[v]) {
        markednbrs[u]++;
        disallowed[u].insert(used);
        if (adj[u].size()-1 <= markednbrs[u] && !is_found[u]) {
          is_found[u] = 1;
          leaves.push(u);
        }
      }
    }
    for (int i: ans) cout << i << " ";
    cout << endl;
  }
}