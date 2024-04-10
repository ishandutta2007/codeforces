#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<int> arr (n + 1);
  vector<int> pos (n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    pos[arr[i]] = i;
  }

  set<int> taken;
  taken.insert(n + 1);
  
  int nxt = -1;
  for (int i = 1; i <= n; i++) {
    if (pos[i] != nxt && nxt != -1) {
      cout << "No" << '\n';
      return;
    }

    taken.insert(pos[i]);
    nxt = pos[i] + 1;
    if (taken.count(nxt)) nxt = -1;
  }
  cout << "Yes" << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}