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

int vis[30];
char ans[2][30];

int main()
{
  fast_io;
  int n = 27,m = 13;
  string s; cin>>s;
  SET(vis,-1);
  int x,y;
  for(int i=0; i<n; i++)
  {
    if(vis[s[i]-'A']!=-1)
    {
      x = vis[s[i]-'A'];
      y = i;
      break;
    }
    vis[s[i]-'A'] = i;
  }
  if(x==y-1)
  {
    cout<<"Impossible"<<endl;
    return 0;
  }
  int cnt = y-x-1;
  if(cnt&1)
  {
    int idx = m - 1 - cnt/2;
    //trace(x,y,idx,cnt);
    int pos = x+1;
    ans[0][idx] = s[x];
    for(int i=idx; i<m; i++,pos++) ans[1][i] = s[pos];
    for(int i=m-1; pos<y; i--,pos++) ans[0][i] = s[pos];
    pos++;
    for(int i=idx-1; i>=0 && pos<n; i--,pos++) ans[1][i] = s[pos];
    if(pos<n)
      for(int i=0; pos<n; i++,pos++) ans[0][i] = s[pos];
    pos = x-1;
    for(int i=idx-1; i>=0 && pos>=0; i--,pos--) ans[0][i] = s[pos];
    if(pos >= 0)
      for(int i=0; pos>=0; i++,pos--) ans[1][i] = s[pos];
  }
  else
  {
    int idx = m - 1 - cnt/2;
    //trace(x,y,idx,cnt);
    int pos = x+1;
    ans[0][idx] = s[x];
    for(int i=idx+1; i<m; i++,pos++) ans[1][i] = s[pos];
    for(int i=m-1; pos<y; i--,pos++) ans[0][i] = s[pos];
    pos++;
    //trace(pos);
    for(int i=idx; i>=0 && pos<n; i--,pos++) ans[1][i] = s[pos];
    if(pos<n)
      for(int i=0; pos<n; i++,pos++) ans[0][i] = s[pos];
    pos = x-1;
    for(int i=idx-1; i>=0 && pos>=0; i--,pos--) ans[0][i] = s[pos];
    if(pos >= 0)
      for(int i=0; pos>=0; i++,pos--) ans[1][i] = s[pos];
  }
  ans[0][m] = '\0';
  ans[1][m] = '\0';
  cout<<ans[0]<<endl<<ans[1]<<endl;
	return 0;
}