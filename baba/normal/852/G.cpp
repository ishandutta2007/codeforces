//TooMuchMath
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

const int N = int(1e5)+10;
unordered_map<string,int> mp,done;
string ss;
inline int go(string s, int pos){
  if(pos == SZ(ss)){
    if(done.count(s))return 0;
    done[s] = 1;
    if(mp.count(s))return mp[s];
    else return 0;
  }
  int ret = 0;
  if(ss[pos] != '?'){
    s.PB(ss[pos]);
    ret += go(s ,pos+1);
  }
  else {
    ret += go(s, pos + 1);
    s.PB(' ');
    REP(i,5){
     s[SZ(s) - 1] = 'a' + i;
     ret += go(s, pos+1);
    }
  }
  return ret;
}
int main()
{
  fast_io;
  int n,m;
  cin>>n>>m;
  REP(i,n){
    string s;
    cin>>s;
    mp[s]++;
  }
  REP(i,m){
    cin>>ss;done.clear();
    string  s= "";
    cout << go(s,0) << "\n";
  }
	return 0;
}