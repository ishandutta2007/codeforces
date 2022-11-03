#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}
//INSERT ABOVE HERE
const int MAX = 1536;
int A[MAX][MAX];
int B[MAX][MAX];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>A[i][j];

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>B[i][j];

  using T = tuple<int, int, int>;
  vector<T> va,vb;
  const int MOD1 = 1e9+7;
  const int MOD2 = 1e9+9;
  const int MOD3 = 998244353;
  const int B1 = 1777771;
  const int B2 = 1777733;
  const int B3 = 1727339;
  for(int i=0;i<n;i++){
    {
      int h1=0,h2=0,h3=0;
      for(int j=0;j<m;j++){
        h1=(h1*B1+A[i][j])%MOD1;
        h2=(h2*B2+A[i][j])%MOD2;
        h3=(h3*B3+A[i][j])%MOD3;
      }
      va.emplace_back(h1,h2,h3);
    }
    {
      int h1=0,h2=0,h3=0;
      for(int j=0;j<m;j++){
        h1=(h1*B1+B[i][j])%MOD1;
        h2=(h2*B2+B[i][j])%MOD2;
        h3=(h3*B3+B[i][j])%MOD3;
      }
      vb.emplace_back(h1,h2,h3);
    }
  }
  sort(va.begin(),va.end());
  sort(vb.begin(),vb.end());
  if(va!=vb) drop(-1);

  // mt19937 mt(1333);


  vector<int> cnt(m,0);
  for(int j=0;j<m;j++)
    for(int i=1;i<n;i++)
      cnt[j]+=B[i-1][j]>B[i][j];

  queue<int> que;
  for(int j=0;j<m;j++)
    if(cnt[j]==0) que.emplace(j);

  vector<int> ans,used(m,0),reset(n,0);
  auto cut=[&](int i){ // cut i, i - 1
    if(reset[i]) return;
    reset[i]=1;
    for(int j=0;j<m;j++){
      if(used[j]) continue;
      if(B[i-1][j]>B[i][j]){
        cnt[j]--;
        if(cnt[j]==0) que.emplace(j);
      }
    }
  };

  for(int t=0;t<m;t++){
    if(que.empty()) drop(-1);

    int j=que.front();que.pop();
    ans.emplace_back(j);
    used[j]=1;

    for(int i=1;i<n;i++)
      if(B[i-1][j]<B[i][j]) cut(i);
  }

  reverse(ans.begin(),ans.end());
  cout<<m<<newl;
  for(int i=0;i<m;i++){
    if(i) cout<<' ';
    cout<<ans[i]+1;
  }
  cout<<newl;
  return 0;
}