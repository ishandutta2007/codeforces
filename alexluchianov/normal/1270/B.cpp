#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[1 + nmax];

void solve(){
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i < n; i++)
    if(2 <= fabs(v[i + 1] - v[i])){
      cout << "YES\n";
      cout << i << " " << i + 1 << '\n';
      return ;
    }
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