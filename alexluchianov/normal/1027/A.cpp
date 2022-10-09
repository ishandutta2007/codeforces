#include <iostream>
#include <cmath>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for(int testcase = 1;testcase <= t ; testcase++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "#" + s;
    bool ok = 0;
    for(int i = 1 ; i <= n ; i++){
      if(!((s[i] - s[n - i + 1]) == 0 || fabs(s[i] - s[n - i + 1]) == 2))
        ok = 1;
    }
    if(ok == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}