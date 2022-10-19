#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

bool testing = 0;
vector<int> test = {9, 9, 16, 17, 23, 23, 23, 23, 25, 25};
const int maxn = 2e5+7;
int ans[maxn];

pii query(int a, int b) {
  cout << "? " << a << " " << b << endl;
  pii x;
  if (!testing) cin >> x.first >> x.second;
  else {
    int mode = 0;
    int maxfreq = 0;
    int cur = -1;
    int curfreq = 0;
    for (int i = a-1; i < b; i++) {
      int v = test[i];
      if (v == cur) {
        curfreq++;
      }
      else {
        cur = v;
        curfreq = 1;
      }
      if (curfreq > maxfreq) {
        mode = cur;
        maxfreq = curfreq;
      }
    }
    x = {mode, maxfreq};
  }
  return x;
}

void solve(int a, int b) {
  if (!ans[a]) ans[a] = query(a, a).first;
  if (!ans[b]) ans[b] = query(b, b).first;
  if (ans[a] == ans[b]) {
    for (int i = a+1; i < b; i++) ans[i] = ans[a];
    return;
  }
  int x, f;
  tie(x, f) = query(a, b);
  if (x == ans[a]) {
    for (int i = 1; i < f; i++) ans[a+i] = x;
    solve(a+f, b);
    return;
  }
  if (x == ans[b]) {
    for (int i = 1; i < f; i++) ans[b-i] = x;
    solve(a, b-f);
    return;
  }
  int mid = (a+b)/2;
  solve(a, mid);
  solve(mid, b);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  if (!testing) cin >> n;
  else n = test.size();
  solve(1, n);
  cout << '!';
  for (int i = 1; i <= n; i++) cout << ' ' << ans[i];
  cout << endl;
}