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

double dist(double x1, double y1, double x2 = 0, double y2 = 0){
  return hypot(x1 - x2, y1 - y2);
}
int main()
{
  double R, x1, y1, x2, y2;
  cin >> R >> x1 >> y1 >> x2 >> y2;
  x2 -= x1; y2 -= y1;
  auto printAns = [&](double x, double y, double R){
    x += x1; y += y1;
    printf("%.15lf %.15lf %.15lf\n", x, y, R);
  };
  double d = dist(x2, y2);
  if(d >= R){
    printAns(0, 0, R);
    return 0;
  }
  if(fabs(d) <= 1e-9){
    printAns(0, R / 2, R / 2);
    return 0;
  }
  double rad = (d + R) / 2;
  double vx = x2 / d, vy = y2 / d;
  double x = x2 - vx * rad, y = y2 - vy * rad;
  printAns(x, y, rad);
	return 0;
}