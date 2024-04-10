#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e5;
const int P = 998244353;

vector<int> mu(maxn+5);
vector<ll> fact(maxn+5, 1);
vector<ll> invfact(maxn+5, 1);

int expmod(ll a, ll b, int m) {
  int res = 1;
  a = a % m; 
  if (a == 0) return 0;
  while (b > 0)
  {
    if (b & 1) {
      res = (res*a) % m;
    }
    b = b>>1;
    a = (a*a) % m;
  }
  return res;
}

int boxproblem(vector<int> bounds, int size, int m, int start) {
  int min_element = 1e9;
  int sum = 0;
  ll prod = 1;
  if (m < 0) return 0;
  for (int i = start; i < size; i++) {
    int val = bounds[i];
    min_element = min(min_element, val);
    sum += val;
    prod = (prod * (bounds[i]+1)) % P;
  }
  if (m >= sum) return prod;
  if (m <= min_element) {
    return (fact[m+size-start] * invfact[size-start] % P) * invfact[m] % P;
  }
  ll result = 0;
  for (int i = 0; i <= bounds[start]; i++) {
    result += boxproblem(bounds, size, m-i, start+1);
    result %= P;
  }
  return result;
}

ll solveD(vector<int>& lower, vector<int>& upper, int n, int m, int D) {
  vector<int> diffs(n);
  int newM = m/D;
  for (int i = 0; i < n; i++) {
    int new_lower = (lower[i]-1)/D + 1;
    int new_upper = upper[i]/D;
    if (new_lower > new_upper) return 0;
    diffs[i] = new_upper - new_lower;
    newM -= new_lower;
  }
  if (newM < 0) return 0;
  return boxproblem(diffs, n, newM, 0);
}

int main () {
  vector<bool> isprime(maxn+5, 1);
  for (int i = 2; i <= maxn; i++) {
    if (isprime[i]) {
      for (int j = 2*i; j <= maxn; j += i) {
        isprime[j] = 0;
      }
    }
  }
  vector<int> primes;
  for (int i = 2; i <= maxn; i++) {
    if (isprime[i]) primes.push_back(i);
  }
  mu[1] = 1;
  for (int i = 2; i <= maxn; i++) {
    for (int p: primes) {
      if (i % p == 0) {
        if (i/p % p == 0)  mu[i] = 0; 
        else mu[i] = -mu[i/p];
        break;
      }
    }
  }
  
  for (int i = 2; i <= maxn; i++) {
    fact[i] = i*fact[i-1] % P;
  }
  invfact[maxn] = expmod(fact[maxn], P-2, P);
  for (int i = maxn; i > 0; i--) {
    invfact[i-1]=i*invfact[i] % P;
  }

  int n, m;
  cin >> n >> m;
  vector<int> lower(n), upper(n);
  for (int i = 0; i < n; i++) {
    cin >> lower[i] >> upper[i];
  }
  ll result = 0;
  for (int d = 1; d <= maxn; d++) {
    if (mu[d]) result += mu[d]* solveD(lower, upper, n, m, d);
    result %= P;
  }
  if (result < 0) result += P;
  cout << result << endl;
}