#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <map>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100;
int v[1 + nmax];

map<int,int> dp;

int mex(vector<int> v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for(int i = 0; i < v.size(); i++)
    if(v[i] != i)
       return i;
  return v.size();
}

int computedp(int mask){
  map<int,int>::iterator it = dp.find(mask);
  if(it != dp.end())
    return it->second;

  vector<int> v;
  for(int i = 1;(1 << i) <= mask; i++){
    int newmask = ((mask & ((1 << i) - 1)) | (mask >> i));
    v.push_back(computedp(newmask));
  }
  dp[mask] = mex(v);
  return dp[mask];
}

map<int,int> frec;

void decompose(int number){
  for(int i = 2;i * i <= number; i++){
    if(number % i == 0){
      int p = 0;
      while(number % i == 0){
        number /= i;
        p++;
      }
      frec[i] |= (1 << p);
    }
  }
  if(1 < number)
    frec[number] |= 2;
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= n; i++)
    decompose(v[i]);

  int result = 0;
  for(map<int,int>::iterator it = frec.begin(); it != frec.end(); it++) {
    result ^= computedp(it->second | 1);
  }

  if(result == 0)
    cout << "Arpa";
  else
    cout << "Mojtaba";

  return 0;
}