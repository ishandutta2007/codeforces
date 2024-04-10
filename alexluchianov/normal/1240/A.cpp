#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[5 + nmax];

int n;
ll x, a, y, b;

ll tryit(int k){
  ll x1, a1;
  x1 = y;
  a1 = k / b;
  ll x2, a2;
  x2 = x;
  a2 = k / a;
  ll x3, a3;


  x3 = x + y;
  a3 = k / (a * b / __gcd(a, b));
  a1 -= a3;
  a2 -= a3;

  ll result = 0;

  for(int i = 1;i <= k; i++){
    if(0 < a3){
      result += v[i] * x3;
      a3--;
    } else if(0 < a2){
      result += v[i] * x2;
      a2--;
    } else if(0 < a1){
      result += v[i] * x1;
      a1--;
    }
  }
  return result;
}

int binarysearch(int from, int to, ll val){

  if(from < to){
    int mid = (from + to) / 2;
    if(val <= tryit(mid))
      return binarysearch(from, mid, val);
    else
      return binarysearch(mid + 1, to, val);
  } else
    return from;
}

void solve(){
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    v[i] /= 100;
  }

  sort(v + 1, v + n + 1);
  reverse(v + 1, v + n + 1);

  cin >> x >> a;
  cin >> y >> b;

  if(x < y) {
    swap(x, y);
    swap(a, b);
  }

  ll k;
  cin >> k;
  int pos = binarysearch(1, n + 1, k);
  if(pos == n + 1)
    cout << -1 << '\n';
  else
    cout << pos << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}