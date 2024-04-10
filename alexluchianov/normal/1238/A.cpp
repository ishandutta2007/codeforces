#include <iostream>

using namespace std;

#define ll long long

void solve(){
  ll x, y;
  cin >> x >> y;
  if(y + 1 < x)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main()
{
  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();

  return 0;
}