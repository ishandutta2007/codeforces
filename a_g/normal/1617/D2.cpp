#include <bits/stdc++.h>
using namespace std;

bool testing = 0;
vector<int> test = {1, 0, 1, 1, 0, 1, 0, 0, 1};
const int maxn = 1e4+10;
int status[maxn];
int n;
int ki;
int kc;

bool query(int a, int b, int c) {
  cout << "? " << a << ' ' << b << ' ' << c << endl;
  assert(a > 0 && b > 0 && c > 0 && a != b && b != c && c != a);
  int ans;
  cin >> ans;
  if (testing) {
    return (test[a-1]+test[b-1]+test[c-1] >= 2);
  }
  if (ans == -1) exit(0);
  return ans;
}

void upd (int i, bool x) {
  if (status[i] != -1) return;
  status[i] = x;
  if (x) kc = i;
  else ki = i;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    if (!testing) cin >> n;
    else n = test.size();
    for (int i = 1; i <= n; i++) status[i] = -1;
    ki = 0;
    kc = 0;

    vector<bool> groups(n/3);
    int u, v;
    for (int i = 0; i < n/3; i++) {
      groups[i] = query(3*i+1, 3*i+2, 3*i+3);
      if (groups[i]) v = i;
      else u = i;
    }
    assert(u != v);

    bool x = query(3*u+1, 3*u+2, 3*v+1);
    bool y = query(3*u+1, 3*u+2, 3*v+2);
    if (x == 0 && y == 0) {
      upd(3*u+1, 0);
      upd(3*u+2, 0);
      if (query(3*v+1, 3*v+2, 3*u+1)) {
        upd(3*v+1, 1);
        upd(3*v+2, 1);
      }
      else {
        upd(3*v+3, 1);
      }
    }
    else if (x == 1 && y == 1) {
      upd(3*v+1, 1);
      upd(3*v+2, 1);
      upd(3*u+3, 0);
    }
    else {
      upd(3*u+3, 0);
      upd(3*v+1, x);
      upd(3*v+2, y);
    }
    assert(ki != 0 && kc != 0);
    for (int i: {3*u+1, 3*u+2, 3*u+3, 3*v+1, 3*v+2, 3*v+3}) {
      if (status[i] == -1) {
        status[i] = query(ki, kc, i);
      }
    }

    for (int j = 0; j < n/3; j++) {
      if (j == u || j == v) continue;
      bool x = groups[j];
      int third = (x ? ki : kc);
      bool y = query(3*j+1, 3*j+2, third);
      if (y != x) {
        status[3*j+3] = x;
        status[3*j+1] = query(ki, kc, 3*j+1);
        status[3*j+2] = 1-status[3*j+1];
      }
      else {
        status[3*j+1] = x;
        status[3*j+2] = x;
        status[3*j+3] = query(ki, kc, 3*j+3);
      }
    }
    for (int i = 1; i <= n; i++) assert(status[i] != -1);


    cout << "! " << count(status+1, status+n+1, 0) << ' ';
    for (int i = 1; i <= n; i++) {
      if (status[i] == 0) cout << i << ' ';
    }
    cout << endl;
  }
}