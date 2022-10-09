#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve(){
  int a, b;
  cin >> a >> b;
  if(__gcd(a, b) == 1)
    cout << "Finite\n";
  else
    cout << "Infinite\n";
}

int main()
{
  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}