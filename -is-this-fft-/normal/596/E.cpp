#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_N = 205 * 205;

int val [MAX_N];
int nx [10], ny [10];

int nxt [MAX_N];
vector<int> pred [MAX_N];

int vis [MAX_N];
vector<int> roots;
void find_roots (int vertex, int colour) {
  vis[vertex] = colour;
  if (vis[nxt[vertex]] == 0) {
    find_roots(nxt[vertex], colour);
  } else if (vis[nxt[vertex]] == colour) {
    roots.push_back(nxt[vertex]);
  } else {
    return;
  }
}

int cycle_has [MAX_N][10];

void descend (int vertex, int src, int ptr, const string &query, bool &ans) {
  if (ptr == -1) {
    ans = true;
    return;
  }

  if (val[vertex] == query[ptr] - '0') {
    ptr--;
  }

  if (ptr == -1) {
    ans = true;
    return;
  }

  for (int u : pred[vertex]) {
    if (u != src) {
      descend(u, src, ptr, query, ans);
    }
  }
}

bool solve_root (int root, const string &query) {
  int ptr = (int) query.size() - 1;
  while (ptr >= 0 && cycle_has[root][query[ptr] - '0']) {
    ptr--;
  }

  if (ptr == -1) {
    return true;
  }

  bool ans = false;
  descend(root, root, ptr, query, ans);
  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  int height, width, queryc;
  cin >> height >> width >> queryc;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      char c;
      cin >> c;

      val[width * i + j] = c - '0';
    }
  }

  for (int i = 0; i < 10; i++) {
    cin >> nx[i] >> ny[i];
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int d = val[width * i + j];
      int ni = i + nx[d];
      int nj = j + ny[d];
      if (0 <= ni && ni < height && 0 <= nj && nj < width) {
        nxt[width * i + j] = width * ni + nj;
      } else {
        nxt[width * i + j] = width * i + j;
      }
    }
  }

  int vertexc = height * width;
  for (int i = 0; i < vertexc; i++) {
    //  cout << i << " " << nxt[i] << endl;
    if (nxt[i] != -1) {
      pred[nxt[i]].push_back(i);
    }
  }

  for (int i = 0; i < vertexc; i++) {
    find_roots(i, i + 1);
  }

  for (int u : roots) {
    int v = u;
    do {
      cycle_has[u][val[v]] = 1;
      v = nxt[v];
    } while (v != u);
  }

  for (int i = 0; i < queryc; i++) {
    string query;
    cin >> query;

    bool solved = false;
    for (int u : roots) {
      if (solve_root(u, query)) {
        cout << "YES" << '\n';
        solved = true;
        break;
      }
    }
    if (!solved) {
      cout << "NO" << '\n';
    }
  }
}