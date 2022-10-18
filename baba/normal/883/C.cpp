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


int main()
{
  LL f, T, t;
  cin >> f >> T >> t;
  LL a1,t1,p1;
  cin >> a1 >> t1 >> p1;
  LL a2,t2,p2;
  cin >> a2 >> t2 >> p2;
  auto rajasChutiya = [&](LL files, LL a, LL p, LL ct, LL total){
    //Rajas dekh, ye hai lamda functions. FB intern ke time teri gand
    //maregi. Ye kabhi zindagi me nhi likh payega tu. 1 maheene me
    //nikal denge tujhe. 
    LL x = t > ct ? ceil((files * 1.0 * t - total) / (t - ct)) : 0;
    if(x > files)return LL(1e18);
    if(x < 0)x = 0;
    LL packets = ceil((x * 1.0) / a);
    LL ret = ((max(0ll, files - packets * a)) * t + x * 1.0 * ct  <= total ? packets * p : LL(1e18));
  //  trace(files, a, p, ct, total, x, packets, ret);
    return ret;
  };
  LL mn = 1e18;
  REP(i, 1e7 + 1){
    LL taken = min(f*1LL,a1 * 1ll * i);
    LL remain = max(0ll, f - taken);
    if(T  < taken * 1ll * t1)continue;
    LL v2 = rajasChutiya(remain, a2, p2, t2, T - taken * 1ll * t1);
    v2 += i * 1ll * p1;
    mn = min(mn, v2);
    LL taken2=a1*1LL*i;
    if( taken2> f){
      break;
    }
  }
  swap(a1, a2);
  swap(p1, p2);
  swap(t1, t2);
  REP(i, 1e7 + 1){
    LL taken = min(f*1LL,a1 * 1ll * i);
    LL remain = max(0ll, f - taken);
    if(T  < taken * 1ll * t1)continue;
    LL v2 = rajasChutiya(remain, a2, p2, t2, T - taken * 1ll * t1);
    v2 += i * 1ll * p1;
    mn = min(mn, v2);
    LL taken2=a1*1LL*i;
    if( taken2> f){
      break;
    }
  }
  if(mn >= 1e17)mn = -1;

  lldout(mn);



	return 0;
}