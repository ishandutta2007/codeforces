#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int const nmax = 100005;
int v[1 + nmax], a[1 + nmax];
long long sol[nmax];

int main()
{
  int n;
  cin>>n;

  for(int i = 1 ; i <= n ;i++){
    cin>>v[i];
    if(1 < i)
      a[i - 1] = fabs(v[i] - v[i-1]);
  }
  long long maxim = -1;
  for(int i = n - 1;0 < i ;i--) { //pai conditii initiale?
    sol[i] = max(1LL * a[i], a[i] - a[i+1] + sol[i+2]);
    if(maxim < sol[i])
      maxim = sol[i];
    //cout<<i<<" "<<sol[i]<<endl;
  }
  cout<<maxim;
  return 0;
}