#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e6 + 5;

string arr [MAX_N];

bool cmp (int u, int v) {
  const string &a = arr[u];
  const string &b = arr[v];
  for (int i = 0; i < (int) a.size(); i++) {
    if (a[i] != b[i]) {
      return (i % 2) ^ (a[i] < b[i]);
    }
  }
  return false;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> ans (n);
  for (int i = 0; i < n; i++) {
    ans[i] = i;
  }

  sort(ans.begin(), ans.end(), cmp);
  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << " ";
  }
  cout << endl;
}