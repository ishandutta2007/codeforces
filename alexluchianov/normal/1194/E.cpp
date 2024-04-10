#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

class FenwickTree{
private:
  vector<int> aib;
  int n;
public:
  FenwickTree(int n_){
    n = n_;
    aib.resize(1 + n);
  }
  void update(int pos, int val){
    for(int x = pos; x <= n; x += (x ^ (x & (x - 1))))
      aib[x] += val;
  }

  int query(int pos){
    int result = 0;
    for(int x = pos;0 < x; x = (x & (x - 1)))
      result += aib[x];
    return result;
  }
};

struct Seg{
  int x, y;
  int x2, y2;
  bool operator < (Seg const &a) const {
    return x2 < a.x2;
  }
};

int const nmax = 5001;

vector<Seg> horizontal;
vector<Seg> vertical;

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n;i++){
    Seg curr;
    cin >> curr.x >> curr.y >> curr.x2 >> curr.y2;
    if(curr.x2 < curr.x)
      swap(curr.x, curr.x2);
     if(curr.y2 < curr.y)
      swap(curr.y, curr.y2);

    curr.x += nmax;
    curr.y += nmax;
    curr.x2 += nmax;
    curr.y2 += nmax;

    if(curr.x != curr.x2)
      horizontal.push_back(curr);
    else
      vertical.push_back(curr);
  }
  if(vertical.size() < horizontal.size()){
    swap(vertical, horizontal);
    for(int i = 0; i < vertical.size(); i++){
      swap(vertical[i].x, vertical[i].y);
      swap(vertical[i].x2, vertical[i].y2);
    }
    for(int i = 0; i < horizontal.size(); i++){
      swap(horizontal[i].x, horizontal[i].y);
      swap(horizontal[i].x2, horizontal[i].y2);
    }
  }
  sort(vertical.begin(), vertical.end());
  sort(horizontal.begin(), horizontal.end());

  ll result = 0;
  for(int i = 0; i < vertical.size(); i++){
    int ptr = horizontal.size() - 1;
    FenwickTree aib(nmax * 2);

    for(int j = vertical.size() - 1; i < j; j--){
      while(0 <= ptr && vertical[j].x2 <= horizontal[ptr].x2){
        if(horizontal[ptr].x <= vertical[i].x2)
          aib.update(horizontal[ptr].y, 1);
        ptr--;
      }
      int cost = aib.query(min(vertical[i].y2, vertical[j].y2)) - aib.query(max(vertical[i].y, vertical[j].y) - 1);
      cost = max(cost, 0);
      result += cost * (cost - 1) / 2;
    }
  }

  cout << result;
  return 0;
}