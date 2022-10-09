#include <iostream>
#include <cmath>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n , q;
  cin >> n >> q;
  for(ll i = 1 ; i <= q ; i++){
    ll x , y;
    cin >> x >> y;
    if((x + y) % 2 == 0){

      ll result = (n / 2 * 2 + n % 2) * ((x - 1) / 2);
      //cout << result << " " ;
      if(x % 2 == 0) {
        result += n / 2 + n % 2;
        result += y / 2;
      } else{
        result += y / 2 + 1;
      }
      cout << result << '\n';
    } else {
      ll result = n * n / 2 + n % 2;

      result += (n / 2 * 2 + n % 2) * ((x - 1) / 2);

      if(x % 2 == 0){
        result += n / 2;
        result += y / 2 + 1;
      } else
        result += y / 2;

      cout << result << '\n';
    }
  }
  return 0;
}