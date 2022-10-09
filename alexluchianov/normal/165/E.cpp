#include <iostream>

using namespace std;

#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const limmask = (1 << 22) - 1;
int v[5 + nmax];
int dp[5 + limmask];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n ;
  cin >> n;
  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];
  for(int mask = 0 ; mask <= limmask ; mask++)
    dp[mask] = -1;

  for(int i = 1 ; i <= n ; i++){
    int a = limmask ^ v[i];
    dp[a] = v[i];
  }

  for(int mask = limmask ; 0 <= mask ; mask--){
    if(0 < dp[mask]) {
      for(int j = 0 ; j < 22 ; j++){
        if(0 < (mask & (1 << j))){
          dp[mask ^ (1 << j)] = MAX(dp[mask ^ (1 << j)] , dp[mask]);
        }
      }
    }
  }

  for(int i = 1 ; i <= n ; i++)
    cout << dp[v[i]] << " " ;

  return 0;
}