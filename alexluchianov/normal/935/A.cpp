#include <iostream>

using namespace std;

int nrdiv(int n){
  int result = 1;
  int h = 2;
  while(h * h <= n){
    int l = 1;
    while(n % h == 0){
      l++;
      n /= h;
    }
    result *= l;
    h++;
  }
  if(1 < n)
    result *= 2;
  return result;
}
int main()
{
  int n;
  cin>>n;
  cout<<nrdiv(n) - 1;
  return 0;
}