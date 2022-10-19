#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e4+10;
int status[maxn];
int ki = 0;
int kc = 0;

bool query(int a, int b, int c) {
  cout << "? " << a << ' ' << b << ' ' << c << endl;
  int ans;
  cin >> ans;
  if (ans == -1) exit(0);
  return ans;
}

void upd (int i, bool x) {
  status[i] = x;
  if (x) kc = i;
  else ki = i;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) status[i] = -1;
    ki = 0;
    kc = 0;
    vector<int> groups(n/3);
    vector<int> ig;
    vector<int> cg;
    for (int i = 0; i < n/3; i++) {
      groups[i] = query(3*i+1, 3*i+2, 3*i+3);
      if (groups[i]) cg.push_back(i);
      else ig.push_back(i);
    }
    int u = ig[0];
    int v = cg[0];
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
      for (int i: {3*v+1, 3*v+2, 3*v+3}) {
        if (status[i] == -1) {
          upd(i, query(3*u+1, 3*u+2, i));
        }
      }
    }
    assert(ki && kc);
    for (int i = 1; i <= n; i++) {
      if (status[i] == -1) {
        upd(i, query(ki, kc, i));
      }
    }


    cout << "! " << count(status+1, status+n+1, 0) << ' ';
    for (int i = 1; i <= n; i++) {
      if (status[i] == 0) cout << i << ' ';
    }
    cout << endl;
  }
}