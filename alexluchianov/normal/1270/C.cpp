#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;

void solve(){
  int n;
  cin >> n;
  ll sum = 0, xorp = 0, val;

  for(int i = 1;i <= n; i++){
    cin >> val;
    sum += val;
    xorp ^= val;
  }
  cout << 3 << '\n';

  if(sum % 2 == 1)
    val = (1LL << 55) + 1;
  else
    val = (1LL << 55);

  sum += val;
  xorp ^= val;

  cout << val << " " << (xorp * 2 - sum) / 2 << " " << (xorp * 2 - sum) / 2 << '\n';
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