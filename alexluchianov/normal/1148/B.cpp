#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
ll v[1 + nmax];
ll v2[1 + nmax];

int main()
{
  ll n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  for(int i = 1; i <= n; i++)
    cin >> v[i];
  for(int i = 1; i <= m; i++)
    cin >> v2[i];
  sort(v + 1, v + n + 1);
  sort(v2 + 1, v2 + m + 1);

  if(n <= k || m <= k) {
    cout << -1;
    return 0;
  }

  ll pos = m + 1;
  ll result = -1;
  for(int i = k; 0 <= i; i--){
    while(1 <= pos && ta + v[i + 1] <= v2[pos - 1] )
      pos--;
    if(pos + k - i <= m)
      result = max(result, v2[pos + k - i] + tb);
    else {
      cout << -1;
      return 0;
    }
  }
  cout << result;

  return 0;
}