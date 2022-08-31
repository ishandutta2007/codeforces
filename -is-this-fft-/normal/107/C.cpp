#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int popc (int x) {
  return __builtin_popcount(x);
}

const int MAX_N = 16;

vector<int> outgoing [MAX_N];
vector<int> incoming [MAX_N];
ll dp [1 << MAX_N];

ll n_ways (vector<int> taken) {
  int N = (int) taken.size();
  int takenc = 0;

  vector<int> isfree (N, 1);
  for (int i = 0; i < N; i++) {
    if (taken[i] != -1) {
      isfree[taken[i]] = 0;
      takenc++;
    } else {
      break;
    }
  }

  vector<int> fprofs;
  for (int i = 0; i < N; i++) {
    if (isfree[i]) {
      fprofs.push_back(i);
    }
  }

  for (int i = 0; i < 1 << N; i += 1 << takenc) {
    dp[i] = 0;
  }

  dp[0] = 1;
  for (int i = 0; i < (1 << N) - (1 << takenc); i += 1 << takenc) {
    int cur = fprofs[popc(i)]; // seat this guy
    for (int k = takenc; k < N; k++) { // at place k
      if (!(i & 1 << k)) {
        // try all constraints
        bool ok = true;
        
        for (int u : incoming[k]) {
          if (u < takenc) {
            if (taken[u] > cur) {
              ok = false;
              break;
            }
          } else if (!(i & 1 << u)) {
            // this should be filled first
            ok = false;
            break;
          }
        }        

        for (int u : outgoing[k]) {
          if (u < takenc) {
            if (taken[u] < cur) {
              ok = false;
              break;
            }
          } else if (i & 1 << u) {
            ok = false;
            break;
          }
        }

        if (ok) {
          dp[i + (1 << k)] += dp[i];
        }
      }
    }
  }

  return dp[(1 << N) - (1 << takenc)];
}

int main () {
  ios::sync_with_stdio(false);

  int vertexc, edgec;
  ll target;
  cin >> vertexc >> target >> edgec;
  target -= 2001;

  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    
    incoming[v].push_back(u);
    outgoing[u].push_back(v);
  }

  vector<int> used (vertexc, 0);
  vector<int> cur (vertexc, -1);
  if (target >= n_ways(cur)) {
    cout << "The times have changed" << endl;
    return 0;
  }

  for (int i = 0; i < vertexc; i++) {
    for (int j = 0; j < vertexc; j++) {
      if (!used[j]) {
        cur[i] = j;

        ll ws = n_ways(cur);
        
        if (target - ws < 0) {
          used[j] = 1;
          break;
        } else {
          cur[i] = -1;
          target -= ws;
        }
      }
    }
  }

  for (int i = 0; i < vertexc; i++) {
    cout << cur[i] + 1 << " ";
  }
  cout << endl;
}