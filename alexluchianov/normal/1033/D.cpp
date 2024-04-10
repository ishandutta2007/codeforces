#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

#define ll long long

int const nmax = 1000;
int const lim = 2000000;
ll const modulo = 998244353;

ll v[5 + nmax];
int seen[5 + nmax];

map<ll , ll> frec;

vector <ll> fact;
vector <ll> fact2;

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++) {
    cin >> v[i];

    ll rad = sqrt(v[i]);
    if(rad * rad == v[i]){
      ll rad2 = sqrt(rad);

      v[i] = 1;

      if(rad2 * rad2 == rad){
        frec[rad2] += 4;
        fact.push_back(rad2);
      } else {
        frec[rad] += 2;
        fact.push_back(rad);
      }
      //seen[i] = 1;
    } else{
      rad = cbrt(v[i]);
      if(rad * rad * rad == v[i]) {
        fact.push_back(rad);
        frec[rad] += 3;
        v[i] = 1;
      } else {
        rad++;
        if(rad * rad * rad == v[i]) {
          fact.push_back(rad);
          frec[rad] += 3;
          v[i] = 1;
        } else
          seen[i] = 2;
      }
    }
  }
  for(int i = 1 ; i <= n ; i++){
    for(int j = i + 1 ; j <= n ; j++){
      if(1 < __gcd(v[i] , v[j]) && __gcd(v[i] , v[j]) < v[j] && __gcd(v[i] , v[j]) < v[i]) {
        ll val = __gcd(v[i] , v[j]);
        v[i] /= val;
        v[j] /= val;

        fact.push_back(val);
        frec[val] += 2;
        seen[i]--;
        seen[j]--;
      }
    }
  }


  for(int i = 0 ; i < fact.size() ; i++){
    for(int j = 1 ; j <= n ; j++){
      while(1 < v[j] && v[j] % fact[i] == 0){
        v[j] /= fact[i];

        seen[j]--;

        frec[fact[i]]++;
      }
    }
  }

  for(int i = 1 ; i <= n ; i++){
    if(seen[i] == 1 && 1 < v[i]){
      fact.push_back(v[i]);
      frec[v[i]]++;
      v[i] = 1;
    }
  }

  for(int i = 0 ; i < fact.size() ; i++){
    for(int j = 1 ; j <= n ; j++){
      while(1 < v[j] && v[j] % fact[i] == 0){
        v[j] /= fact[i];

        seen[j]--;

        frec[fact[i]]++;
      }
    }
  }

  for(int i = 1 ; i <= n ; i++){
    if(1 < v[i] && seen[i] == 2){
      fact2.push_back(v[i]);
      frec[v[i]]++;
      v[i] = 1;
    } else if(1 < v[i] && seen[i] == 1){
      fact.push_back(v[i]);
      frec[v[i]]++;
      v[i] = 1;
    }
  }
  ll result = 1;

  for(int i = 0 ; i < fact.size() ; i++){
    //cout << fact[i] << " " << frec[fact[i]] << '\n';
    result = result * (frec[fact[i]] + 1) % modulo;
    frec[fact[i]] = 0;

  }



  for(int i = 0 ; i < fact2.size() ; i++){
    result = result * (frec[fact2[i]] + 1 ) % modulo;
    result = result * (frec[fact2[i]] + 1 ) % modulo;
    frec[fact2[i]] = 0;
  }
  cout << result << '\n';

  cout.flush();

  return 0;
}
/*
4
6
35
143
4
*/

/*
2 3
3 1
5 1
7 1
11 1
13 1
*/