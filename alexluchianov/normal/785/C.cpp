#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
long long c,k;
bool test(long long n){
  return c <= (n - k - 1) * (n - k) / 2 + n ;
}
long long binarysearch(long long from ,long long to){
  if(from < to){
    long long mid = ((from + to)>>1);
    if(test(mid) == 0){
      return binarysearch(mid + 1 ,to);
    } else
      return binarysearch(from , mid);
  } else
    return from;
}
int main()
{
  cin>>c>>k;

  cout<<min(c, binarysearch(k,k + ((sqrt(c))* 2) ));
                      //570441179141911871 511467058318039545
                                       //511467058661475480

  return 0;
}