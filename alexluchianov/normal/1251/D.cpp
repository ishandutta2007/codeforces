#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int const nmax = 200000;
int const inf = 1000000000;

struct Person{
  int x;
  int y;
  bool operator < (Person const &a) const{
    return x < a.x;
  }
};
Person v[1 + nmax];

int test(int val, int n, ll s){
  int scount = 0;
  for(int i = 1;i <= n; i++)
    if(val <= v[i].y && scount <= n / 2) {
      s -= max(v[i].x, val);
      scount++;
    } else{
      s -= v[i].x;
    }
  return 0 <= s && n / 2 < scount;
}

int binarysearch(int from, int to, int n, ll s){
  if(from < to){
    int mid = (from + to + 1) / 2;
    if(test(mid, n, s) == 1)
      return binarysearch(mid, to, n, s);
    else
      return binarysearch(from, mid - 1, n , s);
  } else
    return from;
}

void solve(){
  int n;
  ll s;
  cin >> n >> s;
  for(int i = 1;i <= n; i++)
    cin >> v[i].x >> v[i].y;
  sort(v + 1, v + n + 1);
  reverse(v + 1, v + n + 1);

  cout << binarysearch(1, inf, n, s) << '\n';
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