#include <iostream>
#include <queue>
#include <stdlib.h>
#include <map>
#include <algorithm>
#include <vector>

const int MAX_EDGE = 100005;
const int MAX_VERTEX = 100005;
const int INF = 1023456789;

using namespace std;

struct uedge {
  int length;
  bool span;
  int index;

  uedge () {
    length = INF;
    span = false;
    index = INF;
  }

  uedge (int il, bool is, int ii) {
    length = il;
    span = is;
    index = ii;
  }
};

bool operator< (uedge e, uedge f) {
  if (e.length == f.length) {
    return e.span > f.span;
  } else {
    return e.length < f.length;
  }
}

uedge edges [MAX_EDGE];
pair<int, int> ans [MAX_EDGE];

int main () {
  int vertexc, edgec;
  cin >> vertexc >> edgec;
  
  int spansize = 0;
  for (int i = 0; i < edgec; i++) {
    cin >> edges[i].length >> edges[i].span;
    edges[i].index = i;
    spansize += edges[i].span;
  }

  if (spansize != vertexc - 1) {
    cout << -1 << endl;
    return 0;
  }
  
  if (vertexc * (vertexc - 1) / 2 < edgec) {
    cout << -1 << endl;
    return 0;
  }

  sort(edges, edges + edgec);

  queue<pair<int, int> > cycles;
  int quelim = 4 * edgec;
  int lastv = 1;
  for (int i = 0; i < edgec; i++) {
    if (edges[i].span) { /* Current edge is in the spanning tree */
      ans[edges[i].index] = make_pair(lastv, lastv + 1);

      for (int i = 1; i < lastv && cycles.size() < quelim; i++) {
        cycles.push(make_pair(i, lastv + 1));
      }

      lastv++;
    } else { /* Find an edge that forms a cycle */
      if (cycles.empty()) {
	cout << -1 << endl;
	return 0;
      }

      ans[edges[i].index] = cycles.front();
      cycles.pop();
      quelim--;
    }
  }

  if (lastv != vertexc) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < edgec; i++) {
      cout << ans[i].first << " " << ans[i].second << endl;
    }
  }
}