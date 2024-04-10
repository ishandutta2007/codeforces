#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;

std::vector<std::vector<char>> v;
std::vector<std::vector<int>> id1, id2;

std::vector<int> g[1 + nmax], g2[1 + nmax];
int g2in[1 + nmax], gin[1 + nmax];
int start[1 + nmax], stop[1 + nmax], currptr = 0;

void dfs(int node) {
  start[node] = ++currptr;
  for(int h = 0; h < g2[node].size(); h++) {
    int to = g2[node][h];
    dfs(to);
  }
  stop[node] = currptr;
}

class SegmentTree{
private:
  std::vector<int> aint, lazy;
public:
  SegmentTree(int n = 0) {
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }

  struct Event{
    int node;
    std::pair<int,int> val;
    int timestamp;
  };
  std::stack<Event> st;

  void record(int node, int timestamp) {
    st.push({node, {aint[node], lazy[node]}, timestamp});
  }

  void cleannode(int node, int from, int to, int timestamp) {
    if(lazy[node] == 0)
      return ;

    record(node, timestamp);
    
    if(from < to) {
      int mid = (from + to) / 2;
      record(node * 2, timestamp);
      record(node * 2 + 1, timestamp);
    
      lazy[node * 2] |= lazy[node];
      lazy[node * 2 + 1] |= lazy[node];
    }

    aint[node] = (to - from + 1);
    lazy[node] = 0;
  }

  void update(int node, int from, int to, int x, int y, int timestamp) {
    record(node, timestamp);
    if(from == x && to == y) {
      lazy[node] = 1;
      cleannode(node, from, to, timestamp);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid, timestamp);
      cleannode(node * 2 + 1, mid + 1, to, timestamp);
      if(x <= mid)
        update(node * 2, from, mid, x, std::min(y, mid), timestamp);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y, timestamp);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    }

  }
  
  int query() {
    return aint[1];
  }

  void reset(int timestamp) {
    while(0 < st.size() && st.top().timestamp == timestamp) {
      aint[st.top().node] = st.top().val.first;
      lazy[st.top().node] = st.top().val.second;
      st.pop();
    }
  }
};

SegmentTree aint;

std::vector<int> req[1 + nmax];

int lim;

void solve(int node, ll &result) {
  for(int h = 0; h < req[node].size(); h++) {
    int to = req[node][h];
    aint.update(1, 1, lim, start[to], stop[to], node);
  }
  result += aint.query();

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    solve(to, result);
  }
  aint.reset(node);
  
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  v.resize(1 + n);
  for(int i = 1;i <= n; i++)
    v[i].resize(1 + m);
  
  id1.resize(1 + n);
  for(int i = 1;i <= n; i++)
    id1[i].resize(1 + m);
  
  id2.resize(1 + n);
  for(int i = 1; i <= n; i++)
    id2[i].resize(1 + m);
  
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++) {
      std::cin >> v[i][j];
    }

  int ptr1 = 0, ptr2 = 0;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      if((i + j) % 2 == 0)
        id1[i][j] = ++ptr1;
      else
        id2[i][j] = ++ptr2;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++) 
      if(v[i][j] == 'U' && i + 2 <= n) {
        if((i + j) % 2 == 0) {
          g[id1[i + 2][j]].push_back(id1[i][j]);
          gin[id1[i][j]] = 1;
        } else {
          g2[id2[i + 2][j]].push_back(id2[i][j]);
          g2in[id2[i][j]] = 1;
        }

      } else if(v[i][j] == 'L' && j + 2 <= m) {
        if((i + j) % 2 == 0) {
          g[id1[i][j + 2]].push_back(id1[i][j]);
          gin[id1[i][j]] = 1;
        } else {
          g2[id2[i][j + 2]].push_back(id2[i][j]);
          g2in[id2[i][j]] = 1;
        }
      } else if(v[i][j] == 'D' && 2 < i) {
        if((i + j) % 2 == 0) {
          g[id1[i - 2][j]].push_back(id1[i][j]);
          gin[id1[i][j]] = 1;
        } else {
          g2[id2[i - 2][j]].push_back(id2[i][j]);
          g2in[id2[i][j]] = 1;
        } 
      } else if(v[i][j] == 'R' && 2 < j) {
        if((i + j) % 2 == 0) {
          g[id1[i][j - 2]].push_back(id1[i][j]);
          gin[id1[i][j]] = 1;
        } else {
          g2[id2[i][j - 2]].push_back(id2[i][j]);
          g2in[id2[i][j]] = 1;
        }

      }

  for(int i = 1;i <= ptr2; i++)
    if(g2in[i] == 0)
      dfs(i);
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      if(v[i][j] == 'U') {
        if(0 < id1[i][j]) 
          req[id1[i][j]].push_back(id2[i + 1][j]);
        else
          req[id1[i + 1][j]].push_back(id2[i][j]);
      } else if(v[i][j] == 'L'){
        if(0 < id1[i][j]) 
          req[id1[i][j]].push_back(id2[i][j + 1]);
        else
          req[id1[i][j + 1]].push_back(id2[i][j]);
      }

  aint = SegmentTree(ptr2);
  lim = ptr2;
  ll result = 0;
  for(int i = 1;i <= ptr1; i++)
    if(gin[i] == 0)
      solve(i, result);
  std::cout << result;

  return 0;
}