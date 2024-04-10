#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[1 + nmax];
int v2[1 + nmax];
int frec[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= n; i++)
    cin >> v2[i];
  for(int i = 1;i <= n; i++)
    frec[v2[i]] = i;

  int result = 0, smax = 0;
  for(int i = 1;i <= n; i++){
    smax = MAX(smax, frec[v[i]]);
    if(frec[v[i]] < smax)
      result++;
  }
  cout << result;
  return 0;
}