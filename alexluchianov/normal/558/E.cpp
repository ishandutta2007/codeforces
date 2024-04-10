#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const sigma = 26;

class SegmentTree{
private:
  int n;
  vector<int> aint;
  vector<int> lazy;
  void cleannode(int node, int from, int to){
    if(from < to) {
      int mid = (from + to) / 2;
      if(0 != lazy[node])
        lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
    }
    if(lazy[node] == 1)
      aint[node] = (to - from + 1);
    else if(lazy[node] == -1)
      aint[node] = 0;
    lazy[node] = 0;
  }
  void computenode(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    }
  }
public:
  void initialize(int n){
    this->n = n;
    aint.resize(4 * n);
    lazy.resize(4 * n);
  }

  void update(int node, int from, int to, int x, int y, int val){ /// -1 sets to 0, 1 sets to 1
    if(y < x)
      return ;
    cleannode(node, from, to);

    if(from == x && to == y){
      lazy[node] = val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);

      if(x <= mid)
        update(node * 2, from, mid, x, MIN(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      computenode(node, from, to);
    }
  }

  int query(int node, int from, int to, int x, int y){
    cleannode(node, from, to);

    if(from == x && to == y)
      return aint[node];
    else{
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);

      int result = 0;
      if(x <= mid)
        result += query(node * 2, from, mid, x, MIN(mid, y));
      if(mid + 1 <= y)
        result += query(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y);
      return result;
    }
  }
};

int main()
{
  int n, q;
  cin >> n >> q;
  SegmentTree v[sigma];
  for(int i = 0; i < sigma; i++)
    v[i].initialize(1 + n);

  for(int i = 1;i <= n; i++){
    char a;
    cin >> a;
    v[a - 'a'].update(1, 1, n, i, i, 1);
  }

  for(int i = 1;i <= q; i++){
    int x, y, op;
    cin >> x >> y >> op;
    int frec[sigma];
    for(int j = 0; j < sigma; j++) {
      frec[j] = v[j].query(1, 1, n, x, y);
      v[j].update(1, 1, n, x, y, -1);
    }
    int start = x;
    if(op == 1) {
      for(int j = 0; j < sigma; j++){
        v[j].update(1, 1, n, start, start + frec[j] - 1,1);
        start += frec[j];
      }
    } else {
      for(int j = sigma - 1; 0 <= j; j--){
        v[j].update(1, 1, n, start, start + frec[j] - 1,1);
        start += frec[j];
      }
    }
  }

  for(int i = 1;i <= n; i++) {
    for(int j = 0; j < sigma; j++) {
      if(v[j].query(1, 1, n, i, i) == 1)
        cout << (char)(j + 'a');
    }
  }
  return 0;
}