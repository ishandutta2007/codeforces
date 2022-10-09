#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))


int main()
{
  int x;
  cin >> x;
  if(x == 1)
    cout << -1;
  else
    cout << x << " " << x;

  return 0;
}