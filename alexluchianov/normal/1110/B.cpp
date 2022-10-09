#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n ,m , k;
  cin >> n >> m >> k;
  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];
  int result = v[n] - v[1] + 1;

  for(int i = 1 ; i < n ; i++)
    v[i] = v[i + 1] - v[i] - 1;
  sort(v + 1 , v + n);
  k--;

  for(int i = n - 1; 1 <= i ;i--){
    if(0 < k){
      k--;
      result -= v[i];
    }
  }
  cout << result;

  return 0;
}