#include <iostream>

#define ll long long
#define MAX(a , b) (((a) < (b)) ? (b) : (a))
#define MIN(a , b) (((a) < (b)) ? (a) : (b))

using namespace std;

int const nmax = 1000000;

ll const inf = 1LL * nmax * nmax + 5;

int v[5 + nmax];
int cost[5 + nmax];
int st[5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie();
  cout.tie();

  int n , m , k;
  cin >> n >> m >> k;
  for(int i = 1 ; i <= m ;i++){
    int a;
    cin >> a;
    v[a] = 1;
  }
  if(v[0] == 1) {
    cout << -1 << '\n';
    return 0;
  }

  for(int i = 0; i < n ;i++){
    if(0 < i && v[i] == 1)
      st[i] = st[i - 1];
    else
      st[i] = i;
  }

  for(int i = 1 ; i <= k ;i++)
    cin >> cost[i];
  ll smin = inf;
  for(int i = 1 ; i <= k ;i++){
    ll totalcost = cost[i];
    int last = 0;
    while(last + i < n){
      if(last < st[last + i] ){
        last = st[last + i];
        totalcost += cost[i];
      } else{
        totalcost = inf;
        break;
      }
    }

    smin = MIN(smin , totalcost);
  }
  if(smin < inf)
    cout << smin;
  else
    cout << -1;
  return 0;
}