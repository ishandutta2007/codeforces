#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e6 + 6;

int height, width;
int to_idx (int i, int j) {
  return i * width + j;
}

vector<int> adj [MAX_N];
int comp [MAX_N];
vector<int> comp_of [MAX_N];
void dfs (int u, int src) {
  comp[u] = src;
  comp_of[src].push_back(u);
  for (int nxt : adj[u]) {
    if (comp[nxt] == -1) {
      dfs(nxt, src);
    }
  }
}

void add_edge (int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

vector<vector<int>> table;
int ans [MAX_N];

int main () {
  for (int i = 0; i < MAX_N; i++) {
    comp[i] = -1;
  }
  
  ios::sync_with_stdio(false);

  cin >> height >> width;
  table = vector<vector<int>> (height, vector<int> (width));
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> table[i][j];
    }
  }

  for (int i = 0; i < height; i++) {
    vector<pair<int, int>> cur_row;
    for (int j = 0; j < width; j++) {
      cur_row.push_back(make_pair(table[i][j], to_idx(i, j)));
    }
    sort(cur_row.begin(), cur_row.end());

    for (int j = 0; j < width - 1; j++) {
      if (cur_row[j].first == cur_row[j + 1].first) {
        add_edge(cur_row[j].second, cur_row[j + 1].second);
      }
    }
  }

  for (int j = 0; j < width; j++) {
    vector<pair<int, int>> cur_col;
    for (int i = 0; i < height; i++) {
      cur_col.push_back(make_pair(table[i][j], to_idx(i, j)));
    }
    sort(cur_col.begin(), cur_col.end());

    for (int i = 0; i < height - 1; i++) {
      if (cur_col[i].first == cur_col[i + 1].first) {
        add_edge(cur_col[i].second, cur_col[i + 1].second);
      }
    }
  }

  for (int i = 0; i < height * width; i++) {
    if (comp[i] == -1) {
      dfs(i, i);
    }
  }

  vector<pair<int, int>> events; // value, comp
  for (int i = 0; i < height * width; i++) {
    if (comp[i] == i) {
      events.push_back(make_pair(table[i / width][i % width], i));
    }
  }

  sort(events.begin(), events.end());

  vector<int> maxr (height, 0);
  vector<int> maxc (width, 0);
  
  for (pair<int, int> e : events) {
    int comp_id = e.second;

    int val = 0;
    for (int u : comp_of[comp_id]) {
      val = max(val, maxr[u / width] + 1);
      val = max(val, maxc[u % width] + 1);
    }

    for (int u : comp_of[comp_id]) {
      ans[u] = val;
      maxr[u / width] = val;
      maxc[u % width] = val;
    }
  }

  /*
  for (int i = 0; i < height; i++) {
    vector<pair<int, int>> cur_row_t;
    vector<pair<int, int>> cur_row_a;
    for (int j = 0; j < width; j++) {
      cur_row_t.push_back(make_pair(table[i][j], to_idx(i, j)));
      cur_row_a.push_back(make_pair(ans[to_idx(i, j)], to_idx(i, j)));
    }
    sort(cur_row_t.begin(), cur_row_t.end());
    sort(cur_row_a.begin(), cur_row_a.end());

    for (int j = 0; j < width; j++) {
      if (cur_row_t[j].second != cur_row_a[j].second) {
        cout << "ERROR " << j << endl;
        return 1;
      }

      if (j != 0 && cur_row_t[j].first == cur_row_t[j - 1].first) {
        if (cur_row_a[j].first != cur_row_a[j - 1].first) {
          cout << "ERROR " << j << endl;
          return 1;
        }
      }

      if (j != 0 && cur_row_t[j].first != cur_row_t[j - 1].first) {
        if (cur_row_a[j].first == cur_row_a[j - 1].first) {
          cout << "ERROR " << j << endl;
          return 1;
        }
      }
    }
  }
  */
  
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << ans[to_idx(i, j)] << " ";
    }
    cout << '\n';
  }
}