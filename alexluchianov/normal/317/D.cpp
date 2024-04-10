#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int grundys[30] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};

int mex(vector<int> v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for(int i = 0; i < v.size(); i++)
    if(i != v[i])
      return i;
  return v.size();
}

map<int,int> dp;
int grundy(int n, int mask){
  if(dp.find(mask) != dp.end())
    return dp[mask];
  if(mask == (1 << n) - 1)
    dp[mask] = 0;
  else {
    vector<int> sol;
    for(int i = 1;i <= n; i++){
      int mask2 = 0;
      for(int j = i; j <= n; j += i)
        mask2 |= (1 << (j - 1));
      if(mask != (mask | mask2))
        sol.push_back(grundy(n, mask | mask2));
    }
    dp[mask] = mex(sol);
  }
  return dp[mask];
}

map<int,int> frec;

int main()
{
  int n;
  cin >> n;
  int result = 0, unnacounted = n;
  for(int i = 2;i * i <= n; i++){
    if(frec[i] == 0){
      int l = 0;
      for(ll j = i; j <= n; j = j * i){
        l++;
        frec[j] = 1;
        unnacounted--;
      }
      result ^= grundys[l];
    }
  }
  if(unnacounted % 2 == 1)
    result ^= grundys[1];

  if(result == 0)
    cout << "Petya\n";
  else
    cout << "Vasya\n";
  return 0;
}