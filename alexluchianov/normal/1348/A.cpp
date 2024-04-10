#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve(){
  int n;
  cin >> n;
  ll result = 0;
  for(int i = 1;i <= n; i++){
    if(i < n / 2 || i == n)
      result += (1 << i);
    else
      result -= (1 << i);
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