#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve(){
  string s;
  cin >> s;
  int sum = 0, even = 0, zero = 0;
  for(int i = 0; i < s.size(); i++){
    sum += s[i] - '0';
    if(s[i] == '0')
      zero++;
    if((s[i] - '0') % 2 == 0)
      even++;
  }
  if(sum % 3 == 0 && 1 <= zero && (2 <= even || s.size() == 1))
    cout << "red\n";
  else
    cout << "cyan\n";
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