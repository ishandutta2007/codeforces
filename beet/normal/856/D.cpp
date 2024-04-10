#include <bits/stdc++.h>

using namespace std;
typedef long long int64;

vector< vector< int > > graph;

struct BinaryIndexedTree
{
  vector< int > data;

  BinaryIndexedTree(int sz)
  {
    data.assign(++sz, 0);
  }

  int sum(int k)
  {
    int ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, int x)
  {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

struct CentroidPathDecomposition
{
  struct Centroid
  {
    int ParIndex, ParDepth, Deep;
    vector< int > node;

    inline int size()
    {
      return (node.size());
    }

    inline int &operator[](int k)
    {
      return (node[k]);
    }

    inline pair< int, int > Up()
    {
      return (make_pair(ParIndex, ParDepth));
    }
  };

  vector< int > SubTreeSize, NextPath;
  vector< int > TreeIndex, TreeDepth;
  vector< Centroid > Centroids;

  void BuildSubTreeSize()
  {
    stack< pair< int, int > > s;
    s.push({0, -1});
    while(!s.empty()) {
      auto p = s.top();
      s.pop();
      if(~SubTreeSize[p.first]) {
        NextPath[p.first] = -1;
        for(auto &to : graph[p.first]) {
          if(p.second == to) continue;
          SubTreeSize[p.first] += SubTreeSize[to];
          if(NextPath[p.first] == -1 || SubTreeSize[NextPath[p.first]] < SubTreeSize[to]) {
            NextPath[p.first] = to;
          }
        }
      } else {
        s.push(p);
        SubTreeSize[p.first] = 1;
        for(auto &to : graph[p.first]) {
          if(p.second != to) s.push({to, p.first});
        }
      }
    }
  }

  void BuildPath()
  {
    stack< pair< int, int > > s;
    Centroids.push_back((Centroid) {-1, -1, 0});
    s.push({0, -1});
    TreeIndex[0] = 0;
    while(!s.empty()) {
      auto p = s.top();
      s.pop();
      TreeDepth[p.first] = Centroids[TreeIndex[p.first]].size();
      for(auto &to : graph[p.first]) {
        if(p.second != to) {
          if(to == NextPath[p.first]) { // Centroid-Path
            TreeIndex[to] = TreeIndex[p.first];
          } else {                  // Not Centroid-Path
            TreeIndex[to] = Centroids.size();
            Centroids.push_back((Centroid) {TreeIndex[p.first], TreeDepth[p.first], Centroids[TreeIndex[p.first]].Deep + 1});
          }
          s.push({to, p.first});
        }
      }
      Centroids[TreeIndex[p.first]].node.push_back(p.first);
    }
  }

  void AddEdge(int x, int y)
  {
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  void Build()
  {
    BuildSubTreeSize();
    BuildPath();
  }

  inline int size()
  {
    return (Centroids.size());
  }

  inline pair< int, int > Information(int idx)
  {
    return (make_pair(TreeIndex[idx], TreeDepth[idx]));
  }

  inline Centroid &operator[](int k)
  {
    return (Centroids[k]);
  }

  inline pair< int, int > LCAandLength(int a, int b)
  {
    int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
    int length = 0;
    tie(TreeIdxA, TreeDepthA) = Information(a);
    tie(TreeIdxB, TreeDepthB) = Information(b);
    while(TreeIdxA != TreeIdxB) {
      if(Centroids[TreeIdxA].Deep > Centroids[TreeIdxB].Deep) {
        length += TreeDepthA + 1;
        tie(TreeIdxA, TreeDepthA) = Centroids[TreeIdxA].Up();
      } else {
        length += TreeDepthB + 1;
        tie(TreeIdxB, TreeDepthB) = Centroids[TreeIdxB].Up();
      }
    }
    if(TreeDepthA > TreeDepthB) swap(TreeDepthA, TreeDepthB);
    length += TreeDepthB - TreeDepthA + 1;
    return {Centroids[TreeIdxA][TreeDepthA], length};
  }

  CentroidPathDecomposition(int SZ)
  {
    graph.resize(SZ);
    SubTreeSize.assign(SZ, -1);
    NextPath.resize(SZ);
    TreeIndex.resize(SZ);
    TreeDepth.resize(SZ);
  }
};

int N, M, A[200000], B[200000], C[200000];
vector< int > edges[200000];
CentroidPathDecomposition tree(200000);
vector< BinaryIndexedTree > dp1, dp2;

int pathSum(int a, int b)
{
  int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
  tie(TreeIdxA, TreeDepthA) = tree.Information(a);
  tie(TreeIdxB, TreeDepthB) = tree.Information(b);
  int ret = 0;
  while(TreeIdxA != TreeIdxB) {
    if(tree[TreeIdxA].Deep > tree[TreeIdxB].Deep) {
      ret += dp2[TreeIdxA].sum(TreeDepthA + 1) - dp1[TreeIdxA].sum(TreeDepthA + 1);
      tie(TreeIdxA, TreeDepthA) = tree[TreeIdxA].Up();
    } else {
      ret += dp2[TreeIdxB].sum(TreeDepthB + 1) - dp1[TreeIdxB].sum(TreeDepthB + 1);
      tie(TreeIdxB, TreeDepthB) = tree[TreeIdxB].Up();
    }
  }
  if(TreeDepthA > TreeDepthB) swap(TreeDepthA, TreeDepthB);
  ret += dp2[TreeIdxA].sum(TreeDepthB + 1) - dp2[TreeIdxA].sum(TreeDepthA - 1) - dp1[TreeIdxA].sum(TreeDepthB + 1) + dp1[TreeIdxA].sum(TreeDepthA - 1);
  return (ret);
}

int rec(int idx, int prev)
{
  int ret1 = 0, ret2 = 0;
  int treeIdx, treeDepth;
  tie(treeIdx, treeDepth) = tree.Information(idx);

  for(int to : graph[idx]) {
    if(to == prev) continue;
    ret2 += rec(to, idx);
  }
  dp2[treeIdx].add(treeDepth + 1, ret2);
  ret1 = ret2;
  for(int query : edges[idx]) {
    ret1 = max(ret1, C[query] + pathSum(A[query], B[query]));
  }
  dp1[treeIdx].add(treeDepth + 1, ret1);
  return (ret1);
}

int main()
{
  scanf("%d %d", &N, &M);
  for(int i = 1; i < N; i++) {
    int x;
    scanf("%d", &x);
    tree.AddEdge(--x, i);
  }
  tree.Build();
  for(int i = 0; i < tree.size(); i++) {
    dp1.push_back(BinaryIndexedTree(tree[i].size() + 1));
    dp2.push_back(BinaryIndexedTree(tree[i].size() + 1));
  }
  for(int i = 0; i < M; i++) {
    scanf("%d %d %d", &A[i], &B[i], &C[i]);
    auto get = tree.LCAandLength(--A[i], --B[i]);
    edges[get.first].push_back(i);
  }
  printf("%d\n", rec(0, -1));
}