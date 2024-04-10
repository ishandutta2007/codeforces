#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

string s, emp;

void solve(){
  int n, k;
  cin >> n >> k;
  cin >> s;
  sort(s.begin(), s.end());
  s = "#" + s;
  if(s[1] == s[k]) {
    if(s[k + 1] != s[n])
      cout << s[1] + s.substr(k + 1, s.size() - k - 1) << '\n';
    else{
      string sol = emp + s[1];
      for(int i = k + 1; i <= n; i += k)
        sol += s[i];
      cout << sol << '\n';
    }
  } else
    cout << s[k] << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}