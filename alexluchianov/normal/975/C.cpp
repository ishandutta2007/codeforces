#include <iostream>

using namespace std;

int const nmax = 200000;

#define ll long long
ll sum[5 + nmax];
ll const inf = 1000000000000000000;

int binarysearch(int from , int to , ll a){
  if(from < to){
    int mid = (from + to) / 2;
    if(sum[mid] <= a)
      return binarysearch(mid + 1 , to , a);
    else
      return binarysearch(from , mid , a);
  } else
    return from;
}

int main()
{
  int n , q;
  cin >> n >> q;
  for(int i = 1 ; i <= n ;i++){
    cin >> sum[i];
    sum[i] += sum[i - 1];
  }
  sum[n + 1] = inf;
  ll used = 0;
  for(int i = 1 ; i <= q ;i++){
    ll a;
    cin >> a;
    int pos = binarysearch(0 , n + 1 , a + used);
    if(pos == n + 1){
      pos = 1;
      used = 0;
    }else
      used += a;
    cout << n - pos + 1 << '\n';
  }
  return 0;
}