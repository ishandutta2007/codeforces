#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<vector<int>> ans;
int f[N], pre[N], b[N];
bool take[N];

void solve(vector<int>& a) {
  vector<int> lis;
  int n = a.size();
  for (int x: a) {
    auto it = lower_bound(lis.begin(), lis.end(), x);
    if (it != lis.begin()) {
      pre[x] = *(it-1);
    }
    else {
      pre[x] = 0;
    }
    if (it == lis.end()) {
      b[x] = lis.size()+1;
      lis.push_back(x);
    }
    else {
      b[x] = it-lis.begin()+1;
      *it = x;
    }
  }

  int e = 0;
  for (int x: a) {
    if (f[n-b[x]] < f[n]) {
      e = x;
      break;
    }
  }
  if (e) {
    vector<int> seq(1, e);
    take[e] = 1;
    while (pre[seq.back()]) {
      take[pre[seq.back()]] = 1;
      seq.push_back(pre[seq.back()]);
    }
    reverse(seq.begin(), seq.end());
    ans.push_back(seq);
    vector<int> newa;
    for (int x: a) {
      if (!take[x]) newa.push_back(x);
    }
    solve(newa);
    return;
  }

  int mx = 0;
  for (int x: a) {
    mx = max(mx, b[x]);
  }
  int z = ans.size();
  ans.resize(z+mx);
  for (int x: a) {
    ans[z+b[x]-1].push_back(x);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int k = 1; k*(k+1)/2 < N; k++) {
    f[k*(k+1)/2] = k;
  }
  for (int i = 1; i < N; i++) {
    if (!f[i]) f[i] = f[i-1];
  }

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;

    solve(a);

    cout << ans.size() << '\n';
    for (vector<int>& seq: ans) {
      cout << seq.size();
      for (int m: seq) {
        cout << " " << m;
      }
      cout << '\n';
    }
    ans.clear();
    fill(take+1, take+n+1, 0);
  }
}