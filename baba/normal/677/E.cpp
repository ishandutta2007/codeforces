//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
const int N = 2001;
const int MOD = int(1e9)+7;
const int LR = 0,TD = 1, BR = 2, BL = 3;
int PS[4][N][4][N],n,len[4][N],A[4][N][N];
string s[N];
void process(int A[],int n,int PS[4][N]){
  for(int i=1;i<=n;i++)
    PS[A[i]][i]=1;
  for(int j=0;j<4;j++)
    for(int i=1;i<=n;i++)
      PS[j][i]+=PS[j][i-1];
}
bool ok(II x){
  return x.F >=1 && x.F<=n && x.S >=1 && x.S <=n;
}
LL power(LL a,int p){
  if(!a)return 0;
  LL ret = 1;
  while(p){
    if(p&1)ret=ret*a%MOD;
    a=a*a%MOD;
    p/=2;
  }
  return ret;
}
int get(int ans[]){
  LL ret = 1;
  for(int i=1;i<4;i++)
    ret = ret * power(i,ans[i]) % MOD;
  for(int i=1;i<4;i++)
    if(ans[i]!=0)
      return ret;
  return 0;
}
void cmp(int ans[],int curr[]){
  double v1 = ans[2]*log(2)+ans[3]*log(3);
  double v2 = curr[2]*log(2) + curr[3]*log(3);
  if(v1 < v2-1e-8){
    for(int i=0;i<4;i++)
      ans[i]=curr[i];
  }
  else if(fabs(v1-v2)<1e-8 && ans[1] < curr[1]){
    for(int i=0;i<4;i++)
      ans[i]=curr[i];
  }
}
int main()
{
  fast_io;cin>>n;
  for(int i=0;i<n;i++)cin>>s[i];
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      A[TD][j][i] = A[LR][i][j] = s[i-1][j-1]-'0';
      A[BR][i-j+n][++len[BR][i-j+n]] = s[i-1][j-1]-'0';
      A[BL][i+j-1][++len[BL][i+j-1]] = s[i-1][j-1]-'0';
    }
    len[TD][i]=len[LR][i]=n;
  }
  for(int i=0;i<4;i++)
    for(int k=1;k<=2*n;k++)
      process(A[i][k],len[i][k],PS[i][k]);
  int Ans[4];SET(Ans,0);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
      if(s[i-1][j-1]=='0')continue;
      int ll = 1, hh = 2*n,ans = 1;
      while(ll<=hh){
        int m = (ll+hh)/2;
        bool v = true;
        II u = {i-m+1,j};
        II d = {i+m-1,j};
        II l = {i,j-m+1};
        II r = {i,j+m-1};
        v = ok(u) & ok(d) & ok(l) & ok(r);
        if(v){
         v &= (PS[TD][j][0][d.F] - PS[TD][j][0][u.F-1] == 0);
         v &= (PS[LR][i][0][r.S] - PS[LR][i][0][l.S-1] == 0);
        }
        if(v){ans = m;ll = m+1;}
        else hh = m-1;
      }
      int curr[4];SET(curr,0);
      for(int k = 0;k <4; k++){
        curr[k] += PS[TD][j][k][i+ans-1] - PS[TD][j][k][i-ans+1-1];
        curr[k] += PS[LR][i][k][j+ans-1] - PS[LR][i][k][j-ans+1-1];
        curr[k] -= PS[TD][j][k][i] - PS[TD][j][k][i-1];
      }
      cmp(Ans,curr);
    }
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
      if(s[i-1][j-1]=='0')continue;
      int l = 1, h = 2*n,ans = 1;
      while(l<=h){
        int m = (l+h)/2;
        bool v = true;
        II ul = {i-m+1,j-m+1};
        II ur = {i-m+1,j+m-1};
        II dl = {i+m-1,j-m+1};
        II dr = {i+m-1,j+m-1};
        v = ok(ul) & ok(ur) & ok(dl) & ok(dr);
        if(v){
          v &= (PS[BR][i-j+n][0][min(dr.F,dr.S)] - PS[BR][i-j+n][0][min(ul.F,ul.S)-1] == 0);
          v &= (PS[BL][i+j-1][0][min(dl.F,n-dl.S+1)] - PS[BL][i+j-1][0][min(ur.F,n-ur.S+1)-1] == 0);
        }
        if(v){ans = m;l = m+1;}
        else h = m-1;
      }
      int curr[4];SET(curr,0);
      for(int k = 0;k <4; k++){
        II ul = {i-ans+1,j-ans+1};
        II ur = {i-ans+1,j+ans-1};
        II dl = {i+ans-1,j-ans+1};
        II dr = {i+ans-1,j+ans-1};
        curr[k] += PS[BR][i-j+n][k][min(dr.F,dr.S)] - PS[BR][i-j+n][k][min(ul.F,ul.S)-1];
        curr[k] += PS[BL][i+j-1][k][min(dl.F,n-dl.S+1)] - PS[BL][i+j-1][k][min(ur.F,n-ur.S+1)-1];
        curr[k] -= PS[TD][j][k][i] - PS[TD][j][k][i-1];
      }
      cmp(Ans,curr);
    }
  cout<<get(Ans)<<endl;
  return 0;
}