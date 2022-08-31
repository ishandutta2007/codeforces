#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 10005;

struct Edge {
  int other, id;

  Edge () {}
  
  Edge (int t_other, int t_id) :
    other(t_other), id(t_id) {}
};    

pair<int, int> edges [MAX_N];
vector<Edge> adj [MAX_N];

void initPaint (int vertex, vector<int> &color, int curColor, bool &ok) {
  color[vertex] = curColor;

  for (Edge nxt : adj[vertex]) {
    if (color[nxt.other] == color[vertex]) {
      ok = false;
    } else if (color[nxt.other] == 0) {
      initPaint(nxt.other, color, -curColor, ok);
    }
  }
}

vector<Edge> children [MAX_N];
Edge parent [MAX_N];
bool isSpan [MAX_N];
bool inTree [MAX_N];

void buildDfs (int vertex, vector<int> &vis) {
  vis[vertex] = true;
  inTree[vertex] = true;
  for (Edge nxt : adj[vertex]) {
    if (!vis[nxt.other]) {
      isSpan[nxt.id] = 1;
      children[vertex].push_back(nxt);
      parent[nxt.other] = nxt;
      buildDfs(nxt.other, vis);
    }
  }
}

int treeColor [MAX_N];
int lvl [MAX_N];
void paintTree (int vertex, int curColor, int curLvl) {
  treeColor[vertex] = curColor;
  lvl[vertex] = curLvl;
  for (Edge nxt : children[vertex]) {
    paintTree(nxt.other, -curColor, curLvl + 1);
  }
}

vector<int> ans;
int contraCnt;

int contras [MAX_N];
int satis [MAX_N];
pair<int, int> accumulate (int vertex, int root) {
  int curContras = contras[vertex];
  int curSatis = satis[vertex];
  for (Edge nxt : children[vertex]) {
    pair<int, int> pr = accumulate(nxt.other, root);
    curContras += pr.first;
    curSatis += pr.second;
  }
  if (curContras == contraCnt && curSatis == 0 && vertex != root) {
    ans.push_back(parent[vertex].id);
  }
  return make_pair(curContras, curSatis);
}
  

int main () {
  ios::sync_with_stdio(false);

  int vertexc, edgec;
  cin >> vertexc >> edgec;

  for (int i = 1; i <= edgec; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(Edge(v, i));
    adj[v].push_back(Edge(u, i));
    edges[i].first = u;
    edges[i].second = v;
  }

  vector<int> initColors (vertexc + 1, 0);
  vector<int> badRoots;
  for (int i = 1; i <= vertexc; i++) {
    if (initColors[i] == 0) {
      bool ok = true;
      initPaint(i, initColors, 1, ok);
      if (!ok) {
        badRoots.push_back(i);
      }
    }
  }

  if ((int) badRoots.size() == 0) {
    cout << edgec << '\n';
    for (int i = 1; i <= edgec; i++) {
      cout << i << " ";
    }
    cout << '\n';
    return 0;
  }

  if ((int) badRoots.size() >= 2) {
    cout << 0 << '\n';
    return 0;
  }

  int root = badRoots[0];
  vector<int> vis (vertexc + 1, 0);
  buildDfs(root, vis);
  paintTree(root, 1, 0);

  contraCnt = 0;
  for (int i = 1; i <= edgec; i++) {
    if (!isSpan[i] && inTree[edges[i].first]) {
      if (treeColor[edges[i].first] == treeColor[edges[i].second]) {
        contraCnt++;
      }
    }
  }

  for (int i = 1; i <= edgec; i++) {
    if (!isSpan[i] && inTree[edges[i].first]) {
      if (treeColor[edges[i].first] == treeColor[edges[i].second]) {
        if (contraCnt == 1) {
          ans.push_back(i);
        }
      }

      if (lvl[edges[i].first] > lvl[edges[i].second]) {
        swap(edges[i].first, edges[i].second);
      }

      if (treeColor[edges[i].first] == treeColor[edges[i].second]) {
        contras[edges[i].second]++;
        contras[edges[i].first]--;
      } else {
        satis[edges[i].second]++;
        satis[edges[i].first]--;
      }
    }
  }

  accumulate(root, root);

  sort(ans.begin(), ans.end());

  cout << (int) ans.size() << '\n';
  for (int u : ans) {
    cout << u << " ";
  }
  cout << '\n';
}