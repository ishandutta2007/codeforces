#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[1 + nmax];
ll sum[1 + nmax];

map<int,ll> result;

ll solve(int n, int k){
  ll x = 0, level = 0;
  ll sz = 1, result = 0;
  while(x < n){
    result += 1LL * level * (sum[MIN(n, x + sz)] - sum[x] );
    x += sz;
    sz = sz * k;
    level++;
  }
  return result;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> v[i];
  sort(v + 1, v + n + 1);
  reverse(v + 1, v + n + 1);

  for(int i = 1;i <= n; i++)
    sum[i] = sum[i - 1] + v[i];

  cin >> q;
  for(int i = 1; i <= q; i++){
    int k;
    cin >> k;
    if(result[k] == 0)
      result[k] = solve(n, k);
    cout << result[k] << " ";
  }

  return 0;
}