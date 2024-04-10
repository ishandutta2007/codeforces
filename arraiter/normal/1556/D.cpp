#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=1e4+10;
int n,k,A[maxn];

int main(){
  cin>>n>>k;
  int Oab,Aab,Oac,Aac,Obc,Abc;
  puts("or 1 2");
  fflush(stdout);
  cin>>Oab;
  puts("or 1 3");
  fflush(stdout);
  cin>>Oac;
  puts("or 2 3");
  fflush(stdout);
  cin>>Obc;
  puts("and 1 2");
  fflush(stdout);
  cin>>Aab;
  puts("and 1 3");
  fflush(stdout);
  cin>>Aac;
  puts("and 2 3");
  fflush(stdout);
  cin>>Abc;
  rep(bit,0,29){
    rep(x,0,1)rep(y,0,1)rep(z,0,1){
      if((x|y)==(Oab>>bit&1)&&(x|z)==(Oac>>bit&1)&&(y|z)==(Obc>>bit&1)&&(x&y)==(Aab>>bit&1)&&(x&z)==(Aac>>bit&1)&&(y&z)==(Abc>>bit&1)){
        if(x)A[1]|=1<<bit;
        if(y)A[2]|=1<<bit;
        if(z)A[3]|=1<<bit;
      }
    }
  }
  rep(i,4,n){
    int Or,And;
    printf("or 1 %d\n",i);
    fflush(stdout);
    scanf("%d",&Or);
    printf("and 1 %d\n",i);
    fflush(stdout);
    scanf("%d",&And);
    A[i]=A[1]^(Or^And);
  }
//  rep(i,1,n)printf("%d%c",A[i],"\n "[i<n]);
  nth_element(A+1,A+k,A+n+1);
  printf("finish %d\n",A[k]);
  fflush(stdout);
  return 0;
}