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
const int N = int(1e5)+10;
int A[N],PS[N];
int n,k;
string s;
bool ok(int len){
  for(int i=1;i+len-1<=n;i++){
    if(PS[i+len-1] - PS[i-1] <= k)
      return true;
  }
  return false;
}
int go(char c){
  SET(A,0);SET(PS,0);
  for(int i=0;i<SZ(s);i++)
    if(s[i]==c)
      A[i+1]=1;
  for(int i=1;i<=n;i++)
    PS[i]=PS[i-1]+A[i];
  int l = 1,h = n,ans = 0;
  while(l<=h){
    int m = (l+h)/2;
    if(ok(m)){ans = m;l = m+1;}
    else h = m-1;
  }
  return ans;
}
int main()
{
  fast_io;
  cin>>n>>k>>s;
  cout<<max(go('a'),go('b'))<<endl;
	return 0;
}