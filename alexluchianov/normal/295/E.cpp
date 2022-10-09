#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <map>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 100000;
int v[1 + nmax];

struct Query{
  int type;
  int l;
  int r;
} queries[1 + nmax];

map<int,int> code, decode;

int normalize(int n, int q){
  vector<int> temp;
  for(int i = 1;i <= n; i++)
    temp.push_back(v[i]);
  for(int i = 1;i <= q; i++){
    temp.push_back(queries[i].r);
    if(queries[i].type == 2)
      temp.push_back(queries[i].l);
  }

  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());

  for(int i = 0; i < temp.size(); i++) {
    code[temp[i]] = i + 1;
    decode[i + 1] = temp[i];
  }
  for(int i = 1;i <= n; i++)
    v[i] = code[v[i]];

  for(int i = 1;i <= q; i++) {
    if(queries[i].type == 2)
      queries[i].l = code[queries[i].l];
    queries[i].r = code[queries[i].r];
  }
  return temp.size();
}

class SegmentTree{
private:
  struct Node{
    ll result;
    ll sum;
    int scount;

    Node(){
      result = sum = scount = 0;
    }

    Node operator + (Node const &a) const {
      Node obj;
      obj.sum = sum + a.sum;
      obj.scount = scount + a.scount;
      obj.result = result + a.result + scount * a.sum - sum * a.scount;
      return obj;
    }
  };
  vector<Node> aint;
  void _update(int node, int from, int to, int x, int val, int scount){
    if(from < to){
      int mid = (from + to) / 2;
      if(x <= mid)
        _update(node * 2, from, mid, x, val, scount);
      else
        _update(node * 2 + 1, mid + 1, to, x, val, scount);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else {
      aint[node].scount += scount;
      aint[node].sum += 1LL * scount * val;
    }
  }
  Node _query(int node, int from, int to, int x, int y){
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return _query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return _query(node * 2 + 1, mid + 1, to, x, y);
      else
        return _query(node * 2, from, mid, x, mid) + _query(node * 2 + 1, mid + 1, to, mid + 1, y);
    }
  }
public:

  SegmentTree(int n){
   aint.resize(1 + 4 * n);
  }
  void update(int node, int from, int to, int x, int val, int scount){
    _update(node, from, to, x, val, scount);
  }
  ll query(int node, int from, int to, int x, int y){
    return _query(node, from, to, x, y).result;
  }
};
int pos[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    pos[i] = v[i];
  }
  cin >> q;
  for(int i = 1;i <= q; i++){
    cin >> queries[i].type >> queries[i].l >> queries[i].r;
    if(queries[i].type == 1) {
      pos[queries[i].l] += queries[i].r;
      queries[i].r = pos[queries[i].l];
    }
  }
  int lim = normalize(n, q);
  SegmentTree aint(lim);
  for(int i = 1;i <= n; i++)
    aint.update(1, 1, lim, v[i], decode[v[i]], 1);

  for(int i = 1;i <= q; i++){
    if(queries[i].type == 1){
      aint.update(1, 1, lim, v[queries[i].l], decode[v[queries[i].l]], -1);
      v[queries[i].l] = queries[i].r;
      aint.update(1, 1, lim, v[queries[i].l], decode[v[queries[i].l]], 1);
    } else {
      cout << aint.query(1, 1, lim, queries[i].l, queries[i].r) << '\n';
    }
  }
  return 0;
}