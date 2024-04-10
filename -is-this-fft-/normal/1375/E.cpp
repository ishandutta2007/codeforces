#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MAX_N = 1e3 + 5;

int n;
vector<pair<int, int>> ans;
int arr [MAX_N];

void add (int u, int v) {
  ans.push_back(make_pair(u, v));
  swap(arr[u], arr[v]);
}

vector<int> pos [MAX_N];

void solve (int a, int b) {
  vector<int> apos = pos[a];
  vector<int> bpos = pos[b];

  reverse(apos.begin(), apos.end());  
  for (int i = 0; i < (int) bpos.size(); i++) {
    for (int j = 0; j < (int) apos.size() && bpos[i] < apos[j]; j++) {
      add(bpos[i], apos[j]);
    }
  }

  vector<int> allpos = apos;
  for (int u : bpos) {
    allpos.push_back(u);
  }

  sort(allpos.begin(), allpos.end());

  pos[a].clear();
  pos[b].clear();
  for (int i = 0; i < (int) apos.size(); i++) {
    pos[a].push_back(allpos[i]);
  }
  for (int i = (int) apos.size(); i < (int) allpos.size(); i++) {
    pos[b].push_back(allpos[i]);
  }
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n;

  map<int, int> compr;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    compr[arr[i]] = 0;
  }

  int K = 0;
  for (auto it = compr.begin(); it != compr.end(); it++) {
    it->second = K;
    K++;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = compr[arr[i]];
    pos[arr[i]].push_back(i);
  }

  while (true) {
    bool ok = 1;
    for (int i = 0; i < K - 1; i++) {
      if (pos[i].back() > pos[i + 1][0]) {
        solve(i, i + 1);
        ok = 0;
      }
    }

    if (ok) break;
  }
  
  cout << (int) ans.size() << '\n';
  for (auto pr : ans) {
    cout << pr.first + 1 << " " << pr.second + 1 << '\n';
  }
}