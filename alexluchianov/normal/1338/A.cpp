#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;

int lg(int val){
  if(val <= 0)
    return 0;
  for(int i = 0;i <= 30; i++){
    val -= (1 << i);
    if(val <= 0)
      return i + 1;
  }
  return 32;
}

void solve(){
  int n;
  cin >> n;
  vector<int> sol;
  int result = 0;
  for(int i = 1;i <= n; i++){
    int val;
    cin >> val;
    while(0 < sol.size() && sol.back() <= val)
      sol.pop_back();
    sol.push_back(val);
    result = max(result, lg(sol[0] - val));
  }
  cout << result << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}