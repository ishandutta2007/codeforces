#include <iostream>

using namespace std;

#define ll long long
int const nmax = 1000000;

int v[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, k, k2;
  cin >> n >> k;
  k2 = k;
  if(k < n * (n + 1) / 2){
    cout << -1;
    return 0;
  }
  for(int i = 1;i <= n; i++)
    v[i] = i;
  k -= n * (n + 1) / 2;
  int from = 1;
  int to = n;

  while(0 < k && from < to){
    if(to - from <= k){
      swap(v[from], v[to]);
      k -= to - from;
      from++;
      to--;
    } else {
      swap(v[to], v[to - k]);
      k = 0;
    }
  }

  cout << k2 - k << '\n';
  for(int i = 1;i <= n; i++)
    cout << i << " ";
  cout << '\n';
  for(int i = 1;i <= n; i++)
    cout << v[i] << " ";
  cout << '\n';

  return 0;
}