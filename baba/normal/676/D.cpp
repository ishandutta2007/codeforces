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
const int N = int(4e6)+10;
const int M = int(1e3)+10;
VI g[N];
int B[N],d[N],vis[N];
string s[M];
map<char,int> mp;
int A[12][4],R[12],rev[4];
//0 - L , 1 - R, 2 - U, 3 - D
int main()
{
  mp['+']=0;mp['-']=1;mp['|']=2;mp['^']=3;
  mp['>']=4;mp['<']=5;mp['v']=6;mp['L']=7;
  mp['R']=8;mp['U']=9;mp['D']=10;mp['*']=11;
  R[0]=0;R[1]=2;R[2]=1;R[3]=4;R[4]=6;R[5]=3;
  R[6]=5;R[7]=9;R[8]=10;R[9]=8;R[10]=7;R[11]=11;
  A[0][0]=1;A[0][1]=1;A[0][2]=1;A[0][3]=1;
  A[1][0]=1;A[1][1]=1;A[1][2]=0;A[1][3]=0;
  A[2][0]=0;A[2][1]=0;A[2][2]=1;A[2][3]=1;
  A[3][0]=0;A[3][1]=0;A[3][2]=1;A[3][3]=0;
  A[4][0]=0;A[4][1]=1;A[4][2]=0;A[4][3]=0;
  A[5][0]=1;A[5][1]=0;A[5][2]=0;A[5][3]=0;
  A[6][0]=0;A[6][1]=0;A[6][2]=0;A[6][3]=1;
  A[7][0]=0;A[7][1]=1;A[7][2]=1;A[7][3]=1;
  A[8][0]=1;A[8][1]=0;A[8][2]=1;A[8][3]=1;
  A[9][0]=1;A[9][1]=1;A[9][2]=0;A[9][3]=1;
  A[10][0]=1;A[10][1]=1;A[10][2]=1;A[10][3]=0;
  A[11][0]=0;A[11][1]=0;A[11][2]=0;A[11][3]=0;
  fast_io;rev[0]=1;rev[1]=0;rev[2]=3;rev[3]=2;
  int n,m;cin>>n>>m;
  for(int i=0;i<n;i++)
    cin>>s[i];
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      B[i*m+j] = mp[s[i][j]];
  int nn = n*m;
  for(int i=nn;i<4*nn;i++)
    B[i] = R[B[i-nn]];
  int x1,y1;
  cin>>x1>>y1;
  x1--;y1--;
  int s = x1*m + y1;
  cin>>x1>>y1;
  x1--;y1--;
  int e = x1*m + y1;
  queue<int> Q;Q.push(s);vis[s]=1;
  SET(d,-1);d[s]=0;
  while(!Q.empty()){
    int u = Q.front();Q.pop();
    int x = u;
    while(x >= nn)x-=nn;
    int i = x / m; int j = x % m;
    for(int k=0;k<4;k++){
        if(j==0 && k==0)continue;
        if(j==m-1 && k==1)continue;
        if(i==0 && k==2)continue;
        if(i==n-1 && k==3)continue;
        int y = u;
        if(k == 0)y--;
        else if(k==1)y++;
        else if(k==2)y-=m;
        else if(k==3)y+=m;
        if(A[B[u]][k] && A[B[y]][rev[k]]){
          if(vis[y])continue;
          Q.push(y);vis[y]=1;d[y]=d[u] + 1;
        }
    }
    int w = (u + nn)%(4*nn);
    if(!vis[w]){
      d[w]=d[u]+1;
      vis[w]=1;
      Q.push(w);
    }
  }
  int ans = int(1e9);
  for(int i=e;i<4*nn;i+=nn)
    if(d[i]!=-1)
      ans = min(ans,d[i]);
  if(ans == int(1e9))ans = -1;
  cout<<ans<<endl;
	return 0;
}