#include <iostream>
#include <bitset>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 70;
int const lgmax = 20;
int const modulo = 1000000007;

int primes[1 + lgmax] = {2, 3 ,5,7,11,13,17,19,23,29 ,31 ,37 ,41, 43, 47, 53, 57, 59, 61, 67};
int frec[1 + nmax];
int dp[2][1 + (1 << lgmax)];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie();
  int n;
  cin >> n;

  for(int i = 1;i <= n; i++) {
    int a;
    cin >> a;
    frec[a]++;
  }

  dp[0][0] = 1;

  for(int i = 1; i <= nmax; i++){
    int maskval = 0, val = i;
    int coef1 = 1, coef2 = 0;

    for(int j = 1;j <= frec[i]; j++){
      int aux = coef1;
      coef1 = (coef1 + coef2) % modulo;
      coef2 = (aux + coef2) % modulo;
    }

    for(int j = 0; j < lgmax; j++) {
      while(val % primes[j] == 0){
        val /= primes[j];
        maskval ^= (1 << j);
      }
    }

    int era = (i & 1);

    for(int mask = 0; mask < (1 << lgmax); mask++)
      dp[era][mask] = (1LL * dp[era ^ 1][mask] * coef1 % modulo + 1LL * dp[era ^ 1][mask ^ maskval] * coef2) % modulo;
  }
  cout << (dp[0][0] + modulo - 1) % modulo;

  return 0;
}