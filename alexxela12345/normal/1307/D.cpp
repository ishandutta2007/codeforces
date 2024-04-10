#ifndef LOCAL
//#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define max(a, b) (a < b) ? b : a

template<typename T>
istream &operator>>(istream &in, vector<T> &arr) {
  for (auto &el : arr) {
    in >> el;
  }
  return in;
}

template<typename T1, typename T2> 
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &arr) {
  for (auto &el : arr) {
    out << el;
  }
  return out;
}

template<typename T1, typename T2> 
ostream &operator>>(ostream &out, pair<T1, T2> &p) {
  out << p.first << " " << p.second;
  return out;
}

const int INF = 1e9;

int n;
vector<vector<int>> g;

vector<int> bfs(int st) {
  deque<int> q;
  vector<int> dist(n, INF);
  dist[st] = 0;
  q.push_back(st);
  while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (int u : g[v]) {
      if (dist[u] == INF) {
        dist[u] = dist[v] + 1;
        q.push_back(u);
      }
    }
  }
  return dist;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int m, k;
  cin >> n >> m >> k;
  vector<int> a(k);
  cin >> a;
  for (int &el : a) {
    el--;
  }
  g.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  auto dist1 = bfs(0);
  auto distn = bfs(n - 1);
  multiset<int> dists1, dists2;
  for (int el : a) {
    dists1.insert(dist1[el]);
    dists2.insert(distn[el]);
  }
  int maxx = 0;
  sort(a.begin(), a.end(), [&](int i, int j) { return dist1[i] < dist1[j]; });
  for (int el : a) {
    dists2.erase(dists2.find(distn[el]));
    if (dists2.empty())
      break;
    maxx = max(maxx, *dists2.rbegin() + 1 + dist1[el]);
  }
  maxx = min(maxx, dist1[n - 1]);
  cout << maxx << endl;
}