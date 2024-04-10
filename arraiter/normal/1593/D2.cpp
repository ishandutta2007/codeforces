#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int n,A[50];

int main(){
  int T;cin>>T;while(T--){
    cin>>n;
    rep(i,1,n)cin>>A[i];
    sort(A+1,A+n+1);
    per(i,n,1)A[i]-=A[1];
//    putchar('#');rep(i,1,n)printf("%d%c",A[i],"\n "[i<n]);
    bool flg=0;
    rep(i,1,n){
      int ct=0;
      rep(j,1,n)ct+=A[i]==A[j];
      if(ct>=n/2){
        flg=1;break;
      }
    }
    if(flg){
      puts("-1");
      continue;
    }
    set<int>S;
    int ans=0;
    rep(st,1,n/2+1){
      int tp=n/2;
      rep(i,1,n)tp-=A[i]==A[st];
//      if(tp==1){
//        if(A[n]!=A[st])ans=max(ans,A[n]-A[st]);
//        continue;
//      }
      rep(i,st+1,n)if(A[i]>A[st]){
        int x=A[i]-A[st];
        vector<int>fac;
        rep(i,1,sqrt(x))if(x%i==0){
          fac.push_back(i);
          fac.push_back(x/i);
        }
        sort(fac.begin(),fac.end(),greater<int>());
//        for(int d:fac)printf("%d ",d);
//        puts("");
        for(int d:fac){
          if(d<=ans)break;
          if(!S.insert(d).second)continue;
          rep(p,1,n){
            int ano=0;
            rep(j,1,n)if(A[j]>=A[p]&&(A[j]-A[p])%d==0)ano++;
            if(ano>=n/2){
              ans=d;break;
            }
          }
        }
      }
    }
    cout<<(ans?ans:-1)<<endl;
  }
  return 0;
}