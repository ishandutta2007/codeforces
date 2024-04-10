#include <iostream>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
int n, m, k;

int test(int target){
  ll result = target;
  if(target <= k){
    result += 1LL * target * (target - 1) / 2;
  } else
    result += 1LL * k * (k - 1) / 2 + 1LL * (target - k) * (k - 1);
  int k2 = n - k + 1;

  if(target <= k2){
    result += 1LL * target * (target - 1) / 2;
  } else
    result += 1LL * k2 * (k2 - 1) / 2 + 1LL * (target - k2) * (k2 - 1);

  return result <= m;
}

int binarysearch(int from, int to){
  if(from < to){
    int mid = (from + to + 1) / 2;
    if(test(mid) == 1)
      return binarysearch(mid, to);
    else
      return binarysearch(from, mid - 1);
  } else
    return from;
}
/*
4 6 3
*/
int main()
{
  cin >> n >> m >> k;
  m -= n;
  cout << 1 + binarysearch(0, m);
  return 0;
}