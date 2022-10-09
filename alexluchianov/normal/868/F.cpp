#include <iostream>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
using ld = long double;

int const nmax = 100000;
int const kmax = 20;
ll const inf = 1000000000000000;

int v[1 + nmax];

namespace myset{
  ll result = 0;
  int frec[1 + nmax];
  void add(int val){
    result += frec[val];
    frec[val]++;
  }
  void eject(int val){
    frec[val]--;
    result -= frec[val];
  }
  ll getsol() {
    return result;
  }
}

ll dp[1 + kmax][1 + nmax];
int sol[1 + kmax][1 + nmax];

void eval(int pos, int x, int y, int era){
  dp[era][pos] = inf;
  y = min(y, pos);
  for(int i = y; x <= i; i--){
    myset::add(v[i]);
    if(dp[era - 1][i - 1] + myset::getsol() < dp[era][pos]){
      dp[era][pos] = dp[era - 1][i - 1] + myset::getsol();
      sol[era][pos] = i;
    }
  }
  for(int i = x; i <= y; i++)
    myset::eject(v[i]);
}

void divide(int from, int to, int x, int y, int era){
  if(from <= to){
    int mid = (from + to) / 2;

    for(int i = max(y + 1, from); i <= mid; i++)
      myset::add(v[i]);
    eval(mid, x, y, era);
    for(int i = max(y + 1, from); i <= mid; i++)
      myset::eject(v[i]);

    for(int i = sol[era][mid] + 1; i <= min(from - 1, y); i++)
      myset::add(v[i]);
    divide(from, mid - 1, x, sol[era][mid], era);
    for(int i = sol[era][mid] + 1; i <= min(from - 1, y); i++)
      myset::eject(v[i]);

    for(int i = max(y + 1, from); i < mid + 1; i++)
      myset::add(v[i]);
    divide(mid + 1, to, sol[era][mid], y, era);
    for(int i = max(y + 1, from); i < mid + 1; i++)
      myset::eject(v[i]);
  }
}

int main()
{
  int n, k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= n; i++){
    myset::add(v[i]);
    dp[1][i] = myset::getsol();
  }

  for(int i = n;1 <= i; i--)
    myset::eject(v[i]);
  for(int era = 2;era <= k; era++)
    divide(1, n, 1, n, era);
  cout << dp[k][n];
  return 0;
}