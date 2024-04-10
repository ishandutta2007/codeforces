#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 3000;
int v[1 + nmax];

class Slope{
public:
  ll a, b;
  std::priority_queue<ll> pq;

  Slope(){
    a = b = 0;
  }
  void push(int val){
    pq.push(val);
  }

  int size(){
    return pq.size();
  }
  ll top(){
    return pq.top();
  }
  void pop(){
    pq.pop();
  }
  void flatten(){
    while(1 <= a){
      b += pq.top();
      a--;
      pq.pop();
    }
  }
};

void _add(Slope &x, Slope &y){
  if(x.size() < y.size())
    std::swap(x, y);
  x.a += y.a;
  x.b += y.b;
  while(0 < y.size()){
    x.push(y.top());
    y.pop();
  }
}

int main()
{
  int n;
  std::cin >> n;
  Slope total;
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    v[i] -= i;
    Slope newslope;
    newslope.a = 1;
    newslope.b = -v[i];
    newslope.push(v[i]);
    newslope.push(v[i]);

    _add(total, newslope);
    total.flatten();
  }
  std::cout << total.a * total.top() + total.b;
  return 0;
}