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

bool good[26];
const int N = int(1e5)+10;
char s[N],p[N];
int main()
{
  scanf("%s",s);
  int n = strlen(s);
  REP(i,n)good[s[i]-'a'] = true;
  scanf("%s",s+1);
  n = strlen(s+1);
  int q;si(q);
  while(q--){
    scanf("%s",p+1);
    int len = strlen(p+1);
    if(len < n - 1){
      puts("NO");
      continue;
    }
    int pos = -1;
    bool ok = true;
    for(int i=1;i<=len;i++){
      if(i > n){
        ok = false;
        break;
      }
      if(s[i] == p[i])continue;
      if(s[i] == '?' && good[p[i]-'a'])continue;
      if(s[i] == '*'){
        pos = i;
        break;
      }
      ok = false;
      break;
    }
    if(!ok){puts("NO");continue;}
    if(pos == -1){
      puts((len == n || (len == n - 1 && s[n] == '*')) ? "YES" : "NO");
      continue;
    }
    int endpos = -1;
    for(int i = 0; i <= len - pos; i++){
      if(s[n - i] == p[len - i])continue;
      if(s[n - i] == '?' && good[p[len-i]-'a'])continue;
      if(s[n - i] == '*'){
        endpos = len - i;
        break;
      }
      ok = false;
      break;
    }
    if(!ok){puts("NO");continue;}
    for(int i = pos; i <= endpos; ++i){
      ok &= !good[p[i]-'a'];
    }
    puts(ok?"YES":"NO");
  }
	return 0;
}