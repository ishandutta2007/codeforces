#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
int chosen [MAX_N];
int cnt [MAX_N];

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    
    adj[i] = vector<int> (k);
    for (int j = 0; j < k; j++) {
      cin >> adj[i][j];
    }

    chosen[i] = adj[i][0];
  }

  for (int i = 1; i <= n; i++) {
    cnt[i] = 0;
  }

  for (int i = 0; i < m; i++) {
    cnt[chosen[i]]++;
  }

  pair<int, int> dom = make_pair(0, 0); // <frequency, index>
  for (int i = 1; i <= n; i++) {
    dom = max(dom, make_pair(cnt[i], i));
  }

  int max_same = (m + 1) / 2;
  for (int i = 0; i < m; i++) {
    if (chosen[i] == dom.second &&
        dom.first > max_same &&
        (int) adj[i].size() > 1) {
      dom.first--;
      chosen[i] = adj[i][1];
    }
  }

  if (dom.first > max_same) {
    cout << "NO" << '\n';
    return;
  }

  cout << "YES" << '\n';
  for (int i = 0; i < m; i++) {
    cout << chosen[i] << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}