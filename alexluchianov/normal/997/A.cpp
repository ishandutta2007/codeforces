#include <iostream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))

int main()
{
  ll n , x , y;
  cin >> n >> x >> y;
  ll sum = 0;
  ll last = 1;
  for(int i = 1 ; i <= n ; i++){
    char a;
    cin >> a;
    a -= '0';
    if(last == 1 && a == 0)
      sum++;
    last = a;
  }
  if(sum == 0){
    cout << 0;
    return 0;
  }
  ll smin = n * y;
  for(int i = 0 ; i < sum ;i++){
    smin = MIN(smin , i * x + (sum - i) * y);
  }
  cout << smin;

  return 0;
}