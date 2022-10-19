#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9+1e5;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  int sx, sy, fx, fy;
  cin >> sx >> sy >> fx >> fy;

  vector<tuple<int, int, int>> portalsx;
  vector<tuple<int, int, int>> portalsy;
  vector<pair<int, int>> portals;
  vector<vector<pair<int, int>>> edges(m);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    portalsx.push_back({x, y, i});
    portalsy.push_back({y, x, i});
    portals.push_back({x, y});
  }
  sort(portalsx.begin(), portalsx.end());
  sort(portalsy.begin(), portalsy.end());
  for (int i = 0; i < m-1; i++) {
    edges[get<2>(portalsx[i])].push_back(
        {get<2>(portalsx[i+1]), get<0>(portalsx[i+1]) - get<0>(portalsx[i])});
    edges[get<2>(portalsx[i+1])].push_back(
        {get<2>(portalsx[i]), get<0>(portalsx[i+1]) - get<0>(portalsx[i])});
    edges[get<2>(portalsy[i])].push_back(
        {get<2>(portalsy[i+1]), get<0>(portalsy[i+1]) - get<0>(portalsy[i])});
    edges[get<2>(portalsy[i+1])].push_back(
        {get<2>(portalsy[i]), get<0>(portalsy[i+1]) - get<0>(portalsy[i])});
  }

  /*
  for (int i = 0; i < m; i++) {
    cout << i << endl;
    for (pair<int, int> e: edges[i]) {
      cout << e.first << " " << e.second << endl;
    }
  }
  */
  vector<int> dist(m, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 0; i < m; i++) {
    dist[i] = abs(fx-portals[i].first) + abs(fy-portals[i].second);
    pq.push({dist[i], i});
  }
  while (!pq.empty()) {
    pair<int, int> s = pq.top();
    pq.pop();
    int i = s.second;
    int d = s.first;
    if (dist[i] < d) continue;
    for (pair<int, int> e: edges[i]) {
      int j = e.first;
      if (dist[j] > d + e.second) {
        dist[j] = d+e.second;
        pq.push({dist[j], j});
      }
    }
  }

  int ans = abs(sx-fx) + abs(sy-fy);
  for (int i = 0; i < m; i++) {
    ans = min(ans, dist[i] + min(abs(sx-portals[i].first), abs(sy-portals[i].second)));
  }
  cout << ans << '\n';
}