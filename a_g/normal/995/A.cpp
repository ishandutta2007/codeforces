#include <bits/stdc++.h>
using namespace std;

int n;

pair<int, int> carcoord(int i) {
  i %= 2*n;
  if (i < n) return {2, i+1};
  else return {3, 2*n-i};
}

pair<int, int> spotcoord(int i) {
  i %= 2*n;
  if (i < n) return {1, i+1};
  else return {4, 2*n-i};
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int k;
  cin >> n >> k;
  vector<tuple<int, int, int>> ops;
  vector<int> spots(2*n);
  vector<int> cars(2*n);
  for (int i = 0; i < n; i++) {
    cin >> spots[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> cars[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> cars[2*n-1-i];
  }
  for (int i = 0; i < n; i++) {
    cin >> spots[2*n-1-i];
  }

  while (k) {
    for (int i = 0; i < 2*n; i++) {
      if (spots[i] && spots[i] == cars[i]) {
        ops.push_back({spots[i], spotcoord(i).first, spotcoord(i).second});
        k--;
        cars[i] = 0;
      }
    }
    if (!k) break;
    if (k == 2*n) {
      cout << "-1\n";
      return 0;
    }
    int free;
    for (int i = 0; i < 2*n; i++) {
      if (!cars[i]) free = i;
    }
    for (int i = 1; i <= 2*n; i++) {
      int u = (2*n+free-i)%(2*n);
      if (cars[u]) {
        ops.push_back({cars[u], carcoord(u+1).first, carcoord(u+1).second});
      }
    }
    rotate(cars.begin(), cars.end()-1, cars.end());
  }

  cout << ops.size() << '\n';
  for (tuple<int, int, int> op: ops) {
    cout << get<0>(op) << " " << get<1>(op) << " " << get<2>(op) << '\n';
  }

}