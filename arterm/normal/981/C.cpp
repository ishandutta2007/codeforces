#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 100100;

int n;
int d[M];

void read() {
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    d[u]++;
    d[v]++;
  }
}

void kill() {
  vector<int> one;
  vector<int> many;
  for (int v = 0; v < n; ++v) {
    if (d[v] == 1)
      one.push_back(v);
    if (d[v] > 2)
      many.push_back(v);
  }

  if (many.size() >= 2) {
    cout << "No\n";
    return;
  }

  if (many.size() == 0) {
    assert(one.size() == 2);
    cout << "Yes\n1\n";
    cout << one[0] + 1 << " " << one[1] + 1 << endl;
    return;
  }

  int w = one.size();
  cout << "Yes\n";
  cout << w << endl;
  for (int i = 0; i < w; ++i) {
    cout << one[i] + 1 << " " << many[0] + 1 << "\n";
  }
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}