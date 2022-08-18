#include <iostream>
#include <set>

using namespace std;

void solve (int aw, int bw, int as, int bs, set<int> &out) {
  int aa = min(aw, as);
  int bb = min(bw, bs);
  int ab = max(0, as - aa);
  int ba = max(0, bs - bb);

  int cross = ab + ba;
  out.insert(cross);
  while (aa > 0 && bb > 0) {
    cross += 2;
    aa--;
    bb--;
    out.insert(cross);
  }
}

void solve () {
  int a, b;
  cin >> a >> b;

  set<int> ans;
  solve(a, b, (a + b + 1) / 2, (a + b) / 2, ans);
  solve(a, b, (a + b) / 2, (a + b + 1) / 2, ans);

  cout << (int) ans.size() << '\n';
  for (int u : ans) {
    cout << u << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}