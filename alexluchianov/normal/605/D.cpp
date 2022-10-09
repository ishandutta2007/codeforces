#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <map>
#include <queue>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
int const nmax = 100000;
int const inf = 1000000000;

int a[1 + nmax], b[1 + nmax], c[1 + nmax], d[1 + nmax];

void normalize(int n){
  vector<int> temp;
  map<int,int> code;
  temp.push_back(0);
  for(int i = 1; i <= n; i++){
    temp.push_back(a[i]);
    temp.push_back(b[i]);
    temp.push_back(c[i]);
    temp.push_back(d[i]);
  }
  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());
  for(int i = 0; i < temp.size(); i++)
    code[temp[i]] = i;

  for(int i = 1;i <= n; i++){
    a[i] = code[a[i]];
    b[i] = code[b[i]];
    c[i] = code[c[i]];
    d[i] = code[d[i]];
  }
}

/*
update on position
query minimum on segment and its position
*/
class SegmentTree{
private:
  vector<pair<int,int>> aint;
public:
  SegmentTree(int n){
    aint.resize(1 + 4 * n);
  }
  void computenode(int node, int from, int to){
    if(from < to)
      aint[node] = min(aint[node * 2], aint[node * 2 + 1]);
  }
  void update(int node, int from, int to, int x, int val){
    if(from < to){
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
      computenode(node, from, to);
    } else
      aint[node] = {val, from};
  }

  pair<int,int> query(int node, int from, int to, int x, int y){
    if(from == x && to == y)
      return aint[node];
    else{
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return min(query(node * 2, from, mid, x, mid), query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
};

int id[1 + nmax], pos[1 + nmax];
int dp[1 + nmax], last[1 + nmax];

bool compare(int x, int y){
  return a[x] < a[y];
}

int getpos(int n, int target){
  int x = 0;
  for(int jump = (1 << 20); 0 < jump; jump /= 2){
    if(x + jump <= n && a[id[x + jump]] <= target)
      x += jump;
  }
  return x;
}

void extract(int node){
  if(1 < dp[node])
    extract(last[node]);
  cout << node << " ";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    id[i] = i;
  }
  normalize(n);
  SegmentTree aint(n);
  sort(id + 1, id + n + 1, compare);
  for(int i = 1;i <= n; i++)
    aint.update(1, 1, n, i, b[id[i]]);

  queue<int> q;
  for(int i = 1;i <= n; i++)
    if(a[id[i]] == 0 && b[id[i]] == 0) {
      q.push(id[i]);
      dp[id[i]] = 1;
      aint.update(1, 1, n, i, inf);
    }

  while(0 < q.size()){
    int node = q.front();
    q.pop();
    while(true){
      int pos = getpos(n, c[node]);
      if(pos == 0)
        break;
      pair<int,int> sol = aint.query(1, 1, n, 1, pos);
      if(sol.first <= d[node]) {
        aint.update(1, 1, n, sol.second, inf);
        q.push(id[sol.second]);
        dp[id[sol.second]] = dp[node] + 1;
        last[id[sol.second]] = node;
      } else
        break;
    }
  }

  if(dp[n] == 0)
    cout << -1;
  else{
    cout << dp[n] << '\n';
    extract(n);
  }
  return 0;
}