#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main()
{
  int n, gcd = 0, smax = 0;
  cin >> n;
  for(int i = 1;i <= n; i++){
    int a;
    cin >> a;
    gcd = __gcd(gcd, a);
    smax = MAX(smax, a);
  }

  if(((smax / gcd) - n) % 2 == 1)
    cout << "Alice";
  else
    cout << "Bob";
  return 0;
}