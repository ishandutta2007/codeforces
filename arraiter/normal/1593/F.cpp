#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int n,A,B,F[50][50][50][101],G[50][50][50][101];char str[50];
void chkmin(int&x,int y){
  if(x>y)x=y;
}
void chkmax(int&x,int y){
  if(x<y)x=y;
}

int main(){
  int T;cin>>T;while(T--){
    cin>>n>>A>>B>>str;
    memset(F,0,sizeof F);
    memset(G,0,sizeof G);
    F[0][0][0][50]=1;
    rep(i,0,n-1){
      int v=str[i]-'0';
      rep(r_a,0,A-1)rep(r_b,0,B-1)rep(dt,0,100)if(F[i][r_a][r_b][dt]){
        F[i+1][(r_a*10+v)%A][r_b][dt+1]=1;
        G[i+1][(r_a*10+v)%A][r_b][dt+1]=r_a*100+r_b+1;
        F[i+1][r_a][(r_b*10+v)%B][dt-1]=1;
        G[i+1][r_a][(r_b*10+v)%B][dt-1]=-(r_a*100+r_b+1);
      }
    }
    int ans=-1,chk=-1;
    rep(i,0,100)if(F[n][0][0][i]){
      if(ans==-1||ans>abs(i-50))ans=abs(i-50),chk=i;
    }
    if(ans==-1||ans==n){
      cout<<-1<<endl;
    }else{
      string str;
      int r_a=0,r_b=0,pos=chk;
      per(i,n,1){
        int x=G[i][r_a][r_b][pos];
        if(x>0){
          str='R'+str;
          x--;
          r_a=x/100;
          r_b=x%100;
          pos--;
        }else{
          x=-x;
          x--;
          r_a=x/100;
          r_b=x%100;
          pos++;
          str='B'+str;
        }
      }
      cout<<str<<endl;
    }
  }
  return 0;
}