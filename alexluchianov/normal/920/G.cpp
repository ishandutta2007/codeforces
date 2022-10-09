#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;

///returns how many numbers are lower than x and are prime with constant p
vector<int> primes;

int lower_than(int x){
  int n = primes.size();
  ll result = 0;
  for(int mask = 0; mask < (1 << n); mask++){
    int val = 1;
    for(int i = 0; i < n; i++)
      if(0 < (mask & (1 << i)))
        val = val * primes[i];

    if(__builtin_popcount(mask) % 2 == 0)
      result += x / val;
    else
      result -= x / val;
  }
  return result;
}

///first number with target number prime with p lower than him
int binarysearch(int from, int to, int target){
  if(from < to){
    int mid = (from + to) / 2;
    if(lower_than(mid) < target)
      return binarysearch(mid + 1, to, target);
    else
      return binarysearch(from, mid, target);
  } else
    return from;
}

void solve(){
  int x, p, k;
  cin >> x >> p >> k;
  primes.clear();
  for(int i = 2;i * i <= p; i++)
    if(p % i == 0) {
      primes.push_back(i);
      while(p % i == 0)
        p /= i;
    }
  if(1 < p)
    primes.push_back(p);
  cout << binarysearch(1, 1000000000, k + lower_than(x)) << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}
/*
1
2 6 1

*/