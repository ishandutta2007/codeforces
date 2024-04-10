#include <bits/stdc++.h>
using namespace std;

const int N = 7005;
vector<int> divisors[N];
int mu[N];
using mset = bitset<N>;
const int M = 1e5+2;
mset a[M];
mset mask[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  mu[1] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      divisors[j].push_back(i);
      if (j > i) mu[j] -= mu[i];
    }
  }
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      if (mu[j/i]) mask[i][j] = 1;
    }
  }

  int n, q;
  cin >> n >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, v;
      cin >> x >> v;
      a[x].reset();
      for (int j: divisors[v]) {
        a[x][j] = 1;
      }
    }
    else if (t == 2) {
      int x, y, z;
      cin >> x >> y >> z;
      a[x] = a[y]^a[z];
    }
    else if (t == 3) {
      int x, y, z;
      cin >> x >> y >> z;
      a[x] = a[y]&a[z];
    }
    else {
      assert(t==4);
      int x, v;
      cin >> x >> v;
      cout << ((a[x]&mask[v]).count()&1);
    }
  }
  cout << '\n';
}