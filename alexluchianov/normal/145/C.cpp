#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int const nmax = 100000;
int const modulo = 1000000007;
int v[5 + nmax];

bool valid(int n){
  while(0 < n){
    if(n % 10 != 4 && n % 10 != 7)
      return 0;
    n /= 10;
  }
  return 1;
}

int fact[5 + nmax];

void computefact(){
  fact[0] = 1;
  for(int i = 1 ; i <= nmax; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;
}

void gcd(int a , int b , int &x , int &y){
  if(b == 0){
    x = 1;
    y = 0;
  } else{
    gcd(b , a % b , x , y);
    int aux = x;
    x = y;
    y = aux - a / b * y;
  }
}

int comb(int n , int k){
  if(k <= 0)
    return 1;
  if(n < k)
    return 0;

  int result = fact[n];
  int result2 = 1LL * fact[k] * fact[n - k] % modulo;
  int x , y;
  gcd(result2 , modulo , x , y);
  x %= modulo;
  if(x < 0)
    x += modulo;
  return 1LL * result * x % modulo;
}

int lucky[5 + nmax];
int luckp = 0;
unordered_map<int , int> frec;

int dp[5 + nmax];
int dp2[5 + nmax];

///dp[i][j] = j elements subset chosen from the first i elements
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  computefact();
  int n , k;
  cin >> n >> k;
  int others = 0;
  for(int i = 1 ; i <= n ; i++){
    int a;
    cin >> a;
    if(valid(a) == 1){
      frec[a]++;
      if(1 == frec[a])
        lucky[++luckp] = a;
    } else
      others++;
  }
  sort(lucky + 1, lucky + luckp + 1);
  dp[0] = 1;
  for(int i = 1 ; i <= luckp ; i++){
    dp2[0] = dp[0];
    for(int j = 1 ; j <= i ; j++){
      dp2[j] = (dp[j] + 1LL * dp[j - 1] * frec[lucky[i]]) % modulo;
    }
    for(int j = 0 ; j <= k ; j++) {
      dp[j] = dp2[j];
      dp2[j] = 0;
    }
  }
  int result = 0;
  for(int i = 0 ; i <= luckp ;i++){
    result += 1LL * dp[i] * comb(others , k - i) % modulo;
    if(modulo <= result)
      result -= modulo;
  }
  cout << result;
  return 0;
}