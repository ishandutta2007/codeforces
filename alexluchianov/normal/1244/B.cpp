#include <iostream>
#include <fstream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve(){
  int n;
  cin >> n;
  int smax = n;
  for(int i = 1;i <= n; i++) {
    char a;
    cin >> a;
    if(a == '1') {
      smax = max(smax, i * 2);
      smax = max(smax, (n - i + 1) * 2);
    }
  }
  cout << smax << '\n';
}

int main()
{
  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}