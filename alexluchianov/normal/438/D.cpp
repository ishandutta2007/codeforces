#include <iostream>
#include <fstream>

using namespace std;

int const nmax = 100000;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

struct {
  ll sum;
  int val;
} aint[1 + 4 * nmax];

void update1(int node, int from, int to, int x, int val){

  if(from < to){
    int mid = (from + to) / 2;
    if(x <= mid)
      update1(node * 2, from, mid, x, val);
    else
      update1(node * 2 + 1, mid + 1, to, x, val);
    aint[node].sum = aint[node * 2].sum + aint[node * 2 + 1].sum;
    aint[node].val = max(aint[node * 2].val, aint[node * 2 + 1].val);
  } else
    aint[node] = {val, val};
}

ll query(int node, int from, int to, int x, int y){
  if(from == x && to == y)
    return aint[node].sum;
  else {
    int mid = (from + to) / 2;
    ll result = 0;
    if(x <= mid)
      result += query(node * 2, from, mid, x, MIN(mid, y));
    if(mid + 1 <= y)
      result += query(node * 2 + 1, mid + 1, to, MAX(x, mid + 1), y);
    return result;
  }
}
void update2(int node, int from, int to, int x, int y, int modulo){

  if(aint[node].val < modulo)
    return ;

  if(from == to){

    aint[node] = {aint[node].val % modulo, aint[node].val % modulo};
  } else {
    int mid = (from + to) / 2;
    if(x <= mid)
      update2(node * 2, from, mid, x, MIN(mid, y), modulo);
    if(mid + 1 <= y)
      update2(node * 2 + 1, mid + 1, to, MAX(x, mid + 1), y, modulo);
    aint[node].sum = aint[node * 2].sum + aint[node * 2 + 1].sum;
    aint[node].val = max(aint[node * 2].val, aint[node * 2 + 1].val);
  }
}
int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++){
    int a;
    cin >> a;
    update1(1, 1, n, i, a);
  }


  for(int i = 1;i <= m; i++){
    int type;
    cin >> type;
    if(type == 1){
      int l, r;
      cin >> l >> r;
      cout << query(1, 1, n, l, r) << '\n';
    } else if(type == 2){
      int l, r, x;
      cin >> l >> r >> x;
      update2(1, 1, n, l, r, x);
    } else if(type == 3){
      int pos, x;
      cin >> pos >> x;
      update1(1, 1, n, pos, x);
    }

  }
  return 0;
}