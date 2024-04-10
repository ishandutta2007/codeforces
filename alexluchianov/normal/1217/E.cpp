#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const inf = 1000000001;

int const sigma = 10;

struct Node{
  int result;
  int val[sigma];
};

Node aint[1 + nmax * 4];

Node blank(){
  Node result;
  result.result = 2 * inf;
  for(int i = 0; i < sigma; i++)
    result.val[i] = inf;
  return result;
}

Node join(Node a, Node b){
  Node result;
  result.result = MIN(a.result, b.result);
  for(int i = 0; i < sigma; i++) {
    if(a.val[i] < inf && b.val[i] < inf)
      result.result = MIN(result.result, a.val[i] + b.val[i]);
    result.val[i] = MIN(a.val[i], b.val[i]);
  }

  return result;
}


void update(int node, int from, int to, int x, int val){
  if(from < to){
    int mid = (from + to) / 2;
    if(x <= mid)
      update(node * 2, from, mid, x, val);
    else
      update(node * 2 + 1, mid + 1, to, x, val);
    aint[node] = join(aint[node * 2], aint[node * 2 + 1]);
  } else {
    Node result = blank();
    int val2 = val;
    for(int i = 0; i < sigma; i++) {
      if(0 < val2 % 10)
        result.val[i] = val;
      val2 /= 10;
    }
    aint[node] = result;
  }
}

Node query(int node, int from, int to, int x, int y){
  if(from == x && to == y)
    return aint[node];
  else {
    int mid = (from + to) / 2;
    Node result = blank();
    if(x <= mid)
      result = join(result, query(node * 2, from, mid, x, MIN(y, mid)));
    if(mid + 1 <= y)
      result = join(result, query(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y));
    return result;
  }
}

int v[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  for(int i = 1;i <= n; i++){
    cin >> v[i];
    update(1, 1, n, i, v[i]);
  }


  for(int i = 1;i <= q; i++){
    int op, x, y;
    cin >> op >> x >> y;
    if(op == 1)
      update(1, 1, n, x, y);
    else {
      int result = query(1, 1, n, x, y).result;
      if(result == 2 * inf)
        cout << -1 << '\n';
      else
        cout << result << '\n';
    }
  }
  return 0;
}