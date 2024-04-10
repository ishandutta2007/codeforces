#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int P=1e9+7;
void Add(int&x,int y){if((x+=y)>=P)x-=P;}
int n,m,dp[255][1<<15][2][2];char A[255][255],ctt[255][255];

int main(){
  cin>>n>>m;
  memset(A,'x',sizeof A);
  rep(i,1,n)scanf("%s",A[i]+1);
  if(n<m){
    rep(i,1,m)rep(j,1,n)ctt[i][j]=A[j][i];
    memcpy(A,ctt,sizeof A),swap(n,m);
  }
  dp[0][0][0][0]=1;
  rep(i,1,n){
    rep(j,1,m){
      auto lst=dp[(i-1)*m+j-1],cur=dp[(i-1)*m+j];int x;
      rep(S,0,(1<<m)-1){
        if(A[i][j]=='x'){
          int p=S&~(1<<(j-1));
          rep(t,0,1)rep(o,0,1)Add(cur[p][o][0],lst[S][o][t]);
          continue;
        }
        if(j==1)rep(t,0,1)Add(lst[S][t][0],lst[S][t][1]),lst[S][t][1]=0;
        x=lst[S][0][0];
        if(x)Add(cur[S|1<<(j-1)][0][1],x),Add(cur[S][~S>>(j-1)&1][0],x);
        x=lst[S][0][1];
        if(x)Add(cur[S|1<<(j-1)][0][1],x),Add(cur[S][0][1],x);
        x=lst[S][1][0];
        if(x)Add(cur[S|1<<(j-1)][1][1],x);
        if(S>>(j-1)&1)Add(cur[S][1][0],x);
        x=lst[S][1][1];
        if(x)Add(cur[S|1<<(j-1)][1][1],x),Add(cur[S][1][1],x);
      }
    }
  }
  int res=0;
  rep(S,0,(1<<m)-1)rep(p,0,1)rep(q,0,1)Add(res,dp[n*m][S][p][q]);
  cout<<res<<endl;
  return 0;
}