#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

class SegmentTree{
private:
  vector<pair<int,int>> aint;
  vector<int> lazy;
  int mode;
public:
  SegmentTree(int n, int mode_){
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
    mode = mode_;
  }
  void cleannode(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node].first += lazy[node];
    lazy[node] = 0;
  }

  pair<int,int> join(pair<int,int> f1, pair<int,int> f2){
    if(mode == 1)
      return min(f1, f2);
    else
      return max(f1, f2);
  }

  void computenode(int node, int from, int to){
    if(from < to)
      aint[node] = join(aint[node * 2], aint[node * 2 + 1]);
  }

  void build(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      build(node * 2, from, mid);
      build(node * 2 + 1, mid + 1, to);
      computenode(node, from, to);
    } else
      aint[node] = {0, from};
  }

  void update(int node, int from, int to, int x, int y, int val){
    if(y < x)
      return ;

    if(from == x && to == y){
      lazy[node] += val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update(node * 2, from, mid, x, MIN(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      computenode(node, from ,to);
    }
  }

  pair<int,int> _query(int node, int from, int to, int x, int y){
    if(y < x)
      return {0, 0};
    cleannode(node, from, to);
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(y <= mid)
        return _query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x)
        return _query(node * 2 + 1, mid + 1, to, x, y);
      else
        return join(_query(node * 2, from, mid, x, mid), _query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
  pair<int,int> query(){
    return aint[1];
  }
};

int const nmax = 200000;

struct Event{
  int y;
  int id;
  bool operator < (Event const &a) const {
    if(y != a.y)
      return y < a.y;
    else
      return id < a.id;
  }
};

vector<Event> events[1 + nmax];

int sol1[1 + nmax];
int sol2[1 + nmax];

int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  SegmentTree aint(n, 1);
  for(int i = 1;i <= n; i++)
    aint.update(1, 1, n, i, i, i);

  for(int i = 1;i <= n; i++){
    int x, y;
    cin >> x >> y;
    events[x].push_back({y, i});
    aint.update(1, 1, n, y, n, -1);
  }

  set<Event> myset;
  set<Event> myset2;

  bool valid = 0;

  for(int i = 1; i <= n; i++){
    for(int h = 0; h < events[i].size(); h++){
      myset.insert(events[i][h]);
      myset2.insert(events[i][h]);
    }
    sol1[myset.begin()->id] = i;

    myset.erase(myset.begin());
    set<Event>::iterator it = myset2.begin(), target = myset2.begin();
    it++;

    if(it != myset2.end() && 0 < aint._query(1, 1, n, i, it->y - 1).first ) {
      target = it;
      valid = 1;
    } else
      target = myset2.begin();
    aint.update(1, 1, n, i, target->y - 1, -1);
    sol2[target->id] = i;
    myset2.erase(target);

  }

  if(valid == 0) {
    cout << "YES\n";
    for(int i = 1;i <= n; i++)
      cout << sol1[i] << " ";
  } else {
    cout << "NO\n";
    for(int i = 1;i <= n; i++)
      cout << sol1[i] << " ";
    cout << '\n';
    for(int i = 1;i <= n; i++)
      cout << sol2[i] << " ";
    cout << '\n';
  }

  return 0;
}