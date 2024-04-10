#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((b) < (a)) ? (b) : (a))

int const nmax = 1000000;
int v[1 + nmax];

void normalize(int n){
  map<int,int> code;
  vector<int> temp;
  for(int i = 1; i <= n; i++)
    temp.push_back(v[i]);
  sort(temp.begin(), temp.end());
  code[temp[0]] = 1;
  for(int i = 1;i < temp.size(); i++)
    if(temp[i - 1] != temp[i])
      code[temp[i]] = code[temp[i - 1]] + 1;
  for(int i = 1;i <= n; i++)
    v[i] = code[v[i]];
}
int aib[1 + nmax];
void clearaib(){
  for(int i = 1;i <= nmax; i++)
    aib[i] = 0;
}

void update(int x, int val){
  if(x == 0)
    return ;
  while(x <= nmax){
    aib[x] += val;
    x += (x ^ (x & (x - 1)));
  }
}
int query(int x){
  int result = 0;
  while(0 < x){
    result += aib[x];
    x = x & (x - 1);
  }
  return result;
}
int dp[1 + nmax], dp2[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  normalize(n);
  ll result = 0;
  for(int i = 1;i <= n; i++){
    update(v[i], 1);
    dp[i] = (i - 1) - query(v[i] - 1);
  }
  clearaib();
  for(int i = n; 1 <= i; i--){
    update(v[i], 1);
    dp2[i] = query(v[i] - 1);
  }

  for(int i = 1;i <= n; i++)
    result += 1LL * dp[i] * dp2[i];
  cout << result;
  return 0;
}