#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
int const nmax = 5000;
char s[5 + nmax];

int main()
{
  cin>>s;
  int n = strlen(s);
  long long result = 0;
  for(int i = 0 ; i < n ;i++){
    int sum = 0;
    int p = 0;
    for(int j = i ; j < n ;j++){
      if(s[j] == '('){
        sum++;
      } else if(s[j] == ')'){
        if(0 < sum){
          sum--;
        } else{
          if(0 < p){
            p--;
            sum++;
          } else{
            break;
          }
        }
      } else if(s[j] == '?'){
        if(0 < sum){
          p++;
          sum--;
        } else{
          sum++;
        }
      }
      if(sum == 0)
        result++;
    }
  }
  cout<<result;
  return 0;
}