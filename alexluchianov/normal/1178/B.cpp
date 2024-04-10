#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main()
{
  string s;
  cin >> s;
  ll result = 0, ws = 0, wos = 0;
  for(int i = 1; i < s.size(); i++){
    if(s[i - 1] == 'v' && s[i] == 'v') {
      ws++;
      result += wos;
    } else if(s[i] == 'o')
      wos += ws;
  }
  cout << result;
  return 0;
}