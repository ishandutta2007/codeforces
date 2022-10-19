#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n;
bool on[N];

int f(int n, int k) {
  return n-(n+k-1)/k-(k-1);
}

void op(vector<int> a) {
  cout << a.size();
  for (int x: a) {
    cout << ' ' << x;
    on[x] = 1;
  }
  cout << endl;
  int x;
  cin >> x;
  for (int i = 0; i < a.size(); i++) {
    int l = x+i;
    if (l > n) l -= n;
    on[l] = 0;
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  int best = 0;
  int bestk = 0;
  for (int k = 1; k <= n; k++) {
    if (f(n, k) > best) {
      bestk = k;
      best = f(n, k);
    }
  }
  vector<int> t;
  for (int i = 1; i < n; i++) {
    if (bestk && i%bestk != 0) {
      t.push_back(i);
    }
  }
  while (accumulate(on+1, on+n+1, 0) < best) {
    vector<int> a;
    for (int z: t) {
      if (!on[z]) a.push_back(z);
      if (a.size() == bestk) break;
    }
    op(a);
  }
  cout << 0 << endl;
}