#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

#define ll long long
#define MIN(a ,b) (((a) < (b)) ? (a) : (b))
#define MAX(a ,b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
ll const inf = 100000000000000000;

ll v[5 + nmax];

ll cost[5 + nmax];
vector<ll> primes;

void decompose(ll n){
  for(ll i = 2 ; i * i <= n ; i++){
    if(n % i == 0){
      while(n % i == 0)
        n /= i;
      primes.push_back(i);
    }
  }
  if(1 < n)
    primes.push_back(n);
}

void normalize(int n){
  for(int i = 1 ; i <= n ; i++){
    ll result = 1;
    for(int j = 0 ; j < primes.size() ; j++) {
      while(v[i] % primes[j] == 0){
        v[i] /= primes[j];
        result *= primes[j];
      }
    }
    v[i] = result;
  }
}

bool compare(int x , int y){
  if(v[x] != v[y])
    return v[x] < v[y];
  else
    return cost[x] < cost[y];
}

bool compareonlycost(int x , int y){
  return cost[x] < cost[y];
}

int ind[5 + nmax];
ll expp[5 + nmax][11];

ll getexp(ll n , ll val){
  ll result = 1;
  while(n % val == 0){
    n /= val;
    result *= val;
  }
  return result;
}

vector<ll> best[1 << 11];
vector<ll> uses[5 + nmax];

ll dp[2][(1 << 11)][12];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n , k;
  cin >> n >> k;
  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];
  for(int i = 1 ; i <= n ; i++)
    cin >> cost[i];

  ll result = v[1];
  for(int i = 1 ; i <= n ; i++)
    result = __gcd(result , v[i]);
  if(result == 1){
    cout << 0;
    return 0;
  }
  decompose(result);

  normalize(n);

  for(int i = 1 ; i <= n ; i++)
    ind[i] = i;
  sort(ind + 1 , ind + n + 1 , compare);
  int scount = 0;

  for(int i = 1 ; i <= n ; i++)
    for(int h = 0 ; h < primes.size() ;h++)
      expp[i][h] = getexp(v[i] , primes[h]);

  for(int i = 1 ; i <= n ; i++){
    if(v[ind[i - 1]] == v[ind[i]])
      scount++;
    else
      scount = 1;
    if(scount <= primes.size()) {
      for(int j = 0 ; j < (1 << primes.size()) ; j++){
        ll result = 1;
        for(int h = 0 ;h < primes.size() ; h++) {
          if(0 < (j & (1 << h)))
            result = result * expp[ind[i]][h];
        }

        if(result <= k)
          best[j].push_back(ind[i]);
      }
    }
  }

  for(int mask = 1 ; mask < (1 << primes.size()) ; mask++) {
    sort(best[mask].begin() , best[mask].end() , compareonlycost);
    for(int j = 0 ; j < MIN(primes.size() , best[mask].size()) ; j++){
      uses[best[mask][j]].push_back(mask);
    }
  }

  //assert(n < 1000000);

  int st = 0;
  scount = 0;
  result = inf;
  for(int i = 0 ; i < 2 ; i++)
    for(int j = 0 ; j < (1 << primes.size()) ; j++)
      for(int h = 0 ; h <= primes.size() ; h++)
        dp[i][j][h] = inf;

  dp[0][0][0] = 0;

  for(int i = 1 ; i <= n ; i++){
    if(v[ind[i - 1]] == v[ind[i]])
      scount++;
    else
      scount = 1;

    if(scount <= primes.size()) {
      ++st;
      for(int j = 0 ; j < (1 << primes.size()) ; j++){
        for(int h = 0 ; h <= primes.size() ; h++)
          dp[st & 1][j][h] = MIN(dp[st & 1][j][h] , dp[(st - 1) & 1][j][h]);
        for(int h = 0 ; h < uses[ind[i]].size() ; h++){
          for(int h2 = 0 ; h2 < primes.size() ; h2++){
            dp[st & 1][j | uses[ind[i]][h]][h2 + 1] = MIN(dp[st & 1][j | uses[ind[i]][h]][h2 + 1], dp[(st - 1) & 1][j][h2] + cost[ind[i]] );
          }
        }
      }
    }
  }
/*

*/

  for(int i = 1 ; i <= primes.size() ; i++) {
    result = MIN(result , dp[st & 1][(1 << primes.size()) - 1][i] * i);
  }
  if(result == inf)
    cout << -1;
  else
    cout << result;

  return 0;
}