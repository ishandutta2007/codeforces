#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> pos;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') pos.push_back(i);
  }
  int m = pos.size();
  int l = 0;
  int r = k;
  int f = 0;
  int ans = 1e9;
  while (r < m) {
    // adjust f
    while (max(pos[r]-pos[f+1], pos[f+1]-pos[l]) < max(pos[r]-pos[f], pos[f]-pos[l])) {
      f++;
    }
    ans = min(ans, max(pos[r]-pos[f], pos[f]-pos[l]));
    r++, l++;
  }
  cout << ans << endl;
}