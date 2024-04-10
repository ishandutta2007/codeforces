#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
  int N;
  cin >> N;
  
  string s, t;
  cin >> s >> t;

  vector<int> abs;
  vector<int> bas;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'a' && t[i] == 'b') abs.push_back(i);
    if (s[i] == 'b' && t[i] == 'a') bas.push_back(i);
  }

  if (((int) abs.size() + (int) bas.size()) % 2 == 1) {
    cout << -1 << endl;
    return 0;
  }

  vector<pair<int, int>> ans;
  while ((int) abs.size() >= 2) {
    int u = abs.back();
    abs.pop_back();
    int v = abs.back();
    abs.pop_back();
    ans.push_back({u, v});
  }
  while ((int) bas.size() >= 2) {
    int u = bas.back();
    bas.pop_back();
    int v = bas.back();
    bas.pop_back();
    ans.push_back({u, v});
  }

  if (!abs.empty() && !bas.empty()) {
    int u = abs.back();
    int v = bas.back();
    ans.push_back({u, u});
    ans.push_back({v, u});
  }

  cout << (int) ans.size() << endl;
  for (pair<int, int> pr : ans) {
    cout << pr.first + 1 << " " << pr.second + 1 << endl;
  }
}