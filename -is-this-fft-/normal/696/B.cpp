#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int MAX_N = 1e5 + 5;

double ans [MAX_N];
int subsz [MAX_N];
int par [MAX_N];
vector<int> adj [MAX_N];

void calc_sz (int u) {
  subsz[u] = 1;
  for (int nxt : adj[u]) {
    calc_sz(nxt);
    subsz[u] += subsz[nxt];
  }
}

void calc_ans (int u) {
  if (u == 1) {
    ans[u] = 1;
  } else {
    int oths = subsz[par[u]] - subsz[u] - 1;
    ans[u] = ans[par[u]] + (double) oths / 2 + 1;
  }

  for (int nxt : adj[u]) {
    calc_ans(nxt);
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 2; i <= n; i++) {
    cin >> par[i];
    adj[par[i]].push_back(i);
  }

  calc_sz(1);
  calc_ans(1);
  
  for (int i = 1; i <= n; i++) {
    cout << fixed << setprecision(12) << ans[i] << " ";
  }
  cout << endl;
}