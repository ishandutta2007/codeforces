//TooWeakTooSlow
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

int f(int x1, int y1, int x2, int y2){
  return abs(x1 - x2) + abs(y1 - y2);
}
int main()
{
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int ans = f(x1, y1, x2 - 1 , y2 - 1); 
  ans = max(ans, f(x1, y1, x2 - 1 , y2 + 1)); 
  ans = max(ans, f(x1, y1, x2 + 1 , y2 + 1)); 
  ans = max(ans, f(x1, y1, x2 + 1 , y2 - 1)); 
  if(x1 == x2 || y1 == y2)ans++;
  dout(2 * ans);



	return 0;
}