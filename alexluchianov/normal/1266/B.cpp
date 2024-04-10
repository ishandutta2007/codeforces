#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve(){
  ll n;
  cin >> n;
  for(int i = 1;i <= 6; i++) {
    if(0 <= (n - (6 * 7 / 2) + i) && (n - (6 * 7 / 2) + i) % 14 == 0) {
      cout << "YES\n";
      return ;
    }
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