#include <bits/stdc++.h>

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> ans;
  for (int i = 0; (1 << i) <= n; ++i)
    if ((n >> i) & 1)
      ans.push_back(i + 1);
  reverse(ans.begin(), ans.end());
  for (int x : ans)
    cout << x << " ";
  cout << endl;
}