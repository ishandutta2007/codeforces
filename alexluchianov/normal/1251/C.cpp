#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve(){
  vector<int> odd, even;
  string s;
  cin >> s;
  for(int i = 0; i < s.size(); i++){
    if(s[i] % 2 == 0)
      even.push_back(s[i] - '0');
    else
      odd.push_back(s[i] - '0');
  }
  int oddptr = 0, evenptr = 0;
  while(oddptr < odd.size() || evenptr < even.size()){
    if(oddptr == odd.size())
      cout << even[evenptr++];
    else if(evenptr == even.size())
      cout << odd[oddptr++];
    else if(odd[oddptr] < even[evenptr])
      cout << odd[oddptr++];
    else
      cout << even[evenptr++];
  }
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