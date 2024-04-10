#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

bool isgood(int number){
  int frec[10] = {0};
  while(0 < number){
    frec[number % 10]++;
    if(1 < frec[number % 10])
      return 0;
    number /= 10;
  }
  return 1;
}
int main()
{
  int l, r;
  cin >> l >> r;
  for(int i = l; i <= r; i++)
    if(isgood(i) == 1){
      cout << i;
      return 0;
    }
  cout << -1;
  return 0;
}