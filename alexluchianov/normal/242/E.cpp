#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const lgmax = 20;

class SegmentTree{
private:
  vector<int> aint;
  vector<int> lazy;
public:
  SegmentTree(int n){
    aint.resize(4 * n);
    lazy.resize(4 * n);
  }
  void computenode(int node, int from, int to){
    if(from < to)
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
  }

  void cleannode(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      lazy[node * 2] ^= lazy[node];
      lazy[node * 2 + 1] ^= lazy[node];
    }

    if(lazy[node] == 1)
      aint[node] = (to - from + 1) - aint[node];
    lazy[node] = 0;
  }

  void update(int node, int from, int to, int x, int val){
    cleannode(node, from, to);
    if(from < to){
      int mid = (from + to ) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
      computenode(node, from, to);
    } else
      aint[node] = val;
  }

  void updateint(int node, int from, int to, int x, int y){
    if(from == x && to == y){
      lazy[node] ^= 1;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        updateint(node * 2, from, mid, x, MIN(y, mid));
      if(mid + 1 <= y)
        updateint(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y);
      computenode(node, from, to);
    }
  }

  int query(int node, int from, int to, int x, int y){
    cleannode(node, from, to);
    if(from == x && to == y)
      return aint[node];
    else{
      int mid = (from + to) / 2;
      int result = 0;
      if(x <= mid)
        result += query(node * 2, from, mid, x, MIN(y, mid));
      if(mid + 1 <= y)
        result += query(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y);
      return result;
    }
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<SegmentTree> aint;
  for(int i = 0; i < lgmax; i++)
    aint.push_back(SegmentTree(n));

  for(int i = 1;i <= n; i++){
    int val;
    cin >> val;
    for(int j = 0; j < lgmax; j++)
      aint[j].update(1, 1, n, i, (0 < (val & (1 << j))));
  }

  int q;
  cin >> q;
  for(int i = 1;i <= q; i++){
    int op;
    cin >> op;
    if(op == 1){
      int x, y;
      ll result = 0;
      cin >> x >> y;
      for(int j = 0; j < lgmax; j++)
        result += aint[j].query(1, 1, n, x, y) * (1LL << j);
      cout << result << '\n';
    } else {
      int x, y, val;
      cin >> x >> y >> val;
      for(int j = 0; j < lgmax; j++)
        if(0 < ((1 << j) & val))
          aint[j].updateint(1, 1, n, x, y);
    }
  }
  return 0;
}