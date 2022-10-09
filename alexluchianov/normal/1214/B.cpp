#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main()
{
  int g, b, n;
  cin >> g >> b >> n;
  int result = 0;
  for(int i = 0; i <= n; i++)
    if(i <= g && n - i <= b)
      result++;
  cout << result;

  return 0;
}