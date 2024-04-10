#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <unordered_map>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 1000000;
mt19937 rng;
ll v[1 + nmax];

int random(int n){
  return uniform_int_distribution<int>(1, n)(rng);
}

vector<ll> divisors(ll val){
  vector<ll> sol;
  for(int i = 1;1LL * i * i <= val; i++)
    if(val % i == 0){
      sol.push_back(i);
      sol.push_back(val / i);
    }
  sort(sol.begin(), sol.end());
  sol.erase(unique(sol.begin(), sol.end()), sol.end());
  return sol;
}

int dp[1 + nmax];
unordered_map<ll,int> frec;
unordered_map<ll, int> seen;

ll result = 1;

void extract(ll val, int n){
  vector<ll> sol = divisors(val);
  frec.clear();
  for(int i = 1;i <= n; i++)
    frec[__gcd(v[i], val)]++;

  for(int i = 0; i < sol.size(); i++)
    dp[i] = frec[sol[i]];
  for(int i = sol.size() - 1; 0 <= i; i--) {
    if(sol[i] < result)
      return ;
    ll result2 = 0;
    for(int j = i; j < sol.size(); j++)
      if(sol[j] % sol[i] == 0)
        result2 += dp[j];
    if((n + 1) / 2 <= result2){
      result = sol[i];
      return ;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= 10; i++){
    int pos = random(n);
    if(seen[v[pos]] == 0) {
      seen[v[pos]] = 1;
      extract(v[pos], n);
    }
  }
  cout << result;

  return 0;
}