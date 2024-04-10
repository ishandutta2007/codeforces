#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
ofstream out ("text.out");

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[5 + nmax];

int sol[30] = {1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int main()
{
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  int q;
  cin >> q;
  for(int i = 1 ; i <= q ; i++){
    int a;
    cin >> a;
    int p = 0;
    while((1 << p) <= a)
      p++;
    if((1 << p) - 1 != a)
      cout << (1 << p) - 1 << '\n';
    else {
      cout << sol[p - 2] << '\n';
    }
  }
  return 0;
}