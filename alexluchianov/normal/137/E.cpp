#include <iostream>
#include <map>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

map<char,int> vowel;

void precompute(){
  vowel['a'] = 1;
  vowel['e'] = 1;
  vowel['i'] = 1;
  vowel['o'] = 1;
  vowel['u'] = 1;
}

char small(char ch){
  if('A' <= ch && ch <= 'Z')
    return ch - 'A' + 'a';
  return ch;
}

int const nmax = 200000;

class SegmentTree{
private:
  int n;
  vector<int> aint;
public:
  SegmentTree(int n){
    this->n = n;
    aint.resize(4 * n);
  }
  void build(int node, int from, int to){
    if(from < to){
      int mid = (from + to) >> 1;
      build(node * 2, from, mid);
      build(node * 2 + 1, mid + 1, to);
      aint[node] = MIN(aint[node * 2], aint[node * 2 + 1]);
    } else
      aint[node] = nmax;
  }

  void update(int node, int from, int to, int x, int val){
    if(from < to){
      int mid = (from + to) >> 1;
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
      aint[node] = MIN(aint[node * 2], aint[node * 2 + 1]);
    } else
      aint[node] = MIN(aint[node], val);
  }
  int query(int node, int from, int to, int x, int y){
    if(from == x && to == y)
      return aint[node];
    else{
      int mid = (from + to) >> 1;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return min(query(node * 2, from, mid, x, mid), query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
};

int v[1 + nmax];

int main()
{
  precompute();
  string s;
  cin >> s;
  int n = s.size();
  for(int i = 1; i <= n; i++){
    if(vowel[small(s[i - 1])] == 1)
      v[i] = -1;
    else
      v[i] = 2;
  }

  int from = -n * 2, to = n * 2;
  SegmentTree aint(to - from + 1);
  aint.build(1, from, to);
  aint.update(1, from, to, 0, 0);

  int result = 0, scount = 0;
  for(int i = 1;i <= n; i++){
    v[i] += v[i - 1];

    int pos = aint.query(1, from, to, from, v[i]);
    if(pos < i){
      int dist = i - pos;
      if(result < dist){
        result = dist;
        scount = 1;
      } else if(result == dist)
        scount++;
    }
    aint.update(1, from, to, v[i], i);
  }
  if(0 < result)
    cout << result << " " << scount;
  else
    cout << "No solution";
  return 0;
}