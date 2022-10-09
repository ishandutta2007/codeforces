#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = (1 << 22) * 2;
int v[1 + nmax];
int dp[1 + nmax];

int active[1 + nmax];
int mult[1 + nmax];

int jump(int a){
  if(a != mult[a])
    mult[a] = jump(mult[a]);
  return mult[a];
}

void addEdge(int x, int y){
  if(active[x] && active[y] == 1){
    x = jump(x);
    y = jump(y);
    if(x != y)
      mult[x] = y;
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < (1 << n) * 2; i++)
    mult[i] = i;

  int lim = (1 << n) - 1;
  for(int i = 1;i <= m; i++) {
    cin >> v[i];
    dp[v[i]] = 1;
  }

  for(int mask = 0; mask < (1 << n); mask++){
    for(int i = 0; i < n; i++)
      if(0 < (mask & (1 << i)))
        dp[mask] |= dp[mask ^ (1 << i)];
  }

  for(int mask = 0; mask < (1 << n); mask++)
    active[(1 << n) + mask] = dp[mask] & dp[lim ^ mask];

  for(int i = 1;i <= m; i++) {
    active[v[i]] = 1;
    addEdge(v[i], (1 << n) + v[i]);
    addEdge(v[i], (1 << n) + (lim ^ v[i]));
  }

  for(int mask = 0; mask < (1 << n); mask++)
    for(int i = 0; i < n; i++)
      if(0 < (mask & (1 << i)))
        addEdge((1 << n) + mask, (1 << n) + (mask ^ (1 << i)));


  int result = 0;
  for(int mask = 0; mask < 2 * (1 << n); mask++)
    if(active[mask] == 1)
      if(mult[mask] == mask)
        result++;
  cout << result;
  return 0;
}