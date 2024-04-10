#include <iostream>
#include <cmath>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 500000;
int const inf = 1000000000;

int v[5 + nmax];

int main()
{
  int n;
  cin >> n;
  if(n == 1){
    int a;
    cin >> a;
    cout << a;
    return 0;
  }
  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];
  bool okplus = 0;
  bool okminus = 0;
  for(int i = 1 ;i <= n ; i++){
    if(v[i] <= 0)
      okminus = 1;
    if(0 <= v[i])
      okplus = 1;
  }
  if(okplus == 1 && okminus == 1){
    ll sum = 0;
    for(int i = 1 ; i <= n ; i++)
      sum += fabs(v[i]);
    cout << sum;
  } else{
    int smin = inf + 1;
    for(int i = 1 ; i <= n ; i++)
      smin = MIN(smin , fabs(v[i]));
    ll sum = 0;
    for(int i = 1 ; i <= n ; i++)
      sum += fabs(v[i]);
    cout << sum - smin * 2 ;
  }
  return 0;
}