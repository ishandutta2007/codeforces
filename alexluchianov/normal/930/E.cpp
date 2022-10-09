#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
int const nmax = 400000;
int const modulo = 1000000007;

class SegmentTree{
private:
  vector<int> aint;
  vector<int> lazy;
  void computenode(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
      if(modulo <= aint[node])
        aint[node] -= modulo;
    }
  }
  void cleannode(int node, int from, int to){
    if(-1 == lazy[node])
      return ;

    if(from < to){
      int mid = (from + to) / 2;
      lazy[node * 2] = lazy[node];
      lazy[node * 2 + 1] = lazy[node];
    }
    aint[node] = 1LL * lazy[node] * (to - from + 1) % modulo;
    lazy[node] = -1;
  }
public:
  SegmentTree(int n){
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }
  void update(int node, int from, int to, int x, int y, int val){
    cleannode(node, from, to);
    if(from == x && to == y){
      lazy[node] = val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);

      if(x <= mid)
        update(node * 2, from, mid, x, MIN(mid, y), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      computenode(node, from, to);
    }
  }
  int query(int node, int from, int to, int x, int y){
    cleannode(node, from,  to);
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      int result = 0;
      if(x <= mid)
        result += query(node * 2, from, mid, x, MIN(y, mid));
      if(mid + 1 <= y)
        result += query(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y);
      if(modulo <= result)
        result -= modulo;
      return result;
    }
  }
  void addvalue(int node, int from, int to, int x, int val){
    int result = query(node, from, to, x, x) + val;
    if(modulo <= result)
      result -= modulo;
    update(node, from, to, x, x, result);
  }
};

vector<pair<int,int>> query1, query2;
map<int,int> code, decode;
int events[1 + nmax], events2[1 + nmax];

vector<int> normalize(int lim){
  vector<int> temp;
  temp.push_back(0);
  temp.push_back(lim);
  for(int i = 0; i < query1.size(); i++){
    temp.push_back(query1[i].first - 1);
    temp.push_back(query1[i].second);
  }
  for(int i = 0; i < query2.size(); i++){
    temp.push_back(query2[i].first - 1);
    temp.push_back(query2[i].second);
  }
  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());
  for(int i = 0; i < temp.size(); i++) {
    code[temp[i]] = i;
    decode[i] = temp[i];
    events[i] = events2[i] = -nmax;
  }

  for(int i = 0; i < query1.size(); i++){
    query1[i].first = code[query1[i].first - 1];
    query1[i].second = code[query1[i].second];
  }
  for(int i = 0; i < query2.size(); i++){
    query2[i].first = code[query2[i].first - 1];
    query2[i].second = code[query2[i].second];
  }

  for(int i = 0; i < query1.size(); i++)
    events[query1[i].second] = MAX(events[query1[i].second], query1[i].first);
  for(int i = 0; i < query2.size(); i++)
    events2[query2[i].second] = MAX(events2[query2[i].second], query2[i].first);

  return temp;
}

int lgpow(int a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else{
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}



int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int lim, n, m;
  cin >> lim >> n >> m;
  for(int i = 1;i <= n; i++){
    int x, y;
    cin >> x >> y;
    query1.push_back({x, y});
  }
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    query2.push_back({x, y});
  }
  vector<int> temp = normalize(lim);
  SegmentTree dp1(temp.size()), dp2(temp.size());
  dp1.update(1, 0, temp.size(), 0, 0, 1);
  for(int i = 1; i < temp.size(); i++){
    int both = (modulo + lgpow(2, (temp[i] - temp[i - 1])) - 2) % modulo;
    int result = dp1.query(1, 0, temp.size(), 0, i - 1);
    int result2 = dp2.query(1, 0, temp.size(), 0, i - 1);
    dp1.addvalue(1, 0, temp.size(), i - 1, result2);
    dp2.addvalue(1, 0, temp.size(), i - 1, result);
    dp1.addvalue(1, 0, temp.size(), i, 1LL * (result + result2) * both % modulo);

    if(0 <= events[i])
      dp1.update(1, 0, temp.size(), 0, events[i], 0);
    if(0 <= events2[i])
      dp2.update(1, 0, temp.size(), 0, events2[i], 0);
  }
  int result = dp1.query(1, 0, temp.size(),0 ,temp.size()),
      result2 =dp2.query(1, 0, temp.size(),0 ,temp.size());
  cout << (result + result2) % modulo;
  return 0;
}