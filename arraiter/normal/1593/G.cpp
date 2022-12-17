#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=1e6+10;
int n,q,su[maxn];char S[maxn];

int main(){
  int T;cin>>T;while(T--){
    scanf("%s%d",S+1,&q),n=strlen(S+1);
    rep(i,1,n){
      su[i]=(i>1?su[i-2]:0)+(S[i]=='('||S[i]==')');
    }
    while(q--){
      int l,r;scanf("%d%d",&l,&r);
//      int sz=r-l+1;
      int ct0=su[r]-su[l-1];
      int ct1=su[r-1]-(l>1?su[l-2]:0);
      int ans=abs(ct0-ct1);
      printf("%d\n",ans);
    }
  }
  return 0;
}