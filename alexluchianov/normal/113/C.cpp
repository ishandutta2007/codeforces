#include <iostream>
#include <bitset>

using namespace std;
int const nmax = 300000000;

bitset<1 + nmax> prime;

void computeciur(){

  for(int i = 3;i * i <= nmax; i += 2)
    if(prime[i] == 0)
      for(int j = i * i; j <= nmax; j += (i<<1))
        prime[j] = 1;
}

bitset<1 + nmax> counted, allzero;

int lowerthan(int n){
  int result = 0;
  counted = allzero;

   if(2 <= n)
    result++;

  for(int i = 2;i * i <= n; i++)
    for(int j = 1; j < i; j++){
      int val = i * i + j * j;
      if(val <= n) {
        if((val & 1) == 0)
          continue;
        if(prime[val] == 0 && counted[val] == 0) {
          result++;
          counted[val] = 1;
        }
      } else
        break;
    }
  return result;
}

int main()
{
  int a, b;
  cin >> a >> b;
  computeciur();
  cout << lowerthan(b) - lowerthan(a - 1);
  return 0;
}
/*
1 300000000
*/