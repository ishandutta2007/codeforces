#include <iostream>
#include <vector>
#include <map>

typedef long long llong;

const int MAX_VERT = 200005;

using namespace std;

llong par [MAX_VERT], val [MAX_VERT], pdist [MAX_VERT], dist [MAX_VERT];
vector<llong> adj [MAX_VERT];
vector<llong> dfsord;

void dfs (llong cur) {
  dfsord.push_back(cur);
  for (llong i = 0; i < (llong) adj[cur].size(); i++) {
    dist[adj[cur][i]] = pdist[adj[cur][i]] + dist[cur];
    dfs(adj[cur][i]);
  }
}

map<llong, llong> parents;
vector<pair<llong, llong> > events;
void dfsb (llong cur) {
  auto stat = parents.lower_bound(dist[cur] - val[cur]);
  if (stat != parents.end()) {
    events.push_back(make_pair(stat->second, par[cur]));
  }

  parents[dist[cur]] = cur;
  for (llong i = 0; i < (llong) adj[cur].size(); i++) {
    dfsb(adj[cur][i]);
  }
  parents.erase(dist[cur]);
}

llong subtree [MAX_VERT];
void dfsc (llong cur) {
  subtree[cur] = 1;

  for (llong i = 0; i < (llong) adj[cur].size(); i++) {
    dfsc(adj[cur][i]);
    subtree[cur] += subtree[adj[cur][i]];
  }
}

llong special [MAX_VERT], uplink [MAX_VERT], ord [MAX_VERT], vsum [MAX_VERT];
bool is_special [MAX_VERT];

int main () {
  llong vertexc;
  cin >> vertexc;

  for (llong i = 1; i <= vertexc; i++) {
    cin >> val[i];
  }

  for (llong i = 2; i <= vertexc; i++) {
    cin >> par[i] >> pdist[i];
    adj[par[i]].push_back(i);
  }

  dfsord = vector<llong> (0);
  dfs(1);
  dfsb(1);
  dfsc(1);

  for (llong i = 1; i <= vertexc; i++) {
    if ((llong) adj[i].size() != 0) {
      llong specialsize = 0;
      for (llong j = 0; j < (llong) adj[i].size(); j++) {
        if (subtree[adj[i][j]] > specialsize) {
          specialsize = subtree[adj[i][j]];
          special[i] = adj[i][j];
        }
      }
      is_special[special[i]] = true;
    }
  }

  /* heavy - light */

  llong cord = 1;
  for (llong i = 1; i <= vertexc; i++) {
    if (ord[i] == 0 && !is_special[i]) {
      for (llong j = i; j != 0; j = special[j]) {
        ord[j] = cord;
        cord++;
        uplink[j] = i;
      }
    }
  }

  for (llong i = 0; i < (llong) events.size(); i++) {
    for (llong j = events[i].second; true; j = par[uplink[j]]) {
      vsum[ord[j] + 1]--;

      if (uplink[events[i].first] == uplink[j]) {
        vsum[ord[events[i].first]]++;
        break;
      } else {
        vsum[ord[uplink[j]]]++;
      }
    }
  }

  for (llong i = 1; i <= vertexc; i++) {
    vsum[i] += vsum[i - 1];
  }

  for (llong i = 1; i <= vertexc; i++) {
    cout << vsum[ord[i]] << (i == vertexc ? '\n' : ' ');
  }
}