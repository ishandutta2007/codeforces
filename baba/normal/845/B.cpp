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

int main()
{
  string s;cin>>s;
  int ans = 100;
  for(int i=0;i<int(1e7);++i){
    string ss = to_string(i);
    reverse(ALL(ss));
    while(SZ(ss) < 6)ss.PB('0');
    reverse(ALL(ss));
    int s1 = 0, s2 = 0;
    for(int i=0;i<3;i++)
      s1 += (ss[i] - '0'), s2 += (ss[5-i]-'0');
    if(s1 != s2) continue;
    int diff = 0;
    for(int i=0;i<6;i++)
      if(s[i] != ss[i])
        diff++;
    ans = min(ans,diff);
  }
  dout(ans);
	return 0;
}