#include <iostream>
#include <vector>
#include <algorithm>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((b) < (a)) ? (b) : (a))
using ll = long long;
int const nmax = 100000;
ll const inf = 1000000000000000;

struct Line{
  ll a;
  ll b;
  ll eval(int x){
    return a * x + b;
  }
};

namespace LiChao{
  struct Node{
    Line val;
    Node* left;
    Node* right;
    Node(Line val_ = {0, 0}){
      val = val_;
      left = right = NULL;
    }
  };
  void update(Node* &root, int from, int to, Line val){
    if(root == NULL)
      root = new Node(val);
    else {
      int mid = (from + to) / 2;
      if(val.eval(mid) < root->val.eval(mid))
        std::swap(root->val, val);
      if(val.eval(from) < root->val.eval(from))
        update(root->left, from, mid, val);
      if(val.eval(to) < root->val.eval(to))
        update(root->right, mid + 1, to, val);
    }
  }
  ll query(Node* &root, int from, int to, int x){
    if(root == NULL)
      return inf;
    else {
      int mid = (from + to) / 2;
      if(x <= mid)
        return std::min(query(root->left, from, mid, x), root->val.eval(x));
      else
        return std::min(query(root->right, mid + 1, to, x), root->val.eval(x));
    }
  }
}

LiChao::Node* myset[1 + nmax];
std::vector<Line> equats[1 + nmax];
std::vector<int> g[1 + nmax];

void addto(int node, int sub){
  if(equats[node].size() < equats[sub].size()) {
    std::swap(equats[node], equats[sub]);
    std::swap(myset[node], myset[sub]);
  }
  for(int h = 0; h < equats[sub].size(); h++){
    Line lin = equats[sub][h];
    LiChao::update(myset[node], -nmax, nmax, lin);
    equats[node].push_back(lin);
  }
}

void addline(int node, Line lin){
  equats[node].push_back(lin);
  update(myset[node], -nmax, nmax, lin);
}

int a[1 + nmax], b[1 + nmax];
ll dp[1 + nmax];

void dfs(int node, int parent){
  int leaf = true;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent){
      dfs(to, node);
      addto(node, to);
      leaf = false;
    }
  }
  if(leaf == true)
    dp[node] = 0;
  else
    dp[node] = query(myset[node], -nmax, nmax, a[node]);
  addline(node, {b[node], dp[node]});
}

int main()
{
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> a[i];
  for(int i = 1;i <= n; i++)
    std::cin >> b[i];
  for(int i = 1;i < n; i++){
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  for(int i = 1;i <= n; i++)
    std::cout << dp[i] << " " ;
  return 0;
}