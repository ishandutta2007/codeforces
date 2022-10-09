#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
int const nmax = 200000;
int const inf = 1000000000;

struct Node{
  int coef[5][5];
  Node(int x = 0){
    for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++)
        coef[i][j] = inf;
    for(int i = 0; i < 5; i++)
      coef[i][i] = 0;
    if(x == 2){
      coef[0][1] = 0;
      coef[0][0] = 1;
    } else if(x == 0){
      coef[1][2] = 0;
      coef[1][1] = 1;
    } else if(x == 1){
      coef[2][3] = 0;
      coef[2][2] = 1;
    } else if(x == 7){
      coef[3][4] = 0;
      coef[3][3] = 1;
    } else if(x == 6){
      coef[4][4] = 1;
      coef[3][3] = 1;
    }
  }
  Node operator +(Node const &a) const{
    Node result;
    for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++)
        result.coef[i][j] = inf;
    for(int i = 0; i < 5; i++)
      for(int j = i; j < 5; j++)
        for(int h = j; h < 5; h++)
          result.coef[i][h] = MIN(result.coef[i][h], coef[i][j] + a.coef[j][h]);
    return result;
  }
};
char v[1 + nmax];
class SegmentTree{
private:
  vector<Node> aint;
public:
  SegmentTree(int n){
    aint.resize(4 * n);
  }
  void build(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      build(node * 2, from, mid);
      build(node * 2 + 1, mid + 1, to);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node] = Node(v[from] - '0');
  }
  Node query(int node, int from, int to, int x, int y){
    if(from == x && to == y)
      return aint[node];
    else{
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

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n >> q;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  SegmentTree aint(n);
  aint.build(1, 1, n);
  for(int i = 1; i <= q; i++){
    int x, y;
    cin >> x >> y;
    Node result = aint.query(1, 1, n, x, y);
    if(result.coef[0][4] == inf)
      cout << -1 << '\n';
    else
      cout << result.coef[0][4] << '\n';
  }
  return 0;
}
/*
14 1
01201666209167
1 14
*/