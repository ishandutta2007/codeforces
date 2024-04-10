#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 505;

int degle [MAX_N];

int main () {
  int n;
  cin >> n;

  vector<int> leaves;
  vector<int> interns;
  
  int sumdeg = 0;
  for (int i = 1; i <= n; i++) {
    cin >> degle[i];
    sumdeg += degle[i];

    if (degle[i] == 1) leaves.push_back(i);
    else interns.push_back(i);
  }

  if (sumdeg < 2 * n - 2) {
    cout << "NO" << '\n';
    return 0;
  }

  int ans = (int) interns.size() + min(2, (int) leaves.size()) - 1;

  vector<pair<int, int>> edges;
  for (int i = 0; i < (int) interns.size(); i++) {
    if (i + 1 < (int) interns.size()) {
      degle[interns[i]]--;
      edges.push_back({interns[i], interns[i + 1]});
    }

    if (i - 1 >= 0) {
      degle[interns[i]]--;
    }
  }

  vector<int> chances;

  if (degle[interns[0]] != 0) {
    degle[interns[0]]--;
    chances.push_back(interns[0]);
  }

  if (degle[interns.back()] != 0) {
    degle[interns.back()]--;
    chances.push_back(interns.back());
  }

  for (int u : interns) {
    while (degle[u] > 0) {
      degle[u]--;
      chances.push_back(u);
    }
  }

  for (int i = 0; i < (int) leaves.size(); i++) {
    edges.push_back({leaves[i], chances[i]});
  }

  cout << "YES" << " " << ans << '\n';
  cout << n - 1 << '\n';
  for (auto pr : edges) {
    cout << pr.first << " " << pr.second << '\n';
  }
}