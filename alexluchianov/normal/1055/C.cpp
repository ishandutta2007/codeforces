#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie();

  int la , ra , ta;
  cin >> la >> ra >> ta;
  int lb , rb , tb;
  cin >> lb >> rb >> tb;


  int d = __gcd(ta , tb);

  ra -= la / d * d;
  la -= la / d * d;
  rb -= lb / d * d;
  lb -= lb / d * d;

  cout << MAX(0 , MAX((MIN(ra , rb) - MAX(la , lb) + 1) ,MAX(MIN(ra + d, rb) - MAX(la + d, lb) + 1 , MIN(ra , rb + d) - MAX(la , lb + d) + 1 )));

  return 0;
}