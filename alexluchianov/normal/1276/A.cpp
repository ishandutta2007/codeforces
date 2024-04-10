#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;

void solve(){
  string s;
  cin >> s;
  int ptr = 0;

  vector<int> sol;
  while(ptr < s.size()){
    if(s[ptr] == 't' && s[ptr + 1] == 'w' && s[ptr + 2] == 'o' && s[ptr + 3] == 'n' && s[ptr + 4] == 'e') {
      sol.push_back(ptr + 2);
      ptr += 3;
    } else if(s[ptr] == 't' && s[ptr + 1] == 'w' && s[ptr + 2] == 'o'){
      sol.push_back(ptr + 1);
      ptr += 2;
    } else if(s[ptr] == 'o' && s[ptr + 1] == 'n' && s[ptr + 2] == 'e'){
      sol.push_back(ptr + 1);
      ptr += 2;
    } else
      ptr++;
  }
  cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    cout << 1 + sol[i] << " ";
  cout << '\n';

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