#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int v[5 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++) {
    cin >> v[i];
  }
  sort(v + 1 , v + n + 1);
  ll result = 0;
  for(int i = 1 ; i <= n / 2 ; i++) {
    result += 1LL * (v[i] + v[n - i + 1]) * (v[i] + v[n - i + 1]);
  }
  cout << result;

  return 0;
}