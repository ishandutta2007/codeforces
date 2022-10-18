//_/\_MajorKaks_/\_
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
const int N = int(5e4)+10;
int Y[N],A[N],n;
set<int> vis;
bool ok(int val){
  vis.clear();
  for(int i=1;i<=n;i++){
    int x = Y[i];
    while(x > val)x = x / 2;
    while(x && vis.count(x))x = x / 2;
    if(!x)return false;
    vis.insert(x);A[i]=x;
  }
  return true;
}
int main()
{
  si(n);
  for(int i=1;i<=n;i++)
    si(Y[i]);
  int l = 1, h = int(1e9)+10, ans = -1;
  while(l<=h){
    int m = (l+h)/2;
    if(ok(m))ans = m,h = m-1;
    else l = m+1;
  }
  ok(ans);
  for(int i=1;i<=n;i++)
    printf("%d ",A[i]);
  puts("");
	return 0;
}