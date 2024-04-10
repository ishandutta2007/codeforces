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

char s[300];
int main()
{
  int n;si(n);
  scanf("%s",s+1);
  bool in = false,w = false;
  int ans=0,ans1=0,c1=0;
  for(int i=1;i<=n;i++)
    s[i] = tolower(s[i]);
  for(int i=1;i<=n;i++){
    if(s[i] == '(')in = true,w = false,c1=0;
    else if(s[i]==')')in = false,w = false,c1=0;
    else if(isalpha(s[i]) && !w){
      w = true;
      if(in)ans++;
    }
    else if(s[i] == '_')w = false,c1=0;
    if(w && !in)c1++;
    ans1=max(ans1,c1);
  }
  printf("%d %d\n",ans1,ans);


	return 0;
}