#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> ett;
vector<vector<int>> nbrs;
map<int, vector<int>> children;
set<int> visited;

void tour(int a) {
  for (int c: children[a]) {
    ett.push_back(a);
    tour(c);
  }
  ett.push_back(a);
}

int query(set<int>& q) {
  cout << "? " << q.size() << " ";
  for (int k: q) {
    cout << k << " ";
  }
  cout << endl;
  int x;
  cin >> x;
  return x;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  nbrs.resize(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    nbrs[u].push_back(v);
    nbrs[v].push_back(u);
  }
  queue<pair<int, int>> q;
  q.push({0, 0});
  while (!q.empty()) {
    int v = q.front().first;
    int parent = q.front().second;
    if (v != parent) children[parent].push_back(v);
    visited.insert(v);
    q.pop();
    for (int u: nbrs[v]) {
      if (visited.find(u) == visited.end()) {
        q.push({u, v});
      }
    }
  }
  tour(0);
  set<int> queryset;
  for (int i = 0; i < n; i++) queryset.insert(i+1);
  int maximum = query(queryset);
  queryset.clear();
  int low = 0;
  int high = 2*(n-1);
  while (low < high) {
    int mid = (low+high)/2;
    for (int i = low; i <= mid+1; i++) {
      queryset.insert(ett[i]+1);
    }
    int val = query(queryset);
    queryset.clear();
    if (val < maximum) low = mid+1;
    else high=mid;
  }
  cout << "! " << ett[low]+1 << " " << ett[low+1]+1 << endl;
}