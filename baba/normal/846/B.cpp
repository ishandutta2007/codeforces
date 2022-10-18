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

LL A[50];
int main()
{
  int n,k;
  LL m;
  si(n);si(k);sll(m);
  LL sum = 0;
  for(int i=1;i<=k;i++){
    sll(A[i]);
    sum += A[i];
  }
  sort(A+1,A+1+k);
  LL ans = 0;
  for(int i=0;i<=n;i++){
    LL done = sum * i;
    LL points = (k + 1) * i;
    if(done > m)continue;
    for(int j=1;j<=k;j++){
      for(int num = i+1;num <= n; num++){
        if(done + A[j] <= m){
          done += A[j];
          points++;
          if(j == k)
            points++;
        }
      }
    }
    ans = max(ans,points);
  }
  lldout(ans);
	return 0;
}