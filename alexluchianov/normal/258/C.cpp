#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int const nmax = 100000;
int const modulo = 1000000007;

int v[1 + nmax];
int sum[1 + nmax];

vector<int> divisors(int number){
  vector<int> div;
  for(int i = 1;i * i <= number; i++)
    if(number % i == 0) {
      div.push_back(i);
      if(i != number / i)
        div.push_back(number / i);
    }
  return div;
}


int lgpow(int a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else{
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int solve(int number){
  vector<int> div = divisors(number);
  sort(div.begin(), div.end());

  ll result = 1, result2 = 1;

  for(int i = 0; i < div.size() - 1; i++){
    result = 1LL * result * lgpow(i + 1, sum[div[i + 1] - 1] - sum[div[i] - 1]) % modulo;
    result2 = result;
  }

  result = 1LL * result * lgpow(div.size() - 1, sum[nmax] - sum[div.back() - 1]) % modulo;
  result2 = 1LL * result2 * lgpow(div.size() , sum[nmax] - sum[div.back() - 1]) % modulo;
  return (modulo + result2 - result) % modulo;
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= n; i++)
    sum[v[i]]++;
  for(int i = 1;i <= nmax; i++)
    sum[i] += sum[i - 1];
  ll result = 0;
  for(int i = 1;i <= nmax; i++) {
    result += solve(i);
    if(modulo <= result)
      result -= modulo;
  }
  cout << result;

  return 0;
}