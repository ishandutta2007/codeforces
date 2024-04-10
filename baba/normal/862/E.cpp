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

//#define TRACE

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

const int N = int(1e5)+10;
LL B[N],v[N];
LL get(LL alpha, int len){
  int idx = lower_bound(v,v+len,alpha) - v;
  trace(alpha,idx,v[idx], v[idx-1]);
  LL ret = abs(alpha - v[idx]);
  if(idx)
    ret = min(ret, abs(alpha - v[idx-1]));
  if(idx < len)
    ret = min(ret, abs(alpha - v[idx+1]));
  return ret;
}
int main()
{
  int n,m,q;
  si(n);si(m);si(q);
  LL alpha = 0;
  for(int i=0;i<n;i++){
    int x;si(x);
    alpha += (i & 1 ? -1 : 1) * x;
  }
  for(int i=0;i<m;i++){
    sll(B[i]);
  }
  for(int i=0;i<n;i++)
    v[0] += (i & 1 ? -1 : 1) * B[i];
  for(int i=1;i<=m-n;i++){
    v[i] = -(v[i-1] - B[i-1]) + ((n - 1) & 1 ? -1 : 1) * B[i + n - 1];
    trace(i,v[i]);
  }
  v[m-n+1] = LL(1e18);
  sort(v, v + m - n + 1);
  lldout(get(alpha, m - n + 1));
  while(q--){
    int l,r,x;
    si(l);si(r);si(x);
    l--;r--;
    if((r - l + 1) & 1){
      if(l & 1)alpha -= x;
      else alpha += x;
    }
    lldout(get(alpha,m-n+1));
  }
	return 0;
}