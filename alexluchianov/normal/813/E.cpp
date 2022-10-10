#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[1 + nmax];
int active[1 + nmax];
vector<int> freq[1 + nmax];

class SegmentTree{
private:
  vector<vector<int>> aint;
  int lowerthan(vector<int> &v, int target){ ///returns how many values are lower or equal than target
    if(v.size() == 0)
      return 0;
    else if(target < v[0])
      return 0;
    int x = 0;
    for(int jump = (1 << 20); 0 < jump; jump /= 2)
      if(x + jump < v.size() && v[x + jump] <= target)
        x += jump;
    return 1 + x;
  }
public:
  SegmentTree(int n){
    aint.resize(4 * n);
  }
  void build(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      build(node * 2, from, mid);
      build(node * 2 + 1,mid + 1, to);
    }
    for(int i = from; i <= to; i++)
      aint[node].push_back(active[i]);
    sort(aint[node].begin(), aint[node].end());
  }
  int query(int node, int from, int to, int x, int y, int val){
    if(from == x && to == y)
      return lowerthan(aint[node], val);
    else {
      int mid = (from + to) / 2;
      int result = 0;
      if(x <= mid)
        result += query(node * 2, from, mid, x, MIN(mid, y), val);
      if(mid + 1 <= y)
        result += query(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      return result;
    }
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= n; i++){
    freq[v[i]].push_back(i);
    if(k < freq[v[i]].size())
      active[i] = freq[v[i]][freq[v[i]].size() - 1 - k];
  }

  SegmentTree aint(n);
  aint.build(1, 1, n);
  int last = 0, m;
  cin >> m;
  for(int i = 1; i <= m; i++){
    int x, y;
    cin >> x >> y;
    x = (x + last) % n + 1;
    y = (y + last) % n + 1;
    if(y < x)
      swap(x, y);
    last = aint.query(1, 1, n, x, y, x - 1);
    cout << last << '\n';
  }
  return 0;
}