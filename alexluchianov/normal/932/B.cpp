#include <iostream>

using namespace std;
int const nmax = 1000000;
int sol[5 + nmax];
int sum[5 + nmax][10];
int prod(int n){
  int r = 1;
  while(0 < n){
    if(n % 10 != 0)
      r *= n % 10;
    n /= 10;
  }
  return r;
}
int main()
{
  for(int i = 1 ; i <= nmax ;i++){
    for(int j = 1 ; j <= 9 ;j++){
      sum[i][j] = sum[i - 1][j];
    }
    if(i < 10)
      sol[i] = i;
    else
      sol[i] = sol[prod(i)];
    sum[i][sol[i]]++;
  }
  int q;
  cin>>q;
  for(int i = 1; i <= q ;i++){
    int x , y , k;
    cin>>x>>y>>k;
    cout<<sum[y][k] - sum[x - 1][k]<<'\n';
  }
  return 0;
}