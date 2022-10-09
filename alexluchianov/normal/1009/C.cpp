#include <iostream>
#include <iomanip>

using namespace std;

#define ll long long

///-1 -1 -1
///-1 2 5
///-2 1 4
///-6 1 0

int main()
{
  ll n , m;
  cin >> n >> m;
  ll sum = 0;

  for(int i = 1 ;i <= m ;i++){
    ll x , d;
    cin >> x >> d;
    sum += x * n;
    if(0 <= d){
      sum += (n - 1) * n / 2 * d;
    } else {
      if(n % 2 == 1)
        sum += (n / 2) * (n / 2 + 1) * d;
      else
        sum += (n / 2 - 1) * (n / 2) * d + n / 2 * d;
    }
  }
  cout << setprecision(10) << fixed << double(sum) / n;
  return 0;
}