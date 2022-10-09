#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define ll long long

int const nmax = 10000;
ll divs[5 + nmax];
int divp = 0;

void decompose(ll n){
  for(int i = 1 ; 1LL * i * i <= n ; i++){
    if(n % i == 0){
      divs[++divp] = i;
      if(n / i != i)
        divs[++divp] = n / i;
    }
  }
  sort(divs + 1 , divs + divp + 1);
}

int dp[5 + nmax];

int mex( set < int > myset){
  int p = 0;
  while(myset.find(p) != myset.end())
    p++;
  return p;
}

int main()
{
  ll n;
  cin >> n;
  decompose(n);
  dp[1] = 1;
  for(int i = 2; i <= divp; i++){
    set<int> myset;
    bool ok = 0;
    for(int j = 2; j < i ; j++){
      if(divs[i] % divs[j] == 0){
        myset.insert(dp[j]);
        ok = 1;
      }
    }
    if(ok == 1)
      dp[i] = mex(myset);
    else
      dp[i] = 1;
  }
  if(dp[divp] != 0) {
    cout << "1\n";
    for(int j = 2 ; j < divp ;j++){
      if(n % divs[j] == 0 && dp[j] == 0){
        cout << divs[j];
        return 0;
      }
    }
    cout << 0;
  } else
    cout << "2";
  return 0;
}