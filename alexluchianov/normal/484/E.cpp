#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const inf = 1000000000;

int v[1 + nmax];

struct Node{
  int pref;
  int suff;
  int sum;
  int l;

  Node operator + (Node const &a) const{
    Node result;
    result.l = l + a.l;
    if(l == sum)
      result.pref = l + a.pref;
    else
      result.pref = pref;

    if(a.l == a.sum)
      result.suff = suff + a.l;
    else
      result.suff = a.suff;

    result.sum = MAX(MAX(sum, a.sum) ,suff + a.pref);
    return result;
  }
};

class SegmentTree{
private:
  int n;
  vector<Node> aint;
public:
  SegmentTree(int n){
    this->n = n;
    aint.resize(4 * n);
  }
  void build(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      build(node * 2, from, mid);
      build(node * 2 + 1, mid + 1, to);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node] = {0, 0, 0, 1};
  }

  void update(int node, int from, int to, int x){
    if(from < to){
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x);
      else
        update(node * 2 + 1, mid + 1, to, x);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node] = {1, 1, 1, 1};
  }

  Node query(int node, int from, int to, int x, int y){
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return query(node * 2, from, mid, x, mid) + query(node * 2 + 1, mid + 1, to, mid + 1, y);
    }
  }
};

int ind[1 + nmax];
bool compare(int x, int y){
  return v[x] < v[y];
}

int sol[1 + nmax];
int l[1 + nmax], r[1 + nmax], target[1 + nmax];

struct Query{
  int l;
  int r;
  int target;
  int active;
  int id;
  bool operator < (Query const &a) const{
    return active < a.active;
  }
};

int n, m;

void processStep(int jump){
  vector<Query> query;
  for(int i = 1;i <= m; i++)
    query.push_back({l[i], r[i], target[i], sol[i] + jump, i});

  sort(query.begin(), query.end());
  reverse(query.begin(), query.end());

  int ptr = n;
  SegmentTree aint(n);
  aint.build(1, 1, n);

  for(int i = 0; i < query.size(); i++){
    while(0 < ptr && query[i].active <= v[ind[ptr]]){
      aint.update(1, 1, n, ind[ptr]);
      ptr--;
    }
    if(query[i].target <= aint.query(1, 1, n, query[i].l, query[i].r).sum)
      sol[query[i].id] += jump;
  }
}

int main()
{
  //*
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //*/

  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    ind[i] = i;
  }
  sort(ind + 1, ind + n + 1, compare);
  cin >> m;
  for(int i = 1;i <= m; i++){
    cin >> l[i] >> r[i] >> target[i];
    sol[i] = 0;
  }
  for(int step = (1 << 29); 0 < step; step /= 2) {
    processStep(step);
   }

  for(int i = 1; i <= m; i++)
    cout << sol[i] << '\n';
  return 0;
}