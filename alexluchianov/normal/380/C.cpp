#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
char s[1 + nmax];

struct Node{
  int result;
  int open;
  int closed;
  Node operator + (Node const &a) const{
    Node temp = {0, 0, 0};
    temp.result = result + a.result;
    int val = MIN(open, a.closed);
    temp.result += val;
    temp.open = open - val + a.open;
    temp.closed = closed + a.closed - val;
    return temp;
  }
};

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
    } else{
      if(s[from] == '(')
        aint[node] = {0, 1, 0};
      else
        aint[node] = {0, 0, 1};
    }
  }
  Node query(int node, int from, int to, int x, int y){
    if(from == x && to == y)
      return aint[node];
    else{
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2 , from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return query(node * 2, from, mid, x, mid) + query(node * 2 + 1 , mid + 1, to, mid + 1, y);
    }
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> (1 + s);
  int n = strlen(1 + s), m;
  SegmentTree aint(n);
  aint.build(1, 1, n);
  cin >> m;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    cout << 2 * aint.query(1, 1, n, x, y).result << '\n';
  }
  return 0;
}