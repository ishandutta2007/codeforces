#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const lgmax = 20;
int const inf = 1000000000;

map<int,int> frec;

int lg[1 + nmax];
int v[1 + nmax];
int jump[1 + nmax];
int dp[1 + nmax];
int rmq[20][1 + nmax];

int solveinterval(int x, int y){
  int h = lg[y - x];
  return MIN(rmq[h][x], rmq[h][y - (1 << h) + 1]);
}

int main()
{
  lg[1] = 0;
  for(int i = 2;i <= nmax; i++)
    lg[i] = lg[i / 2] + 1;

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];

  int start, stop;
  cin >> stop >> start;

  for(int i = start; i <= stop; i++) {
    jump[i - start] = 1;
    dp[i - start] = inf;
  }

  dp[stop - start] = 0;
  for(int h = 0; h < lgmax; h++)
    rmq[h][stop - start] = 0;

  for(int i = 1;i <= n; i++){
    if(frec[v[i]] == 0){
      frec[v[i]] = 1;
      int start2 = (((start - 1) / v[i]) + 1) * v[i];
      while(start2 <= stop){
        jump[start2 - start] = MAX(jump[start2 - start], v[i] - 1);
        start2 += v[i];
      }
    }
  }

  int lim = stop - start;

  for(int i = stop - 1; start <= i; i--){
    int pos = i - start;
    dp[pos] = solveinterval(pos + 1, MIN(lim, pos + jump[pos])) + 1;
    rmq[0][pos] = dp[pos];
    for(int h = 1; h < lgmax; h++)
      rmq[h][pos] = MIN(rmq[h - 1][pos], rmq[h - 1][pos + (1 << (h - 1))]);
  }
  cout << dp[0];
  return 0;
}