#include <iostream>

using namespace std;

int const nmax = 1000000;
int const inf = 10000000;
int v[5 + nmax];
int dp[5 + nmax];

int n ,k;

void process(int val, int smin, int &result){
  if(result <= 0)
    return ;

  if(val <= nmax) {
    result -= dp[val];
    return ;
  }

  if(val < smin)
    return ;
  if(val < smin * 2)
    result--;
  else{
    process(val / 2, smin, result);

    if(result <= 0)
      return ;
    process(val / 2 + val % 2, smin, result);
  }
}

bool test(int t){
  for(int i = 0; i <= nmax; i++)
    dp[i] = 0;

  int lim = min(nmax, 2 * t - 1);

  for(int i = t; i <= lim; i++)
    dp[i] = 1;

  for(int i = 2 * t;i <= nmax; i++)
    dp[i] = dp[i / 2] + dp[i / 2 + i % 2];

  int result = k;
  for(int i = 1;i <= n; i++)
    process(v[i], t, result);
  return result <= 0;
}

int binarysearch(int from ,int to){
  if(from < to){
    int mid = (from + to + 1) / 2;
    if(test(mid) == 1){
      return binarysearch(mid ,to);
    } else
      return binarysearch(from , mid - 1);
  } else
    return from;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie();

  cin >> n >> k;
  for(int i = 1 ; i <= n ;i++){
    cin >> v[i];
  }

  //*
  if(test(1) == 0){
    cout<<-1<<'\n';
    return 0;
  }
  //*
  int result = binarysearch(1 , inf);
  cout<<result<<'\n';
  //*/
  return 0;
}