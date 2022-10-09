#include <iostream>

using namespace std;
#define ll unsigned long long
#define MIN(a , b) ((a < b) ? a : b)
ll const inf = 2000000000000000000;

ll k , d , t;

ll test(ll val){
  ll repeat = ((k -  1) / d + 1) * d;
  ll sum = val / repeat * (k * 2 + repeat - k);
  val %= repeat;
  sum += MIN(val , k) * 2;
  val -= MIN(val , k);
  sum += val;
  return sum;
}
ll binarysearch(ll from , ll to){
  if(from < to){
    ll mid = (from + to) / 2;
    if(t <= test(mid)){
      return binarysearch(from , mid);
    } else
      return binarysearch(mid + 1 , to);
  } else
    return from;
}
int main()
{
  cin>>k>>d>>t;
  t *= 2;
  ll result = binarysearch(1 ,inf);
  if(test(result) == t){
    cout<<result;
  } else
    cout<<(result - 1)<<".5";
  return 0;
}