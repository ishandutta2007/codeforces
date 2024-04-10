#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

int par [MAX_N];
int lvl [MAX_N];
int S [MAX_N];
int A [MAX_N];
vector<int> adj [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int vertexc;
  cin >> vertexc;

  lvl[1] = 1;
  for (int i = 2; i <= vertexc; i++) {
    cin >> par[i];
    lvl[i] = lvl[par[i]] + 1;
    adj[par[i]].push_back(i);
  }

  for (int i = 1; i <= vertexc; i++) {
    cin >> S[i];
  }

  A[1] = S[1];
  for (int i = 2; i <= vertexc; i++) {
    if (lvl[i] % 2 == 0 && S[i] != -1) {
      cout << -1 << endl;
      return 0;
    }

    if (lvl[i] % 2 != 0 && S[i] == -1) {
      cout << -1 << endl;
      return 0;
    }

    if (lvl[i] % 2 != 0) {
      A[i] = S[i] - S[par[par[i]]];
      if (A[i] < 0) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  for (int i = 2; i <= vertexc; i++) {
    if (lvl[i] % 2 == 0) {
      A[i] = 1 << 30;
      if (adj[i].empty()) {
        A[i] = 0;
      }
      
      for (int nxt : adj[i]) {
        A[i] = min(A[i], A[nxt]);
      }

      for (int nxt : adj[i]) {
        A[nxt] -= A[i];
      }
    }
  }

  long long ans = 0;
  for (int i = 1; i <= vertexc; i++) {
    ans += A[i];
  }
  cout << ans << endl;
}