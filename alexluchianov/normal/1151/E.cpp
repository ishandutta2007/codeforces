#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[5 + nmax];

int main()
{
  int n;
  cin >> n;
  ll result = 0;
  for(int i = 1;i <= n;i++)
    cin >> v[i];
  for(int i = 1;i <= n;i++)
    result += 1LL * v[i] * (n - v[i] + 1);
  for(int i = 1;i < n;i++)
    result -= 1LL * MIN(v[i], v[i + 1]) * (n - MAX(v[i], v[i + 1]) + 1);
  cout << result;

  return 0;
}