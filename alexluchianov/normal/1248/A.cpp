#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve(){
  int n, m;
  cin >> n;
  ll result = 0, even = 0, odd = 0;

  for(int i = 1;i <= n; i++){
    int a;
    cin >> a;
    if(a % 2 == 0)
      even++;
    else
      odd++;
  }
  cin >> m;
  for(int i = 1;i <= m; i++){
    int a;
    cin >> a;
    if(a % 2 == 0)
      result += even;
    else
      result += odd;
  }
  cout << result << '\n';
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