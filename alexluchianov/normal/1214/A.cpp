#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main()
{
  int n, d, e;
  cin >> n >> d >> e;
  int result = 0;
  for(int i = 0; i <= n; i += d)
    result = MAX(result, i + ((n - i) / (e * 5)) * (e * 5));

  cout << n - result;
  return 0;
}