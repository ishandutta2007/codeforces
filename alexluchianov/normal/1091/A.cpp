//#pragma GCC optimize("O3")

#include <iostream>

using namespace std;

#define ll long long
#define ld long double
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;

int main()
{
  //*
  ios::sync_with_stdio(0);
  cin.tie(0);
  //*/

  int a , b , c;
  cin >> a >> b >> c;

  cout << MIN(c - 2 , MIN(b - 1 , a)) * 3 + 3;

  return 0;
}