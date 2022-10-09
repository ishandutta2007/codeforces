#include <iostream>

using namespace std;
string a;
string b;

int main()
{
  cin >> a >> b;
  int fours = 0 , sevens = 0;
  for(int i = 0 ; i < a.size() ;i++){
    if(a[i] == '4' && b[i] == '7')
      fours++;
    else if(a[i] == '7' && b[i] == '4')
      sevens++;
  }
  cout << max(fours , sevens);
  return 0;
}