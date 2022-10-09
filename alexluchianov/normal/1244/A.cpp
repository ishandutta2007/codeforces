#include <iostream>
#include <fstream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve(){
  int a, b, c, d, k;
  cin >> a >> b >> c >> d >> k;
  int x = (a - 1) / c + 1;
  int y = (b - 1) / d + 1;
  if(x + y <= k)
    cout << x << " " << y << '\n';
  else
    cout << -1 << '\n';
}

int main()
{
  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}