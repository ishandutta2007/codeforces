#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5+7;
int n;
bool known[maxn];
bool queried[maxn];
int a[maxn];
bool will_terminate[maxn];
ll diff[maxn];

void solve(int x) {
  if (known[x]) return;
  if (queried[x]) {
    // infinite loop
    will_terminate[x] = 0;
    known[x] = 1;
    return;
  }
  queried[x] = 1;
  ll d = a[x];
  int x2 = x + a[x];
  if (x2 <= 0 || x2 > n) {
    will_terminate[x] = 1;
    diff[x] = d;
    known[x] = 1;
    return;
  }
  int x3 = x2-a[x2];
  d += a[x2];
  if (x3 <= 0 || x3 > n) {
    will_terminate[x] = 1;
    diff[x] = d;
    known[x] = 1;
    return;
  }
  solve(x3);
  if (!will_terminate[x3]) {
    will_terminate[x] = 0;
    known[x] = 1;
    return;
  }
  else {
    will_terminate[x] = 1;
    known[x] = 1;
    diff[x] = d + diff[x3];
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 2; i <= n; i++) cin >> a[i];
  for (int i = 2; i <= n; i++) solve(i);
  known[1] = 1;
  queried[1] = 1;
  will_terminate[1] = 0;
  /*
  for (int i = 1; i <= n; i++) {
    cout << i << " " << known[i] << " " << queried[i] << " " << a[i] << " " <<
      will_terminate[i] << " " << diff[i] << endl;
  }
  */
  for (int i = 1; i <= n-1; i++) {
    int x2 = 1+i;
    ll d = i;
    int x3 = x2-a[x2];
    d += a[x2];
    if (x3 <= 0 || x3 > n) {
      cout << d << '\n';
    }
    else if (x3 == 1) {
      cout << -1 << '\n';
    }
    else {
      if (!will_terminate[x3]) {
        cout << -1 << '\n';
      }
      else {
        cout << d + diff[x3] << '\n';
      }
    }
  }
}