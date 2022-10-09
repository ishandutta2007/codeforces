#include <iostream>

using namespace std;

int main()
{
  string s;
  cin >> s;

  int sum = 0;
  int result = 0;

  for(int i = 0 ; i < s.size() ; i++){
    if(s[i] == '(') {
      sum++;
      result++;
    } else if(s[i] == ')'){
      if(0 < sum){
        sum--;
        result++;
      }
    }
  }
  result -= sum;
  cout << result;
  return 0;
}