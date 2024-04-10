#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e2 + 5;

int N, M;
int sight[MAXN * MAXN];
int arr[MAXN][MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N * M; i++)
    scanf("%d", sight + i);
}

int solve() {
  map <int, vector <int>> groups;
  for (int i = 0; i < N * M; i++)
    groups[sight[i]].push_back(i);
  int row = 0, col = 0;
  for (auto it : groups) {
    vector <int> curr = it.second;
    sort(curr.begin(), curr.end());
    int sz = curr.size();
    if (col + sz <= M) 
      reverse(curr.begin(), curr.end());
    else {
      int rest = (col + sz) % M;
      reverse(curr.begin(), curr.begin() + M - col);
      reverse(curr.begin() + M - col, curr.begin() + sz - rest);
      reverse(curr.begin() + sz - rest, curr.end());
    }
    for (auto elem : curr) {
      arr[row][col++] = elem;
      if (col == M) {
        col = 0;
        row++;
      }
    }
  }
  int sol = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      for (int k = 0; k < j; k++)
        sol += arr[i][k] < arr[i][j];
  return sol;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%d\n", solve());
  }
  return 0;
}