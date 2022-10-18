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

int cnt[256];
bool ok[256];
int add[256];
int main()
{
  int n;si(n);
  string s;cin>>s;
  REP(i, 256)ok[i] = true;
  for(auto c : s)
    if(c != '*')
      ok[c] = false;
  int m;si(m);
  int good = 0;
  REP(i, m){
    string t; cin >> t;
    if(SZ(t) != SZ(s))continue;
    bool fucked = false;
    REP(i, SZ(s))fucked |= (s[i] == '*' && !ok[t[i]]) || (s[i] != '*' && s[i] != t[i]);
    if(fucked)continue;
    good++;
    SET(add, 0);
    REP(i, SZ(t))if(s[i] == '*')add[t[i]] = 1;
    REP(i, 256)cnt[i] += add[i];
  }
  int ans = 0;
  REP(i, 256)if(cnt[i] == good)ans++;
  dout(ans);



	return 0;
}