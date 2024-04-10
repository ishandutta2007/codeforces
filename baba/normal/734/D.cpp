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

const int N = int(5e5)+10;
const int INF = int(2e9)+10;
int X[N],Y[N],T[N];
int getDist(int t,int x1,int y1,int x2,int y2){
  int ans = INF;
  switch(t){
    case 0:{if(x1 == x2 && y2 > y1)ans = y2-y1;}
      break;
    case 1:{if(x1 == x2 && y2 < y1)ans = y1 - y2;}
      break;
    case 2:{if(y1 == y2 && x2 > x1)ans = x2-x1;}
      break;
    case 3:{if(y1 == y2 && x2 < x1)ans = x1 - x2;}
      break;
    case 4:{if(x1 + y1 == x2 + y2 && x2 > x1)ans = x2-x1;}
      break;
    case 5:{if(x1 + y1 == x2 + y2 && x2 < x1)ans = x1-x2;}
      break;
    case 6:{if(x1 - y1 == x2 - y2 && x2 < x1)ans = x1-x2;}
      break;
    case 7:{if(x1 - y1 == x2 - y2 && x2 > x1)ans = x2-x1;}
      break;
    default: assert(false);
  }
  return ans;
}
int main()
{
  int n;si(n);
  int x,y;si(x);si(y);
  for(int i=1;i<=n;i++){
    char t[2];scanf("%s",t);
    if(t[0]=='R')T[i]=0;
    else if(t[0]=='B')T[i]=1;
    else T[i]=2;
    scanf("%d %d",X+i,Y+i);
  }
  bool ok = false;
  for(int i=0;i<8;i++){
    int p = 1;
    for(int j=1;j<=n;j++)
      if(getDist(i,x,y,X[j],Y[j]) < getDist(i,x,y,X[p],Y[p]))
        p = j;
    if(getDist(i,x,y,X[p],Y[p]) == INF)continue;
    ok |= (T[p] == 2 || (i < 4 ? (T[p] == 0) : T[p] == 1));
  }
  puts(ok?"YES":"NO");
	return 0;
}