#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
int const modulo = 998244353;

int dp[1 + nmax][1 + nmax];
int startbig[1 + nmax], stopbig[1 + nmax];

int n, m;
int v[1 + nmax];
int v2[1 + nmax], m2 = 0;

void normalize(){
  for(int i = 1;i <= m; i++)
    if(v[i - 1] != v[i])
      v2[++m2] = v[i];
  m = m2;
  for(int i = 1;i <= m; i++)
    v[i] = v2[i];

}



int solve(int from, int to){
  if(to < from)
    return 1;


  if(0 <= dp[from][to]) {
    return dp[from][to];
  } else {
    dp[from][to] = 0;

    for(int i = from; i <= to; i++)
      if(startbig[v[i]] < from || to < stopbig[v[i]])
        return 0;

    ll result = 0;
    int smin = from, start = from, stop = from;
    for(int i = from; i <= to; i++) {
      if(v[i] < v[smin]) {
        smin = i;
        start = stop = i;
      } else if(v[i] == v[smin]){
        stop = i;
      }
    }
    for(int i = from; i <= start; i++) {
      result += 1LL * solve(from, i - 1) * solve(i, start - 1) % modulo;
      if(modulo <= result)
        result -= modulo;
    }


    for(int i = stop; i <= to; i++) {
      dp[from][to] += 1LL * result * (1LL * solve(stop + 1, i) * solve(i + 1, to) % modulo) % modulo;
      if(modulo <= dp[from][to])
        dp[from][to] -= modulo;
    }

    for(int i = from; i <= to; i++)
      if(v[i] == v[smin]){
        dp[from][to] = 1LL * dp[from][to] * solve(start + 1, i - 1) % modulo;
        start = i;
      }


    return dp[from][to];
  }
}

int main()
{
  cin >> n >> m;
  for(int i = 1;i <= m; i++)
    cin >> v[i];
  normalize();

  if(m <= n * 2) {
    for(int i = 1; i <= m; i++) {
      stopbig[v[i]] = i;
      if(startbig[v[i]] == 0)
        startbig[v[i]] = i;
    }

    for(int i = 1; i <= m ;i++)
      for(int j = 1; j <= m; j++)
        dp[i][j] = -1;
    cout << solve(1, m);
  }

  return 0;
}