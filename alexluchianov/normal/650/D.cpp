#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 800000;
int const modulo = 1000000007;

int v[1 + nmax];
int pos[1 + nmax], h[1 + nmax];

struct Node{
  int val;
  int scount;
  Node(int val = 0, int scount = 0){
    this->val = val;
    this->scount = scount;
  }
  Node operator + (Node const &a) const{
    Node result;
    if(val < a.val)
      return a;
    else if (a.val < val)
      return *this;
    else {
      if(modulo <= scount + a.scount)
        return {val, scount + a.scount - modulo};
      else
        return {val, scount + a.scount};
    }
    return result;
  }
  Node operator * (Node const &a) const{
    return {val + a.val, 1LL * scount * a.scount % modulo};
  }
};

class SegmentTree{
private:
  vector<Node> aint;
public:
  SegmentTree(int n){
    aint.resize(4 * n);
  }

  void computenode(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    }
  }

  void update(int node, int from, int to, int x, Node up){
    if(from < to){
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, up);
      else
        update(node * 2 + 1, mid + 1, to, x, up);
      computenode(node, from, to);
    } else
      aint[node] = aint[node] + up;
  }

  Node query(int node, int from, int to, int x, int y){
    if(y < x)
      return {0, 0};
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, MIN(mid, y));
      if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y);
      else
        return query(node * 2, from, mid, x, MIN(mid, y)) + query(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y);
    }
  }
};

map<int,int> code;
int normalize(int n, int m){
  vector<int> temp;
  for(int i = 1;i <= n; i++)
    temp.push_back(v[i]);
  for(int i = 1; i <= m; i++)
    temp.push_back(h[i]);
  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());
  for(int i = 0; i < temp.size(); i++)
    code[temp[i]] = 1 + i;
  for(int i = 1;i <= n; i++)
    v[i] = code[v[i]];
  for(int i = 1;i <= m; i++)
    h[i] = code[h[i]];
  return temp.size();
}

vector<pair<int,int>> queryst[1 + nmax];
vector<pair<int,int>> querydr[1 + nmax];
Node sol[1 + nmax], sol2[1 + nmax];
Node solpointst[1 + nmax], solpointdr[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= m; i++) {
    cin >> pos[i] >> h[i];
  }
  int lim = normalize(n, m);
  for(int i = 1;i <= m; i++){
    queryst[pos[i]].push_back({i, h[i]});
    querydr[pos[i]].push_back({i, h[i]});
  }
  SegmentTree dp(lim);
  for(int i = 1;i <= n; i++){
    Node result = dp.query(1, 1, lim, 1, v[i] - 1);
    if(result.val == 0)
      result.scount = 1;
    dp.update(1, 1, lim, v[i], {result.val + 1, result.scount});
  }

  Node resultall = dp.query(1, 1, n, 1, n);

  dp = SegmentTree(lim);

  for(int i = 1;i <= n; i++) {
    for(int h = 0; h < queryst[i].size(); h++){
      pair<int,int> pr = queryst[i][h];
      sol[pr.first] = dp.query(1, 1, lim, 1, pr.second - 1);
      if(sol[pr.first].val == 0)
        sol[pr.first].scount = 1;
    }
    Node result = dp.query(1, 1, lim, 1, v[i] - 1);
    if(result.val == 0)
      result.scount = 1;
    solpointst[i] = result;
    dp.update(1, 1, lim, v[i], {result.val + 1, result.scount});
  }

  dp = SegmentTree(lim);

  for(int i = n ;1 <= i; i--) {
    for(int h = 0; h < querydr[i].size(); h++){
      pair<int,int> pr = querydr[i][h];
      Node result2 = dp.query(1, 1, lim, pr.second + 1, lim);
      if(result2.val == 0)
        result2.scount = 1;
      sol[pr.first] = sol[pr.first] * result2;
    }
    Node result = dp.query(1, 1, lim, v[i] + 1, lim);
    if(result.val == 0)
      result.scount = 1;

    solpointdr[i] = result;
    dp.update(1, 1, lim, v[i], {result.val + 1, result.scount});
  }

  for(int i = 1;i <= m; i++){
    sol[i].val++;
    if(resultall.val <= sol[i].val)
      cout << sol[i].val << '\n';
    else {
      Node result2 = (solpointst[pos[i]] * solpointdr[pos[i]]);
      result2.val++;
      if(result2.val == resultall.val && result2.scount == resultall.scount)
        cout << resultall.val - 1 << '\n';
      else
        cout << resultall.val << '\n';
    }
  }
  return 0;
}
/*
5 1
1 1 2 3 3
3 1
*/