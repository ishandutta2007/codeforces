#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

void failure () {
  cout << "No" << '\n';
  exit(0);
}

vector<int> words [MAX_N];

int cap [MAX_N];

vector<int> adj [MAX_N];
void add_prop (int u, int v) {
  adj[u].push_back(v);
}

bool vis [MAX_N];
void prop (int u) {
  vis[u] = 1;
  if (cap[u]) {
    for (int nxt : adj[u]) {
      if (!vis[nxt]) {
        cap[nxt] = 1;
        prop(nxt);
      }
    }
  }
}

bool bigger (int u, int v) {
  if (cap[u] != cap[v]) {
    return cap[u] < cap[v];
  }
  return u > v;
}

int main () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    
    words[i] = vector<int> (k);
    for (int j = 0; j < k; j++) {
      cin >> words[i][j];
    }
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < (int) min(words[i].size(), words[i + 1].size()); j++) {
      if (words[i][j] != words[i + 1][j]) {
        if (words[i][j] < words[i + 1][j]) {
          add_prop(words[i + 1][j], words[i][j]);
        } else {
          cap[words[i][j]] = 1;
        }
        break;
      }
    }
  }

  for (int i = 1; i <= m; i++) {
    if (cap[i] && !vis[i]) {
      prop(i);
    }
  }
  
  for (int i = 0; i < n - 1; i++) {
    bool flag = true;
    for (int j = 0; j < (int) min(words[i].size(), words[i + 1].size()); j++) {
      if (bigger(words[i][j], words[i + 1][j])) {
        failure();
      } else if (bigger(words[i + 1][j], words[i][j])) {
        flag = false;
        break;
      }
    }
    if (flag) {
      if (words[i + 1].size() < words[i].size()) {
        failure();
      }
    }
  }

  vector<int> ans;
  for (int i = 1; i <= m; i++) {
    if (cap[i]) {
      ans.push_back(i);
    }
  }

  cout << "Yes" << endl;
  cout << (int) ans.size() << endl;
  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;
}