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

int query(int x,int y){
  printf("? %d %d\n",x,y);
  fflush(stdout);
  char s[2];
  scanf("%s",s);
  if(s[0] == '=')return 0;
  else if(s[0] == '<')return 1;
  else if(s[0] == '>')return -1;
  else assert(false);
}
int main()
{
  int t;si(t);
  while(t--){
    int n;si(n);
    int mn = 1, mx = 1;
    if(n & 1){
      mn = 1, mx = 1;
    }
    else {
      int x = query(1,2);
      if(x == 1)mn = 1, mx = 2;
      else mx = 1,mn = 2;
    }
    for(int i=(n & 1 ? 1 : 2);i < n; i += 2){
      int x = i+1, y = i + 2;
      if(query(x,y) == -1)swap(x,y);
      if(query(mn,x) == -1)mn = x;
      if(query(mx,y) == +1)mx = y;
    }
    printf("! %d %d\n",mn,mx);
    fflush(stdout);
  }
	return 0;
}