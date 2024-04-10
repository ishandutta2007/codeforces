#include <iostream>
#include <cmath>

using namespace std;

#define ll long long
int const nmax = 1000;
int a[1 + nmax];
int b[1 + nmax];
int v[1 + nmax];

int main()
{
  int n, k1, k2;
  cin >> n >> k1 >> k2;
  for(int i = 1;i <= n; i++)
    cin >> a[i];
  for(int i = 1;i <= n; i++)
    cin >> b[i];
  for(int i = 1;i <= n; i++)
    v[i] = fabs(a[i] - b[i]);

  ll result = 0;

  for(int i = 1;i <= k1 + k2; i++) {
    int pos = 1;
    for(int j = 1;j <= n; j++) {
      if(v[pos] < v[j])
        pos = j;
    }
    if(0 < v[pos])
      v[pos]--;
    else
      v[pos]++;
  }

  for(int i = 1;i <= n; i++)
    result += 1LL * v[i] * v[i];

  cout << result;
}