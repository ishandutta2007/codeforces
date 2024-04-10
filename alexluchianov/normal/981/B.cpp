#include <iostream>
#include <algorithm>

using namespace std;

struct Element{
  int x;
  int cost;
  bool operator < (Element const &a) const{
    if(x != a.x)
      return x < a.x;
    else
      return cost < a.cost;
  }
};
int const nmax = 100000;
Element v[5 + nmax * 2];

#define ll long long

int main()
{
  int n , m;
  cin >> n;
  for(int i = 1 ; i <= n ;i++)
    cin >> v[i].x >> v[i].cost;
  cin >> m;
  for(int i = 1 ; i <= m ;i++)
    cin >> v[n + i].x >> v[n + i].cost;
  sort(v + 1 , v + m + n + 1);
  ll result = 0;
  for(int i = m + n ; 0 < i ;i--){
    if(v[i].x != v[i + 1].x)
      result += v[i].cost;
  }
  cout << result;
  return 0;
}