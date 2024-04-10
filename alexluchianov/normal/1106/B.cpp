#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[5 + nmax];
int cost[5 + nmax];
int ind[5 + nmax];

bool compare(int x , int y){
  if(cost[x] != cost[y])
    return cost[x] < cost[y];
  else
    return x < y;
}

int main()
{
  int n, m;
  cin >> n >> m;

  for(int i = 1 ; i <= n ; i++) {
    cin >> v[i];
    ind[i] = i;
  }

  for(int i = 1 ; i <= n ; i++)
    cin >> cost[i];
  sort(ind + 1 , ind + n + 1, compare);
  int st = 1;
  for(int i = 1 ; i <= m ; i++){
    int d , t;
    cin >> t >> d;
    ll result = 0;
    int val = MIN(v[t] , d);
    v[t] -= val;
    d -= val;
    result += 1LL * val * cost[t];

    while(st <= n && 0 < d){
      t = ind[st];

      int val = MIN(v[t] , d);
      v[t] -= val;
      d -= val;
      result += 1LL * val * cost[t];
      if(v[t] == 0)
        st++;
    }
    if(0 < d)
      result = 0;
    cout << result << '\n';
  }
  return 0;
}