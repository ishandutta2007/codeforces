#include <iostream>

using namespace std;
int const nmax = 1000006;
#define MAX(a , b) ((a < b) ? b : a)
int v[5 + nmax];
void gcd(long long  a ,long long  b , long long  &x ,long long  &y){
  if(b == 0){
    x = 1;
    y = 0;
  } else{
    gcd(b , a % b , x , y);
    long long temp = x;
    x = y;
    y = temp - a / b * y;
  }
}
int main()
{
  long long a , b , p , valmax;
  cin>>a>>b>>p>>valmax;
  v[0] = 1;
  for(int i = 1 ; i < p - 1;i++){
    v[i] = (1LL * v[i - 1] * a) % p;
  }
  long long sum = 0;
  if(b == 0){
    cout<<(valmax / p);
    return 0;
  }
  long long smin = -1;
  for(int i = 0 ; i < p - 1;i++){
    long long  x , y;
    gcd(v[i] , p , x , y);
    x %= p;
    if(x < 0){
      x += p;
    }
    long long val = (b * x) % p;
    long long a1 = i;
    long long a2 = val;
    a1 = (a1 - a2) % (p - 1);
    if(a1 < 0)
      a1 += (p - 1);
    long long result = a1 * p + a2;
    result %= (p * (p - 1));
    //cout<<sum<<" "<<result<<" "<<valmax - result<<" "<<(p * (p - 1))<<'\n';
    if(result <= valmax){
      sum += MAX(0 , (valmax - result) / (p * (p - 1))) + 1;
    }
  }
  cout<<sum;
  return 0;
}