#include <iostream>

using namespace std;

int main()
{
  int a,b,c;
  a = b = c = 0;
  string s;
  cin >> s;
  for(int i = 1;i < s.size();i++){
    if(s[i - 1] > s[i]){
      cout << "NO";
      return 0;
    }
  }
  for(int i = 0; i < s.size(); i++)
    if(s[i] == 'a')
      a++;
    else if(s[i] == 'b')
      b++;
    else if(s[i] == 'c')
      c++;
  if(0 < a && 0 < b && (a == c || b == c))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}