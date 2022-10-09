#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[1 + nmax], suff[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  ll sum = 0;
  int smax = 0;
  for(int i = 1; i <= m; i++){
    cin >> v[i];
    smax = max(smax, v[i] + i - 1);
    sum += v[i];
  }
  for(int i = m; 1 <= i; i--)
    suff[i] = max(suff[i + 1], v[i] + i - 1);

  if(sum < n || n < smax) {
    cout << -1;
    return 0;
  }
  int boos = 0;


  for(int i = 1; i <= m; i++){
    cout << i + boos << " ";

    while(i < m && suff[i + 1] + boos < n && 1 < v[i]) {
      boos++;
      v[i]--;
    }
  }
  return 0;
}