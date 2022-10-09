#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
vector<int> g[1 + nmax];
int v[1 + nmax];

class SegmentTree{
public:
  int n;
  vector<int> aint;
  SegmentTree(int n){
    this->n = n;
    aint.resize(4 * n);
  }
  void update(int node,int from, int to, int x, int y, int val){
    if(from == x && to == y)
      aint[node] += val;
    else {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, MIN(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
    }
  }
  int query(int node,int from, int to, int x){
    if(from == to)
      return aint[node];
    else{
      int mid = (from + to) / 2;
      if(x <= mid)
        return aint[node] + query(node * 2, from, mid, x);
      else
        return aint[node] + query(node * 2 + 1, mid + 1, to, x);
    }
  }
};

int level[1 + nmax];
int pos[1 + nmax], posp = 0;
int endp[1 + nmax];

void dfs(int node, int parent){
  level[node] = level[parent] + 1;
  pos[node] = ++posp;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      dfs(to, node);
  }
  endp[node] = posp;
}

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  SegmentTree ainteven(n), aintodd(n);

  for(int i = 1;i <= n; i++)
    if(level[i] % 2 == 0)
      ainteven.update(1, 1, n, pos[i], pos[i], v[i]);
    else
      aintodd.update(1, 1, n, pos[i], pos[i], v[i]);

  for(int i = 1;i <= m; i++){
    int op;
    cin >> op;
    if(op == 1){
      int x, val;
      cin >> x >> val;
      if(level[x] % 2 == 1)
        val = -val;
      ainteven.update(1, 1, n, pos[x], endp[x], val);
      aintodd.update(1, 1, n, pos[x], endp[x], -val);
    } else{
      int x;
      cin >> x;
      if(level[x] % 2 == 0)
        cout << ainteven.query(1, 1, n, pos[x]) << '\n';
      else
        cout << aintodd.query(1, 1, n, pos[x]) << '\n';
    }
  }

  return 0;
}