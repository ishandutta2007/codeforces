#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int l = sqrt(n);
  int lim = n + 1;
  int last = lim - l;
  while(1 < lim){
    cout << last << " ";
    last++;
    if(last == lim){
      lim -= l;
      last = lim - l;
    }
    if(last < 1)
      last = 1 ;
  }

  return 0;
}