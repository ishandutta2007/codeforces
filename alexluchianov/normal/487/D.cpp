#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 100000;
string s[1 + nmax];

class SegmentTree{
private:
  struct Convey{
    int l;
    vector<pair<int,int>> dest;
    Convey(){

    }
    Convey(string s){
      int n = s.size() - 1;
      dest.resize(1 + n);
      l = 1;
      for(int i = 1;i <= n; i++)
        if(s[i] == '^')
          dest[i] = {0, i};
        else
          dest[i] = {-1, -1};

      if(s[n] == '>')
        dest[n] = {1, n + 1};
      if(s[1] == '<')
        dest[1] = {1, 0};

      for(int i = 2;i <= n; i++)
        if(s[i] == '<')
          dest[i] = dest[i - 1];
      for(int i = n - 1; 1 <= i; i--)
        if(s[i] == '>')
          dest[i] = dest[i + 1];
    }

    Convey operator + (Convey const a) const {
      Convey result;
      result.l = l + a.l;
      int n = dest.size() - 1;
      result.dest.resize(1 + n);
      for(int i = 1;i <= n; i++){
        if(a.dest[i].first == -1)
          result.dest[i] = a.dest[i];
        else if(a.dest[i].first == 0)
          result.dest[i] = dest[a.dest[i].second];
        else {
          result.dest[i] = a.dest[i];
          result.dest[i].first += l;
        }
      }
      return result;
    }
  };
  vector<Convey> aint;
public:
  SegmentTree(int n){
    aint.resize(1 + 4 * n);
  }
  void build(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      build(node * 2, from, mid);
      build(node * 2 + 1, mid + 1, to);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node] = s[from];
  }
  void update(int node, int from, int to, int x, string s){
    if(from < to){
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, s);
      else
        update(node * 2 + 1, mid + 1, to, x, s);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node] = s;
  }
  Convey query(int node, int from, int to, int x, int y){
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return query(node * 2, from, mid, x, mid) + query(node * 2 + 1, mid + 1, to, mid + 1, y);
    }
  }
  pair<int,int> _query(int node, int from, int to, int x, int y){
    Convey result = query(node, from, to, 1, x);
    return result.dest[y];
  }
};
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, q;
  cin >> n >> m >> q;
  for(int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = "#" + s[i];
  }
  SegmentTree aint(n);
  aint.build(1, 1, n);
  for(int i = 1;i <= q; i++){
    char op;
    cin >> op;
    if(op == 'A'){
      int x, y;
      cin >> x >> y;
      pair<int,int> sol = aint._query(1, 1, n, x, y);
      cout << sol.first << " " << sol.second << '\n';
    } else {
      int x, y;
      char ch;
      cin >> x >> y >> ch;
      s[x][y] = ch;
      aint.update(1, 1, n, x, s[x]);
    }
  }
  return 0;
}