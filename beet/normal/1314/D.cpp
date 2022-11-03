#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


template<typename F>
struct FixPoint : F{
  FixPoint(F&& f):F(forward<F>(f)){}
  template<typename... Args>
  decltype(auto) operator()(Args&&... args) const{
    return F::operator()(*this,forward<Args>(args)...);
  }
};
template<typename F>
inline decltype(auto) MFP(F&& f){
  return FixPoint<F>{forward<F>(f)};
}

//INSERT ABOVE HERE
const int MAX = 100;
int as[MAX][MAX]={};

int dp[MAX][MAX][10]={};
int id[MAX][MAX][10]={};

int vs[10]={};
int cnt[MAX]={};

signed main(){
  int n,k;
  cin>>n>>k;

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>as[i][j];

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      using P = pair<int, int>;
      vector<P> vp;
      for(int k=0;k<n;k++)
        if(i!=k&&j!=k)
          vp.emplace_back(as[i][k]+as[k][j],k);
      sort(vp.begin(),vp.end());

      if(vp.size()>10) vp.resize(10);
      for(int k=0;k<(int)vp.size();k++)
        tie(dp[i][j][k],id[i][j][k])=vp[k];
    }
  }

  int ans=2e9;
  int m=k/2;

  for(int v=1;v<n;v++)
    chmin(ans,(as[0][v]+as[v][0])*m);

  vs[0]=vs[m]=0;
  memset(cnt,0,sizeof(cnt));
  MFP([&](auto dfs,int x,int p,int res)->void{
        if(res>=ans) return;
        if(x==m){
          if(n<=20){
            int flg=0;
            for(int i=0;i<n;i++)
              flg|=!cnt[i];
            if(!flg) return;
          }
          int sum=0;
          for(int t=0;t<m;t++){
            int i=vs[t+0],j=vs[t+1],k=0;
            while(cnt[id[i][j][k]]) k++;
            sum+=dp[i][j][k];
            if(sum>=ans) break;
          }
          chmin(ans,sum);
          return;
        }
        for(int v=0;v<n;v++){
          vs[x]=v;
          cnt[v]++;
          dfs(x+1,v,res+dp[p][v][0]);
          cnt[v]--;
        }
      })(1,0,0);

  cout<<ans<<endl;
  return 0;
}