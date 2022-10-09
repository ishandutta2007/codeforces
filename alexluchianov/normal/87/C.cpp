#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int dp[1 + nmax];
int sum[1 + nmax];
int mv[1 + nmax];

int mex(vector<int> v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for(int i = 0; i < v.size(); i++){
    if(v[i] != i)
      return i;
  }
  return v.size();
}

int gauss(int start, int stop){
  return (start + stop) * (stop - start + 1) / 2;
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++){
    vector<int> v;
    for(int j = 2;j <= n; j++){
      int sz = (i - j * (j - 1) / 2) / j;

      if(0 < sz && gauss(sz, sz + j - 1) == i){
        v.push_back((sum[sz + j - 1] ^ sum[sz - 1]));
        if((sum[sz + j - 1] ^ sum[sz - 1]) == 0 && mv[i] == 0)
          mv[i] = j;
      } else if(i < gauss(sz, sz + j - 1))
        break;
    }
    dp[i] = mex(v);
    sum[i] = sum[i - 1] ^ dp[i];
  }
  if(dp[n] == 0)
    cout << -1;
  else
    cout << mv[n];
  return 0;
}