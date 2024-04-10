#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
int const sigma = 26;
int seen[1 + sigma];

void solve(){
  for(int i = 0; i < sigma; i++)
    seen[i] = 0;

  string s;
  cin >> s;
  s += "#";
  int sum = 1;
  for(int i = 1; i < s.size(); i++){
    if(s[i - 1] == s[i])
      sum++;
    else if(sum % 2 == 1) {
      seen[s[i - 1] - 'a'] = 1;
      sum = 1;
    } else
      sum = 1;
  }
  for(int i = 0; i < sigma; i++)
    if(seen[i] == 1)
      cout << char('a' + i);
  cout << '\n';
}

int main()
{
  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}