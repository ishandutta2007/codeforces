#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int const nmax = 100000;

struct Person{
  int val;
  int id;
  bool operator < (Person const &a) const{
    if(val != a.val)
      return val < a.val;
    else
      return id < a.id;
  }
};

Person v[1 + nmax];
ll sol[1 + nmax];

class Fenwick{
private:
  int n;
  vector<int> aib;
public:
  Fenwick(int n){
    this->n = n;
    aib.resize(1 + n);
  }
  void update(int x, int val){
    if(x == 0)
      return ;
    while(x <= n){
      aib[x] += val;
      x = x + (x ^ (x & (x - 1)));
    }
  }
  int query(int x){
    int result = 0;
    while(0 < x){
      result += aib[x];
      x = x & (x - 1);
    }
    return result;
  }
};

int main()
{
  int n, p;
  cin >> n >> p;
  for(int i = 1;i <= n; i++){
    cin >> v[i].val;
    v[i].id = i;
  }
  sort(v + 1, v + n + 1);

  ll currentTime = 0;
  int ptr = 1;
  priority_queue<int,vector<int>, greater<int>> pq;

  Fenwick active(n);
  for(int i = 1;i <= n; i++)
    active.update(i, 1);

  queue<int> q;

  while(0 < q.size() || 0 < pq.size() || ptr <= n){
    if(0 < q.size()){
      currentTime += p;
      while(ptr <= n && v[ptr].val <= currentTime){
        if(active.query(v[ptr].id) == v[ptr].id) {
          active.update(v[ptr].id, -1);
          q.push(v[ptr].id);
        } else
          pq.push(v[ptr].id);
        ptr++;
      }

      int pos = q.front();
      q.pop();
      active.update(pos, 1);
      sol[pos] = currentTime;

      while(0 < pq.size() && active.query(pq.top()) == pq.top()) {
        active.update(pq.top(), -1);
        q.push(pq.top());
        pq.pop();
      }
    } else {
      currentTime = v[ptr].val;
      while(ptr <= n && v[ptr].val <= currentTime){
        if(active.query(v[ptr].id) == v[ptr].id) {
          active.update(v[ptr].id, -1);
          q.push(v[ptr].id);
        } else
          pq.push(v[ptr].id);
        ptr++;
      }
    }
  }

  for(int i = 1;i <= n; i++)
    cout << sol[i] << " ";
  cout << '\n';
  return 0;
}
/*
5 100
102 4 3 2 1
*/