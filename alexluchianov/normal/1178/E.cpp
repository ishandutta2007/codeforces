#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

string s;
string result;

int main()
{
  cin >> s;
  string result;
  int st = 0, dr = s.size() - 1;
  while(st + 1 < dr - 1){
    if(s[st] == s[dr] || s[st] == s[dr - 1])
      result += s[st];
    else
      result += s[st + 1];

    st += 2;
    dr -= 2;
  }
  cout << result;
  if(st <= dr)
    cout << s[st];
  reverse(result.begin(), result.end());
  cout << result;
  return 0;
}