#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>

typedef long double ldouble;

const int MAX_V = 55;
const int INF = 1023456789;
const ldouble EPS = 0.00000000000000001L;
const int MAX_EDGE = 505;

using namespace std;

ldouble capac [MAX_V][MAX_V];
vector<int> adj [MAX_V];
int prevn [MAX_V], vis [MAX_V], dist [MAX_V];

ldouble max_flow (int source, int sink) {
  ldouble ans = 0;
  while (true) {
    for (int i = 0; i < MAX_V; i++) {
      prevn[i] = -1;
      vis[i] = false;
      dist[i] = INF;
    }

    queue<int> que;
    que.push(source);
    while (!que.empty()) {
      int qtop = que.front();
      que.pop();

      for (int i = 0; i < adj[qtop].size(); i++) {
	if (!vis[adj[qtop][i]] && capac[qtop][adj[qtop][i]] > EPS) {
	  vis[adj[qtop][i]] = true;
	  dist[adj[qtop][i]] = dist[qtop] + i;
	  prevn[adj[qtop][i]] = qtop;
	  que.push(adj[qtop][i]);
	}
      }
    }

    if (prevn[sink] == -1) {
      break;
    }

    ldouble bneck = INF;
    for (int i = sink; i != source; i = prevn[i]) {
      bneck = min(bneck, capac[prevn[i]][i]);
    }

    ans += bneck;

    for (int i = sink; i != source; i = prevn[i]) {
      capac[prevn[i]][i] -= bneck;
      capac[i][prevn[i]] += bneck;
    }
  }

  return ans;
}

struct arc {
  int start, end;
  ldouble weight;
};

arc edges [MAX_EDGE];

int main () {
  int vertexc, edgec, bearc;
  cin >> vertexc >> edgec >> bearc;

  for (int i = 0; i < edgec; i++) {
    cin >> edges[i].start >> edges[i].end >> edges[i].weight;
    adj[edges[i].start].push_back(edges[i].end);
    adj[edges[i].end].push_back(edges[i].start);
  }

  ldouble ans = 0;
  for (ldouble i = 1000000000; i >= EPS; i /= 2) {
    for (int j = 0; j < edgec; j++) {
      capac[edges[j].start][edges[j].end] = 0;
      capac[edges[j].end][edges[j].start] = 0;
    }

    ldouble cur = ans + i;
    for (int j = 0; j < edgec; j++) {
      capac[edges[j].start][edges[j].end] = floor(edges[j].weight / cur);
    }

    int cbear = max_flow(1, vertexc);
    if (cbear >= bearc) {
      ans += i;
    }
  }

  cout << fixed << setprecision(12) << ans * bearc << endl;
}