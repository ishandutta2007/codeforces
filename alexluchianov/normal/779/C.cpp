#include <iostream>
#include <algorithm>

using namespace std;

int const nmax = 200000;

#define ll long long

struct Price{
  int x;
  int y;
  bool operator < (Price const &a) const{
    return x - y < (a.x - a.y);
  }
};

Price v[5 + nmax];

int main()
{
  int n , k;
  cin >> n >> k;
  for(int i = 1 ; i <= n ; i++){
    cin >> v[i].x;
  }
  for(int i = 1 ; i <= n ; i++){
    cin >> v[i].y;
  }
  sort(v + 1 , v + n + 1);

  ll result = 0;
  for(int i = 1 ; i <= k ; i++){
    result += v[i].x;
  }

  for(int i = k + 1; i <= n ; i++){
    if(v[i].x <= v[i].y)
      result += v[i].x;
  }
  for(int i = k + 1; i <= n ; i++){
    if(v[i].x > v[i].y)
      result += v[i].y;
  }
  cout << result;
  return 0;
}