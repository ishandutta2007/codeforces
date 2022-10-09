#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

namespace DataStructures{

struct Node{
  ll result;
  int pref, suff, l, complete;
  Node operator + (Node const a) const{
    Node result;
    result.result = this->result + a.result + 1LL * suff * a.pref;
    if(complete == 1)
      result.pref = l + a.pref;
    else
      result.pref = pref;

    if(a.complete == 1)
      result.suff  = suff + a.l;
    else
      result.suff = a.suff;

    result.l = l + a.l;
    result.complete = (complete & a.complete);
    return result;
  }
  Node(int x = 0){
    l = 1;
    if(x == 0){
      result = pref = suff = complete = 0;
    } else {
      result = pref = suff = complete = 1;
    }
  }
};

class SegmentTree{
private:
  std::vector<Node> aint;
public:
  SegmentTree(int n = 0){
    aint.resize(4 * n);
  }
  void update(int node, int from, int to, int x, int val){
    if(from < to){
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node] = val;
  }
  ll query(){
    return aint[1].result;
  }
};

};

int const nmax = 100000;
int const lgmax = 17;
int v[1 + nmax];
/*
3 1
1 1 1
1 1
*/

int main()
{
  /*
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  */

  int n, m;
  cin >> n >> m;
  vector<DataStructures::SegmentTree> aint(1 + lgmax);
  for(int i = 0; i < lgmax; i++)
    aint[i] = DataStructures::SegmentTree(n);
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int bit = 0; bit < lgmax; bit++){
    for(int i = 1;i <= n; i++){
      if(0 < ((1 << bit) & v[i]))
        aint[bit].update(1, 1, n, i, 1);
      else
        aint[bit].update(1, 1, n, i, 0);
    }
  }

  for(int i = 1;i <= m; i++){
    int pos, value;
    cin >> pos >> value;
    for(int bit = 0;bit < lgmax; bit++)
      if(0 < ((1 << bit) & value))
        aint[bit].update(1, 1, n, pos, 1);
      else
        aint[bit].update(1, 1, n, pos, 0);
    ll result = 0;

    for(int bit = 0; bit < lgmax; bit++) {
      result += (aint[bit].query() << bit);
    }
    cout << result << '\n';
  }
  return 0;
}