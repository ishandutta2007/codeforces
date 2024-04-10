#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 3000000;
ll frec[5 + nmax];
ll sol[5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    int val;
    cin >> val;
    frec[val]++;
  }
  sol[0] = 1LL * n * (n - 1);
  for(int i = 1;i <= nmax; i++)
    for(int j = 1; j <= nmax / i; j++) {
      if(i == j) {
        sol[i * j + 1] -= (frec[i] * (frec[j] - 1));
      } else
        sol[i * j + 1] -= frec[i] * frec[j];
    }
  for(int i = 1;i <= nmax; i++)
    sol[i] += sol[i - 1];
  int q;
  cin >> q;
  for(int i = 1;i <= q; i++){
    int p;
    cin >> p;
    cout << sol[p] << '\n';
  }
  return 0;
}