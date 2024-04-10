#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

int const nmax = 100;
int v[1 + nmax];

void solve(){
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  sort(v + 1, v + n + 1);
  int sol = 1;
  for(int i = 2;i <= n; i++)
    if(v[i - 1] + 1 == v[i])
      sol = 2;
  cout << sol << '\n';
}

int main()
{
  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}