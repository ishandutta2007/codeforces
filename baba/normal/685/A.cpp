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

int get(int x){
  int ret = 1;
  while(x>=7){
    ret++;
    x = x / 7;
  }
  return ret;
}
int cnt[7],total;
void go(int x){
  int c = 0;
  while(x>=7){
    cnt[x%7]++;c++;
    x = x/7;
  }
  cnt[x%7]++;c++;
  assert(c<=total);
  cnt[0]+=total-c;
}
void solve(int n,int m){
  int d1 = get(n-1);
  int d2 = get(m-1);
  //trace(d1,d2);
  if(d1 + d2 > 7){
    puts("0");
    return;
  }
  int ans = 0;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
      total=d1;go(i);
      total=d2;go(j);
      bool ok = true;
      for(int k=0;k<7;k++)
        if(cnt[k]>1)
          ok=false;
      if(ok)ans++;
      SET(cnt,0);
    }
  dout(ans);	
}
int main()
{
  int n,m;
  si(n);si(m);
  solve(n,m);
  return 0;
}