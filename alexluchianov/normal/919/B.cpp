#include <iostream>

using namespace std;
int digitsum(int n){
  int p = 0;
  while(0 < n && p <= 10){
    p += n % 10;
    n /= 10;
  }
  return p;
}
int main()
{
  int k;
  cin>>k;
  int number = 1 ,p = 0;
  while(true){
    if(digitsum(number) == 10)
      p++;
    if(p == k){
      cout<<number;
      return 0;
    }
    number++;
  }
  return 0;
}