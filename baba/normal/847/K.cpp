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

const int N = 601;
map<string,int> mp;
string A[N],B[N];
int cost[N][N];
int main()
{
  int n,a,b,k,f;
  cin>>n>>a>>b>>k>>f;
  for(int i=1;i<=n;i++){
    cin>>A[i]>>B[i];
    mp[A[i]];mp[B[i]];
  }
  int len = 0;
  for(auto &it : mp)
    it.S  = ++len;
  LL ans = 0;
  for(int i=1;i<=n;i++){
    int add = (A[i] == B[i-1] ? b : a);
    int x = mp[A[i]], y = mp[B[i]];
    if(x > y)swap(x,y);
    cost[x][y] += add;
    ans += add;
  }
  VI v;
  for(int i=1;i<=2 * n;i++)
    for(int j=i+1;j<=2 * n;j++)
      if(cost[i][j]){
        v.PB(cost[i][j]);
      }
  sort(ALL(v));
  reverse(ALL(v));
  int used = 0;
  for(auto x : v)
    if(x > f && used < k){
      ans -= x;
      ans += f;
      used++;
    }
  lldout(ans);



	return 0;
}