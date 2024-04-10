#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 300300;

vector<int> g[M];
int f[M];

void add(int at, int x) {
  for (int i = at; i < M; i |= (i + 1)) {
    f[i] += x;
  }
}

int get(int r) {
  int ans = 0;
  for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
    ans += f[i];
  return ans;
}

int n, q;

void kill() {
  cin >> n >> q;
  int m = 0;
  int l = 0;
  for (int i = 0; i < q; ++i) {
    int t;
    cin >> t;

    if (t == 1) {
      int x;
      cin >> x;

      g[x].push_back(m);
      add(m, 1);

      ++m;
    }

    if (t == 2) {
      int x;
      cin >> x;

      for (int k : g[x]) 
        add(k, -1);
      g[x].clear();
    }

    if (t == 3) {
      int d;
      cin >> d;
      
      l = max(l, d);
    }

    cout << get(m - 1) - get(l - 1) << endl;
  }
}
      
int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  kill();
}