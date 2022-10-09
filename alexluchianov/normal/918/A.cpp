#include <iostream>

using namespace std;
int const nmax = 1000;
int fib[5 + nmax];
int isfib[5 + nmax];

int main()
{
  int n;
  cin>>n;
  fib[0] = fib[1] = 1;
  isfib[1] = 1;
  for(int i = 2 ; i <= n ;i++){
    fib[i] = fib[i - 1] + fib[i - 2];
    if(fib[i] <= n)
      isfib[fib[i]] = 1;
    else
      break;
  }
  for(int i = 1 ; i <= n ;i++){
    if(isfib[i] == 1){
      cout<<"O";
    } else
      cout<<"o";
  }
  return 0;
}