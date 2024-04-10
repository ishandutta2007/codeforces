#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
void solve(){
  int n, k1, k2;
  cin >> n >> k1 >> k2;
  int win = 0, val;
  for(int i = 1;i <= k1; i++){
    cin >> val;
    if(val == n)
      win = 1;
  }
  for(int i = 1;i <= k2; i++)
    cin >> val;
  if(win == 1)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}