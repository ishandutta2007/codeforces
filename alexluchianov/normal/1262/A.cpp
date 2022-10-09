#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const inf = 1000000000;

void solve(){
  int n;
  cin >> n;
  int x = inf, y = 0;
  for(int i = 1;i <= n; i++){
    int l, r;
    cin >> l >> r;
    x = MIN(x, r);
    y = MAX(y, l);
  }
  if(x <= y)
    cout << y - x << '\n';
  else
    cout << 0 << '\n';
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