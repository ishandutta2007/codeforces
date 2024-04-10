#include <iostream>

using namespace std;

typedef long long ll;

const ll INF = 1e16;
const int MAX_N = 4e5 + 5;
const int MAX_LG = 20;

int jmp [MAX_N][MAX_LG];
int lvl [MAX_N];
ll weight [MAX_N];
ll potent [MAX_N];

void add (int u, int p, ll w) {
  weight[u] = w;
  potent[u] = weight[u] + potent[p];
  jmp[u][0] = p;
  lvl[u] = lvl[p] + 1;
  for (int i = 1; i < MAX_LG; i++) {
    jmp[u][i] = jmp[jmp[u][i - 1]][i - 1];
  }
}

int find_true_parent (int u, ll w) {
  // lowest ancestor with higher weight
  if (weight[u] >= w) return u;

  for (int k = MAX_LG - 1; k >= 0; k--) {
    if (weight[jmp[u][k]] < w) {
      u = jmp[u][k];
    }
  }
  return jmp[u][0];
}

int find_longest_seq (int u, ll X) {
  int ans = 0;
  ll min_pot = potent[u] - X;
  if (potent[0] >= min_pot) {
    return lvl[u];
  }
  
  for (int k = MAX_LG - 1; k >= 0; k--) {
    if (potent[jmp[u][k]] >= min_pot) {
      ans += 1 << k;
      u = jmp[u][k];
    }
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  
  weight[0] = INF;
  potent[0] = INF;
  add(1, find_true_parent(0, 0), 0);
  
  int vc = 1;

  int qc;
  cin >> qc;

  ll last = 0;
  for (int i = 0; i < qc; i++) {
    int op;
    ll p, q;
    cin >> op >> p >> q;
    p ^= last; q ^= last;

    if (op == 1) {
      vc++;
      add(vc, find_true_parent(p, q), q);
    } else {
      int ans = find_longest_seq(p, q);
      last = ans;
      cout << ans << '\n';
    }
  }
}