#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 3e5 + 5;
const int MAX_K = 8;

int arr [MAX_N][MAX_K];
int exists [1 << MAX_K];
int cur [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<pair<int, pair<int, int>>> elems;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      elems.push_back({arr[i][j], {i, j}});
    }
  }
  
  sort(elems.begin(), elems.end());
  reverse(elems.begin(), elems.end());

  for (int i = 0; i < 1 << m; i++) {
    exists[i] = -1;
  }

  for (auto e : elems) {
    int r = e.second.first;
    int c = e.second.second;

    cur[r] |= 1 << c;
    exists[cur[r]] = r;
    for (int i = 0; i < 1 << m; i++) {
      if ((i | cur[r]) == (1 << m) - 1) {
        if (exists[i] != -1) {
          cout << r + 1 << " " << exists[i] + 1 << endl;
          return 0;
        }
      }
    }
  }
}