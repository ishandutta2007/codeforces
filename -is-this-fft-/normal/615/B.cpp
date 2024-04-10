#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

const int MAX_V = 200005;

using namespace std;

long long spinec [MAX_V], maxtail [MAX_V];

int main () {
  vector<pair<int, int> > edges;
  
  int verticec, edgec;
  cin >> verticec >> edgec;
  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;
    if (u < v) {
      edges.push_back(make_pair(u, v));
    } else {
      edges.push_back(make_pair(v, u));
    }

    spinec[u]++;
    spinec[v]++;
  }

  for (int i = 1; i <= verticec; i++) {
    maxtail[i] = 1;
  }

  sort(edges.begin(), edges.end());

  for (int i = 0; i < edgec; i++) {
    maxtail[edges[i].second] = max(maxtail[edges[i].first] + 1, 
				   maxtail[edges[i].second]);
  }

  long long ans = 0;
  for (int i = 1; i <= verticec; i++) {
    if (maxtail[i] * spinec[i] > ans) {
      ans = maxtail[i] * spinec[i];
    }
  }

  cout << ans << endl;
}