#include <bits/stdc++.h>

using namespace std;

#define free sdlkfla

const int M = 100100;

int n, m;

struct Edge {
  int id, w;
  bool taken;

  void read() {
    cin >> w >> taken;
  }

  bool operator < (const Edge &to) const {
    if (w != to.w)
      return w < to.w;
    if (taken != to.taken)
      return taken;
    return id < to.id;
  }
} e[M];

vector<pair<int, int>> free;
pair<int, int> ans[M];

void add(int v) {
  for (int i = 2; i < v && free.size() < M; ++i)
    free.emplace_back(i, v);
}

void read() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    e[i].id = i;
    e[i].read();
  }
  sort(e, e + m);

  
}


void kill() {
  int v = 2;
  for (int i = 0; i < m; ++i) {
    auto e = ::e[i];
    if (e.taken) {
      ans[e.id] = make_pair(1, v);
      add(v);
      ++v;
    } else { 
      if (free.empty()) {
        cout << "-1\n";
        exit(0);
      } else {
        ans[e.id] = free.back();
        free.pop_back();
      }
    }
  }

  for (int i = 0; i < m; ++i)
    cout << ans[i].first << " " << ans[i].second << "\n";
}


int main() {
  ios_base::sync_with_stdio(false);
  read();
  kill();
  return 0;
}