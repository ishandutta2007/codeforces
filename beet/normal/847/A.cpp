#include <bits/stdc++.h>

using namespace std;

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k)
  {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k)
  {
    return (-data[find(k)]);
  }
};

struct edge
{
  int u, v, cost;

  bool operator<(const edge &e) const
  {
    return (cost < e.cost);
  };
};

int N, L[100], R[100];
int root;

void dfs(int idx)
{
  if(R[idx] != -1) {
    dfs(R[idx]);
  } else {
    for(int i = 0; i < N; i++) {
      if(root == i) continue;
      if(L[i] == -1) {
        L[i] = idx;
        R[idx] = i;
        dfs(i);
        return;
      }
    }
  }
}

int main()
{
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
    --L[i], --R[i];
  }

  for(int i = 0; i < N; i++) {
    if(L[i] == -1) {
      root = i;
      dfs(i);
      break;
    }
  }

  for(int i = 0; i < N; i++) {
    cout << L[i] + 1 << " " << R[i] + 1 << endl;
  }

}