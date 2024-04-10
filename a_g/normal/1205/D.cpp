#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> subtreesizes;
vector<vector<int>> ans;

void process(int v, int p) {
  subtreesizes[v] = 1;
  for (int u: adj[v]) {
    if (u != p) {
      process(u, v);
      subtreesizes[v] += subtreesizes[u];
    }
  }
}

int getcentroid(int v, int p) {
  for (int u: adj[v]) {
    if (u != p && subtreesizes[u] > n/2) {
      return getcentroid(u, v);
    }
  }
  return v;
}

void label(int v, int p, vector<int> targets, set<int> banned) {
  int index = 0;
  for (int u: adj[v]) {
    if (u != p && !banned.count(u)) {
      int m = subtreesizes[u];
      ans.push_back({v, u, targets[index]});
      vector<int> newtargets;
      for (int i = 0; i < m-1; i++) {
        newtargets.push_back(targets[index+i+1]-targets[index]);
      }
      index += m;
      label(u, v, newtargets, set<int>());
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  adj.resize(n);
  subtreesizes.resize(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  //find centroid
  process(0, 0);
  int centroid = getcentroid(0, 0);
  process(centroid, centroid);
  assert(getcentroid(centroid, centroid) == centroid);

  vector<int> a;
  vector<int> b;
  int asize = 0, bsize = 0;
  // place children in decreasing order of subtree size
  vector<pair<int, int>> s;
  for (int u: adj[centroid]) {
    s.push_back({-subtreesizes[u], u});
  }
  sort(s.begin(), s.end());
  for (pair<int, int> p: s) {
    int u = p.second;
    if (asize > bsize) {
      b.push_back(u);
      bsize += subtreesizes[u];
    }
    else {
      a.push_back(u);
      asize += subtreesizes[u];
    }
  }
  assert((asize+1)*(bsize+1)-1 >= (2*n*n)/9);
  vector<int> atargets;
  vector<int> btargets;
  for (int i = 1; i <= asize; i++) atargets.push_back(i);
  for (int i = 1; i <= bsize; i++) btargets.push_back((asize+1)*i);
  label(centroid, centroid, atargets, set<int>(b.begin(), b.end()));
  label(centroid, centroid, btargets, set<int>(a.begin(), a.end()));

  for (vector<int> p: ans) {
    cout << p[0]+1 << " " << p[1]+1 << " " << p[2] << endl;
  }
}