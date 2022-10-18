//mobius_treap_v0
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

const int N=320;
int dp[2][8][N][N];
int vis[N][N],T[32];
//directions are N E S W NE SE SW NW
int newdir[8][2]={{7,4},{4,5},{5,6},{6,7},{0,1},{1,2},{2,3},{3,0}};
int dx[8]={0,+1,0,-1,+1,+1,-1,-1};
int dy[8]={+1,0,-1,0,+1,-1,-1,+1};
int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>T[i];
  int pre=0,nxt=1;
  dp[pre][0][160][160+T[1]]=1;
  for(int i=1;i<=T[1];i++)
    vis[160][160+i]=1;
  for(int i=2;i<=n;i++){
    for(int dir=0;dir<8;dir++){
      for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
          if(dp[pre][dir][x][y]==1){
            for(int nd=0;nd<2;nd++){
              for(int z=1;z<=T[i];z++){
                int fdir= newdir[dir][nd];
                int nx=x+z*dx[fdir],ny=y+z*dy[fdir];
                vis[nx][ny]=1;
                if(z==T[i])
                  dp[nxt][fdir][nx][ny]=1;
              }
            }
          }
        }
      }
    }
    swap(nxt,pre);
    SET(dp[nxt],0);
  }
  int ans=0;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      ans+=vis[i][j];
  cout<<ans<<"\n";
  return 0;
}