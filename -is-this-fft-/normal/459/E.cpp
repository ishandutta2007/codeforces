#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

const int MAX_V = 300005;
const int MAX_E = 300005;

using namespace std;

struct edge {
  int start, end, weight;
};

bool operator< (edge a, edge b) {
  return a.weight < b.weight;
}

edge arcs [MAX_E];
int best [MAX_V];

int main () {
  ios::sync_with_stdio(false);

  int vertexc, edgec;
  cin >> vertexc >> edgec;
  for (int i = 0; i < edgec; i++) {
    cin >> arcs[i].start >> arcs[i].end >> arcs[i].weight;
  }

  sort(arcs, arcs + edgec);

  queue<pair<int, int> > nbest;
  for (int i = 0; i < edgec; i++) {
    if (i > 0 && arcs[i - 1].weight != arcs[i].weight) {
      while (!nbest.empty()) {
	pair<int, int> qtop = nbest.front();
	nbest.pop();

	best[qtop.first] = max(best[qtop.first], qtop.second);
      }
    }

    nbest.push(make_pair(arcs[i].end, best[arcs[i].start] + 1));
  }
  while (!nbest.empty()) {
    pair<int, int> qtop = nbest.front();
    nbest.pop();

    best[qtop.first] = max(best[qtop.first], qtop.second);
  }


  int ans = 0;
  for (int i = 1; i <= vertexc; i++) {
    ans = max(ans, best[i]);
  }

  cout << ans << endl;
}