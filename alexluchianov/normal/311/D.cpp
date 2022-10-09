#include <iostream>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;

int const nmax = 100000;
int const modulo = 95542721;
int const period = 48;

int v[1 + nmax];

struct Node{
  int val[1 + period];
  int pos;
  int lazy;
} aint[1 + 4 * nmax];

void cleannode(int node, int from, int to){
  if(from < to){
    int mid = (from + to) / 2;
    aint[node * 2].lazy += aint[node].lazy;
    aint[node * 2 + 1].lazy += aint[node].lazy;
  }
  aint[node].pos += aint[node].lazy;
  aint[node].pos %= period;
  aint[node].lazy = 0;
}

void computenode(int node, int from, int to){
  aint[node].pos = aint[node].lazy = 0;
  if(from == to){
    aint[node].val[0] = v[from];
    for(int i = 1; i < period; i++)
      aint[node].val[i] = 1LL * aint[node].val[i - 1] * aint[node].val[i - 1] % modulo * aint[node].val[i - 1] % modulo;
  } else { /// sons are clean
    int mid = (from + to) / 2;
    for(int i = 0; i < period; i++) {
      ll result = aint[node * 2].val[(i + aint[node * 2].pos) % period] +
                  aint[node * 2 + 1].val[(i + aint[node * 2 + 1].pos) % period];
      aint[node].val[i] = result % modulo;
    }
  }
}

void build(int node, int from, int to){
  if(from < to){
    int mid = (from + to) / 2;
    build(node * 2, from, mid);
    build(node * 2 + 1, mid + 1, to);
  }
  computenode(node, from, to);
}

void update(int node, int from, int to, int x, int y){

  cleannode(node, from, to);
  if(from == x && to == y){
    aint[node].lazy++;
    cleannode(node, from, to);
  } else {
    int mid = (from + to) / 2;
    if(x <= mid)
      update(node * 2, from, mid, x, MIN(mid, y));
    else
      cleannode(node * 2, from, mid);

    if(mid + 1 <= y)
      update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y);
    else
      cleannode(node * 2 + 1, mid + 1, to);

    computenode(node, from, to);
  }
}

int query(int node,int from, int to, int x, int y){
  cleannode(node, from, to);

  if(from == x && to == y) {
    return aint[node].val[aint[node].pos];
  } else {
    int mid = (from + to) / 2;
    int result = 0;
    if(x <= mid)
      result += query(node * 2, from, mid, x, MIN(y, mid));
    if(mid + 1 <= y)
      result += query(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y);
    return result % modulo;
  }
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  build(1, 1, n);

  int q;
  cin >> q;
  for(int i = 1;i <= q; i++){
    int type, x, y;
    cin >> type >> x >> y;
    if(type == 2)
      update(1, 1, n, x, y);
    else
      cout << query(1, 1, n, x, y) << '\n';
  }
  return 0;
}
/*
2
2 3
3
1 1 2
2 1 1
1 1 2
*/