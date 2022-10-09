#include <iostream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const inf = 1000000000;

int v[5 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n;i++)
    cin >> v[i];
  ll result = 0, val = inf + 1;
  for(int i = n; 1 <= i; i--){
    val = MIN(val - 1, v[i]);
    if(0 < val)
      result += val;
  }
  cout << result;
  return 0;
}