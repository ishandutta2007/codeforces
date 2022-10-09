#include <iostream>
#include <fstream>

using namespace std;
int const nmax = 50;
int const kmax = 1000;
int const modulo = 1000000007;
int m , n;
char v[5 + nmax][5 + kmax];
int x[5 + kmax];
int mult[5 + kmax];
int jump(int a){
  if(x[a] == a){
    return a;
  } else{
    x[a] = jump(x[a]);
    return x[a];
  }
}
void reunite(int a ,int b){
  if(jump(a) != jump(b)){
    if(mult[jump(a)] < mult[jump(b)]){
      mult[jump(b)] += mult[jump(a)];
      mult[jump(a)] = 0;
      x[jump(a)] = x[jump(b)];
    } else{
      mult[jump(a)] += mult[jump(b)];
      mult[jump(b)] = 0;
      x[jump(b)] = x[jump(a)];
    }
  }
}
int dp[5 + kmax][5 + kmax];
int sum[5 + kmax][5 + kmax];
void precompute(int n){
  dp[0][0] = 1;
  sum[0][0] = 1;
  for(int i = 1 ; i <= n ;i++){
    for(int j = 1 ; j <= i ;j++){
      dp[i][j] = (dp[i - 1][j - 1] + 1LL * dp[i - 1][j] * j) % modulo;
      sum[i][j] = sum[i][j - 1] + dp[i][j];
      if(modulo <= sum[i][j]){
        sum[i][j] -= modulo;
      }
    }
  }
}
int main()
{
  cin>>m>>n;
  for(int i = 1 ; i <= n ;i++){
    cin>>(v[i]);
  }
  for(int i = 0 ; i < m ;i++){
    x[i] = i;
    mult[i] = 1;
  }
  for(int i = 0 ; i < m ;i++){
    for(int i2 = 0 ; i2 < m ;i2++){

      bool ok = 1;
      for(int j = 1 ;j <= n ;j++){
        if(v[j][i] != v[j][i2]){
          ok = 0;
        }
      }
      if(ok == 1)
        reunite(i , i2);
    }
  }
  precompute(m);
  int result = 1;
  for(int i = 0 ; i < m ;i++){
    result = (1LL * result * sum[mult[i]][mult[i]]) % modulo;
  }
  cout<<result;
  return 0;
}