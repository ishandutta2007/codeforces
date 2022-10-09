#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 500000;
int const inf = 1000000000;
class SegmentTree{
/*
initialized with 0, -1, -2, -3, ... -(n - 1)
update on interval with +val
query, max on interval
*/

private:
  int n;
  vector<int> aint;
  vector<int> lazy;
  void cleannode(int node, int from, int to){
    if(from < to){
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node] += lazy[node];
    lazy[node] = 0;
  }

  void computenode(int node, int from, int to){
    if(from < to)
      aint[node] = MAX(aint[node * 2], aint[node * 2 + 1]);
  }

public:
  SegmentTree(int n){
    this->n = n;
    aint.resize(4 * n);
    lazy.resize(4 * n);
  }

  void update(int node, int from, int to, int x, int y, int val){
    cleannode(node, from, to);
    if(from == x && to == y){
      lazy[node] += val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, MIN(y, mid), val);
      else
        cleannode(node * 2, from, mid);

      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      else
        cleannode(node * 2 + 1, mid + 1, to);

      computenode(node, from, to);
    }
  }

  int query(int node, int from, int to, int x, int y){
    cleannode(node, from, to);
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      int result = -inf, result2 = -inf;
      if(x <= mid)
        result = query(node * 2, from, mid, x, MIN(y, mid));
      if(mid + 1 <= y)
        result2 = query(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y);
      return MAX(result, result2);
    }
  }
  void print(int from, int to){
    for(int i = from;i <= to; i++)
      cout << query(1, 1, 3, i, i) << " ";
    cout << '\n';
  }
};

struct Friend{
  int time;
  int cap;
  int cost;
  bool operator < (Friend const &a) const{
    return a.cost < cost;
  }
};

bool compare(Friend a, Friend b){
  return a.time < b.time;
}

Friend v[1 + nmax];

map<int,int> code;
map<int,int> decode;

void solve(){
  int n, m, clim, current;
  cin >> n >> m >> clim >> current;

  code.clear();
  decode.clear();
  for(int i = 1;i <= n; i++)
    cin >> v[i].time >> v[i].cap >> v[i].cost;
  sort(v + 1, v + n + 1, compare);
  int ind = 0, time = current;

  code[0] = 1;
  decode[1] = 0;

  for(int i = 1;i <= n; i++)
    if(v[i - 1].time < v[i].time) {
      code[v[i].time] = code[v[i - 1].time] + 1;
      decode[code[v[i].time]] = v[i].time;
    }

  if(code[m - 1] == 0) {
    code[m - 1] = code.size();
    decode[code[m - 1]] = m - 1;
  }


  int lim = code.size();

  SegmentTree aint(lim);
  for(int i = 1;i <= lim; i++) {
    aint.update(1, 1, lim, i, i, -decode[i]);
  }

  aint.update(1, 1, lim, code[0], code[m - 1], time);

  priority_queue<Friend> pq;
  ll result = 0;
  while(time < m){
    while(ind < n && v[ind + 1].time <= time){
      ind++;
      pq.push(v[ind]);
    }

    if(0 < pq.size()){
      Friend tryp = pq.top();
      pq.pop();
      int nxt = m - time;
      if(ind < n)
        nxt = MIN(m - time, v[1 + ind].time - time);
      int val = min(nxt, min((clim - aint.query(1, 1, lim, code[tryp.time], code[m - 1])), tryp.cap));
      if(val == 0)
        continue;

      time += val;
      tryp.cap -= val;
      result += 1LL * tryp.cost * val;
      if(0 < tryp.cap)
        pq.push(tryp);
      aint.update(1, 1, lim, code[tryp.time], code[m - 1], val);
    } else
      break;
  }

  if(time < m)
    cout << -1 << '\n';
  else
    cout << result << '\n';
  //*/
}
int main()
{
  //*
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //*/

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}
/*
1
1 5 3 1
1 5 3

*/
/*
1
7 9 2 1
4 1 1
7 1 7
1 2 4
7 1 3
2 2 1
3 2 2
1 1 7
*/