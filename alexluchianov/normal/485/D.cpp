#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 500000;
int v[5 + nmax];

struct Value{
  int x;
  int sadd;
  bool operator < (Value const &a) const {
    return x > a.x;
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie();

  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];
  sort(v + 1 , v + n + 1);

  int smax = 0;
  priority_queue<Value> pq;
  pq.push({v[1] , v[1]});
  for(int i = 2 ; i <= n ; i++){
    if(v[i - 1] < v[i]){
      Value node = pq.top();
      while(node.x + node.sadd <= v[i]){
        pq.pop();
        node.x = v[i] - v[i] % node.sadd;

        pq.push(node);
        node = pq.top();
      }
      smax = MAX(smax , v[i] - pq.top().x);
      pq.push({v[i] , v[i]});
    }
  }
  cout << smax;
  return 0;
}