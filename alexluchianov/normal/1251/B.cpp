#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve(){
  int n;
  cin >> n;

  int zero = 0, one = 0, odd = 0;
  for(int i = 1;i <= n; i++){
    string s;
    cin >> s;
    if(s.size() % 2 == 1)
      odd++;
    for(int j = 0; j < s.size(); j++)
      if(s[j] == '0')
        zero++;
      else
        one++;
  }
  if(one % 2 == 1)
    odd--;
  if(zero % 2 == 1)
    odd--;

  if(0 <= odd && odd % 2 == 0)
    cout << n << '\n';
  else
    cout << n - 1 << '\n';
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