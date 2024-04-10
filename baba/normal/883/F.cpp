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

//#define TRACE

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
  set<string> S;
  int n;si(n);
  REP(i, n){
    string s; cin >> s;
    while(true){
      string nxt = "";
      bool done = false;
      REP(j, SZ(s)){
        if(!done && j < SZ(s) && s[j] == 'u'){
          nxt += "oo";
          done = true;
        }
        else if(!done  && j < SZ(s) - 1 && s[j] == 'k' && s[j+1] == 'h'){
          nxt += "h";
          j++;
          done = true;
        }
        else nxt.PB(s[j]);
      }
      if(nxt == s)break;
      s = nxt;
    }
    trace(s);
    S.insert(s);
  }
  for(auto it : S)trace(it);
  dout(SZ(S));



	return 0;
}