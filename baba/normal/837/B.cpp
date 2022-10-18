//Mobius_Treap
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
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

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

const int N=105;
string flag[N];

int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++)
    cin>>flag[i];
  int ans=1;
  if(n%3==0){
    for(int k=0;k<3;k++){
      char col=flag[(k*n)/3][0];
      for(int i=(k*n)/3;i<((k+1)*n)/3;i++)
        for(int j=0;j<m;j++)
          if(flag[i][j]!=col){
            ans=0;break;
          }
    }
    if(flag[0][0]==flag[n/3][0]||flag[0][0]==flag[2*n/3][0]||flag[n/3][0]==flag[2*n/3][0])
      ans=0;
  }
  if(ans==1&&n%3==0){
    cout<<"YES\n";
    return 0;
  }
  if(m%3==0){
    if(n%3==0)ans=1;
    for(int k=0;k<3;k++){
      char col=flag[0][(k*m)/3];
      for(int i=0;i<n;i++)
        for(int j=(k*m)/3;j<((k+1)*m)/3;j++)
          if(flag[i][j]!=col){
            ans=0;break;
          }
    }
    if(flag[0][0]==flag[0][m/3]||flag[0][0]==flag[0][2*m/3]||flag[0][m/3]==flag[0][2*m/3])
      ans=0;
  }
  if(n%3!=0&&m%3!=0)
    ans=0;
  if(ans==1){
    cout<<"YES\n";
  }
  else
    cout<<"NO\n";
	return 0;
}