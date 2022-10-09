#include <iostream>

using namespace std;

using ll = long long;
int const nmax = 100000;
ll const inf = 1000000000000;

ll v[1 + nmax], color[1 + nmax];
ll dp[1 + nmax];

ll solve(int n, int a , int b){
  for(int i = 1;i <= n;i++)
    dp[i] = -inf;
  dp[0] = 0;
  ll smax1 = 0, scolor1 = 0;
  ll smax2 = 0, scolor2 = 0;
  for(int i = 1;i <= n; i++){
    ll newdp = dp[color[i]] + v[i] * a;

    if(scolor1 == color[i])
      newdp = max(newdp, smax2 + v[i] * b);
    else
      newdp = max(newdp, smax1 + v[i] * b);
    dp[color[i]] = max(dp[color[i]], newdp);

    if(smax1 < dp[color[i]]){
      if(scolor1 == color[i])
        smax1 = dp[color[i]];
      else{
        smax2 = smax1;
        scolor2 = scolor1;
        smax1 = dp[color[i]];
        scolor1 = color[i];
      }
    } else {
      if(scolor1 != color[i]){
        if(smax2 < dp[color[i]]){
          smax2 = dp[color[i]];
          scolor2 = color[i];
        }
      }
    }
  }
  return smax1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n >> q;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= n; i++)
    cin >> color[i];

  for(int i = 1;i <= q; i++){
    int a, b;
    cin >> a >> b;
    cout << solve(n, a, b) << '\n';
  }
  return 0;
}