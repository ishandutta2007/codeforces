#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))


int const nmax = 50;
ll const inf = 10000000000000;

struct Task{
  int a;
  int b;
  bool operator < (Task const &temp) const{
    if(a != temp.a)
      return a > temp.a;
    else
      return b > temp.b;
  }
};
Task v[5 + nmax];

ll c[5 + nmax];
ll sum[5 + nmax];

int st[5 + nmax];

int n;

bool test(ll sol){
  //*
  for(int i = 1 ; i <= n  ;i++){
    c[i] = 1LL * v[i].a * 1000 - sol * v[i].b;
    sum[i] = sum[i - 1] + c[i];
    //cout << c[i] << " " ;
  }
  //cout << '\n';
  //*/

  for(int i = 1 ; i <= n ;i++)
    if(v[i - 1].a == v[i].a)
      st[i] = st[i - 1];
    else
      st[i] = i - 1;
  ll dp[5 + nmax][5 + nmax] = {0};
  for(int i = 0 ; i <= n + 1 ;i++)
    for(int j = 0 ; j <= n + 1 ; j++)
      dp[i][j] = inf;
  dp[0][0] = 0;

  bool ok = 0;
  for(int i = 1 ; i <= n ;i++){
    for(int j = 0 ; j <= n ;j++){
      if(v[i].a == v[i + 1].a){
        break;
      } else{
        for(int p = st[i] ; p <= i ; p++){
          int used = i - p;
          int regain = p - st[i];
          if(0 <= j - regain && j + used - regain <= n)
            dp[i][j] = MIN(dp[i][j] , dp[st[i]][j + used - regain] + sum[p] - sum[st[i]]);
        }
      }
      //cout << i << " " << j << " " << dp[i][j] << '\n';
      if(i == n && dp[i][j] <= 0)
        ok = 1;
    }
  }
  return ok;
}

ll binarysearch(ll from ,ll to){
  if(from < to){
    ll mid = (from + to) / 2;
    if(test(mid) == 1)
      return binarysearch(from , mid);
    else
      return binarysearch(mid + 1 , to);
  } else
    return from;
}

int main()
{
  ///(a[1] + a[2] + .... a[n]) / (b[1] + b[2] + ... b[n]) * 1000 <= SOL
  ///(a[1] + a[2] + .... a[n]) * 1000 <= SOL * (b[1] + b[2] + ... b[n])
  /// (a[1] + a[2] + .... a[n]) * 1000 - SOL * (b[1] + b[2] + ... b[n]) <= 0
  ///a[1] * 1000 - SOL * b[1] + .... a[2] * 1000 - SOL * b[2] <= 0
  cin >> n;
  for(int i = 1 ; i <= n ;i++)
    cin >> v[i].a;
  for(int i = 1 ; i <= n ;i++)
    cin >> v[i].b;
  sort(v + 1, v + n + 1);
  //cout << test(0);

  cout << binarysearch(0 , 100000000000);
  return 0;
}