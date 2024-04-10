#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n , k;
  cin >> n >> k;
  ll result = 0;
  for(int i = 1 ; i < k ; i++) {
    int a;
    cin >> a;
    result += a * n;
  }
  int a;
  cin >> a;
  result += a;
  if(result % 2 == 0)
    cout << "even";
  else
    cout << "odd";

  return 0;
}