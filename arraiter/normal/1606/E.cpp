#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int P=998244353;
int n,k,dp[505][505],C[505][505],pw[505][505];

int main(){
  cin>>n>>k;
  rep(i,0,500){
    C[i][0]=1;
    rep(j,1,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
    pw[i][0]=1;
    rep(j,1,500)pw[i][j]=1ll*pw[i][j-1]*i%P;
  }
  rep(i,0,k)dp[0][i]=1;
  rep(i,0,k)dp[1][i]=0;
  rep(i,2,n){
    rep(j,1,k){
      rep(p,0,i)if(p!=i-1){
        dp[i][j]=(dp[i][j]+1ll*C[i][p]*pw[min(i-1,j)][p]%P*(dp[i-p][max(j-i+1,0)]))%P;
      }
//      printf("(%d %d) : %d\n",i,j,dp[i][j]);
    }
  }
  cout<<dp[n][k]<<endl;
  return 0;
}