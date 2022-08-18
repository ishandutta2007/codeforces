#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MAX_V = 300005;

typedef long long llong;

vector<pair<llong, llong>> adj [MAX_V];
llong par [MAX_V];
llong par_cost [MAX_V];
llong subtree_size [MAX_V];

typedef pair<llong, llong> edge;

void dfs (llong vertex, llong parent) {
  par[vertex] = parent;
  subtree_size[vertex] = 1;

  for (edge nxt : adj[vertex]) {
    if (nxt.first != parent) {
      par_cost[nxt.first] = nxt.second;
      dfs(nxt.first, vertex);
      subtree_size[vertex] += subtree_size[nxt.first];
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  llong vertexc, queryc;
  cin >> vertexc >> queryc;

  for (llong i = 0; i < vertexc - 1; i++) {
    llong u, v;
    llong w;
    cin >> u >> v >> w;

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  dfs(1, 0);
  
  deque<llong> path;
  for (llong i = vertexc; i != 0; i = par[i]) {
    path.push_front(i);
  }

  vector<llong> arr ((llong) path.size(), 0);

  bool trivial_case = false;
  if (subtree_size[vertexc] >= 3) {
    trivial_case = true;
  }

  for (edge nxt : adj[vertexc]) {
    if (nxt.first != par[vertexc]) {
      arr.back() = nxt.second;
    }
  }

  for (llong i = 0; i < (llong) path.size() - 1; i++) {
    if (subtree_size[path[i]] - subtree_size[path[i + 1]] >= 3) {
      trivial_case = true;
    }

    for (edge nxt : adj[path[i]]) {
      if (nxt.first != par[path[i]] && nxt.first != path[i + 1]) {
        arr[i] = nxt.second;
      }
    }
  }

  llong sumdist = 0;
  vector<llong> dists ((llong) path.size(), 0);
  for (llong i = 1; i < (llong) path.size(); i++) {
    dists[i] = par_cost[path[i]];
    sumdist += dists[i];
  }

  llong magic = - (1LL << 60);
  pair<pair<llong, llong>, pair<llong, llong>> cur_suff =
    make_pair(make_pair(arr.back(), (llong) arr.size() - 1),
              make_pair(-(1LL << 60), -1));
  
  for (llong i = (llong) path.size() - 2; i >= 0; i--) {
    cur_suff.first.first -= dists[i + 1];
    cur_suff.second.first -= dists[i + 1];

    if (cur_suff.first.second == i + 1 && arr[i + 1] == 0 && arr[i] == 0) {
      magic = max(magic, cur_suff.second.first + arr[i]);
    } else {
      magic = max(magic, cur_suff.first.first + arr[i]);
    }

    pair<llong, llong> new_suff = make_pair(arr[i], i);
    if (new_suff >= cur_suff.first) {
      cur_suff.second = cur_suff.first;
      cur_suff.first = new_suff;
    } else if(new_suff >= cur_suff.second) {
      cur_suff.second = new_suff;
    }
  }
  
  for (llong i = 0; i < queryc; i++) {
    llong query;
    cin >> query;

    if (trivial_case) {
      cout << sumdist << '\n';
    } else {
      cout << sumdist + min(magic + query, 0LL) << '\n';
    }
  }
}