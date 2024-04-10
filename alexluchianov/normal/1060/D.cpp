#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int const nmax = 100000;

int l[5 + nmax] , r[5 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ;i++)
    cin >> l[i] >> r[i];

  sort(l + 1 , l + n + 1);
  sort(r + 1 , r + n + 1);

  long long result = 0;
  for(int i = 1 ; i <= n ; i++)
    result += max(l[i] , r[i]);
  cout << n + result;

  return 0;
}