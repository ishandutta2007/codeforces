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
map<LL,LL> sz;
LL f(LL x){
  if(x <= 1)return sz[x] = 1;
  return sz[x] = 2*f(x/2) + 1;
}
int get(LL n,LL cnt){
  if(sz[n] == 1){
    return n % 2;
  }
  if(sz[n/2] >= cnt)return get(n/2,cnt);
  else if(sz[n/2] == cnt-1)return n % 2;
  else return get(n/2,cnt - sz[n/2] - 1);
}
int main()
{
  LL n,l,r;
  cin>>n>>l>>r;
  f(n);
  int ans = 0;
  for(LL x = l; x <= r; x++)
    if(get(n,x) == 1){
      ans++;
    }
  dout(ans);
	return 0;
}