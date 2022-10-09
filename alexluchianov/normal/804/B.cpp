#include <iostream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const modulo = 1000000007;

string s;

int main()
{
  cin >> s;
  ll result = 0;
  ll sum = 0;
  for(int i = s.size() - 1 ; 0 <= i ; i--){
    if(s[i] == 'a') {
      result += sum;
      if(modulo <= result)
        result -= modulo;

      sum = sum * 2;
      if(modulo <= sum)
        sum -= modulo;
    } else {
      sum++;
      if(modulo <= sum)
        sum -= modulo;
    }
  }
  cout << result;
  return 0;
}