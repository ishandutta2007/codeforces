#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 1e6 + 5;

int root [MAX_N];
int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  root[u] = v;
}

int longest [MAX_N];
vector<int> poss [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  string s;
  cin >> s;

  for (int i = 0; i <= n; i++) {
    root[i] = i;
  }
  
  int last0 = -1;
  int last1 = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      longest[i] = i - min(last0, last1);
    } else if (s[i] == '0') {
      longest[i] = i - last1;
      last0 = i;
    } else if (s[i] == '1') {
      longest[i] = i - last0;
      last1 = i;
    }

    poss[longest[i]].push_back(i);
  }

  ll lccs = 0;
  for (int i = 1; i <= n; i++) {
    int ans = 0, pos = -1;
    while (pos + i < n) {
      pos = find(pos + i);
      if (pos >= n) break;
      ans++;
    }

    for (int idx : poss[i]) {
      merge(idx, idx + 1);
    }

    cout << ans << " ";
  }
  cout << endl;
}