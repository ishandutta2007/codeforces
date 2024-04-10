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
  int n ;
  cin >> n;
  ll sumx = 0 , sumy = 0;
  for(int i = 1 ; i <= n ; i++){
    int a , b;
    cin >> a >> b;
    sumx += a;
    sumy += b;
  }
  for(int i = 1 ; i <= n ; i++){
    int a , b;
    cin >> a >> b;
    sumx += a;
    sumy += b;
  }
  cout << sumx / n << " " << sumy /n;

  return 0;
}