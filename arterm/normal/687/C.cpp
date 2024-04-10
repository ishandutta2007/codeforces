#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 507;

bitset<M> d[M];

int n, k;

void add(int x) {
  for (int a = M - 1; a >= 0; --a) {
    int b = a + x;
    if (b < M)
      d[b] |= d[a];
    d[a] |= (d[a] << x);
  }
}

void read() {
  cin >> n >> k;
  d[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    add(x);
  }
}


void kill() {
  vector<int> ans;
  for (int a = 0; a <= k; ++a)
    if (d[a][k - a])
      ans.push_back(a);

  cout << ans.size() << endl;
  for (int x : ans)
    cout << x << " ";
  cout << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}