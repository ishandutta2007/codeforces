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

const int N = int(5e3)+10;
bool isPal[N][N];
char s[N];
int val[N][N];
int ans[N];
int main()
{
  scanf("%s",s+1);
  int n = strlen(s+1);
  for(int i=1;i<=n;i++){
    isPal[i][i] = true;
    val[i][i] = 1;
    ans[val[i][i]]++;
  }
  for(int len=2;len<=n;len++)
    for(int i=1;i<=n;i++){
      int j = i + len - 1;
      isPal[i][j] = (s[i] == s[j] && ((i+1 <= j - 1) ? isPal[i+1][j-1] : true));
      if(isPal[i][j]){
        val[i][j] = 1 + val[i][i + len / 2 - 1];
        ans[val[i][j]]++;
      }
      else {
        val[i][j] = 0;
      }
    }
  for(int i=n;i>=1;i--)
    ans[i] += ans[i+1];
  for(int i=1;i<=n;i++)
    printf("%d ",ans[i]);
  puts("");
	return 0;
}