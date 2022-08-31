#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

int arr [MAX_N];
int last [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    last[i] = -1;
  }

  int qc;
  cin >> qc;
  
  vector<pair<int, int>> upds;
  for (int i = 0; i < qc; i++) {
    int t;
    cin >> t;

    if (t == 1) {
      int p, x;
      cin >> p >> x;

      arr[p] = x;
      last[p] = i;

      upds.push_back(make_pair(p, x));
    } else {
      int x;
      cin >> x;

      upds.push_back(make_pair(-1, x));
    }
  }

  int mx = -1;
  for (int i = qc - 1; i >= 0; i--) {
    if (upds[i].first == -1) mx = max(mx, upds[i].second);
    else if (last[upds[i].first] == i) {
      arr[upds[i].first] = max(arr[upds[i].first], mx);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (last[i] == -1) {
      arr[i] = max(arr[i], mx);
    }
  }
  
  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  cout << '\n';
}