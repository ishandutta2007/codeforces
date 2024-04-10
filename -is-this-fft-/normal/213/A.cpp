#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 205;

int n;
int loc [MAX_N];
vector<int> out [MAX_N];

int cnt_in [MAX_N];
vector<int> cur_src [3];

void proc (int u) {
  for (int v : out[u]) {
    cnt_in[v]--;
    if (cnt_in[v] == 0) {
      cur_src[loc[v]].push_back(v);
    }
  }
}

int solve (int cur) {
  for (int i = 1; i <= n; i++) {
    cnt_in[i] = 0;
  }

  for (int k = 0; k < 3; k++) {
    cur_src[k].clear();
  }

  for (int i = 1; i <= n; i++) {
    for (int v : out[i]) {
      cnt_in[v]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (cnt_in[i] == 0) {
      cur_src[loc[i]].push_back(i);
    }
  }

  int ans = 0;
  while (!cur_src[0].empty() || !cur_src[1].empty() || !cur_src[2].empty()) {
    ans++;
    while (!cur_src[cur].empty()) {
      int u = cur_src[cur].back();
      cur_src[cur].pop_back();
      proc(u);
    }
    
    cur += 1;
    cur %= 3;
  }

  return ans - 1;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> loc[i];
    loc[i]--;
  }

  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;

    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;

      out[v].push_back(i);
    }
  }

  cout << n + min(solve(0), min(solve(1), solve(2))) << endl;
}