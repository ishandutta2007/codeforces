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

typedef pair<double,double> point;
const double EPS = 1e-9;
const double PI = acos(-1);
bool eq(double a,double b){
  return fabs(a - b) < EPS;
}
point sub(point a, point b){
  return {a.F - b.F, a.S - b.S};
}
point add(point a, point b){
  return {a.F + b.F, a.S + b.S};
}
const int N = int(1e5)+10;
point A[3][N];
int B[N], F[N], arr[N], ans[N];
double val[N];
double dist(point x, point y){
  return hypot({x.F-y.F},{x.S-y.S});
}
double cross(point a, point b){
  return fabs(a.F * b.S - a.S * b.F);
}
double perp(point a, point b, point x){
  point ab = sub(b, a);
  point ax = sub(x, a);
  return cross(ab, ax);
}
int main()
{
  int n;si(n);
  REP(i, n)si(B[i]);
  REP(i, n)A[1][i] = {i, 0};
  double theta = PI / n;
  point v1 = {cos(theta), sin(theta)};
  A[2][0] = {n, 0};
  FOR(i,1, n){
    A[2][i] = add(A[2][i-1], v1);
  }
  v1 = {cos(PI - theta), sin(PI - theta)};
  A[0][n-1] = add(A[1][0],v1);
  
  for(int i=n-2;i>=0;i--)
    A[0][i] = add(A[0][i+1], v1);
  REP(i, n - 1){
    if(n - B[i] > B[i+1]){
      F[i] = -1;
    }
    else if(n - B[i] < B[i+1]){
      F[i] = +1;
    }
    else {
      F[i] = 0;
    }
  }
  REP(i, n){
    int x = B[i], y = B[(i+1)%n];
    val[i] =  perp(A[0][x], A[2][y], A[1][0]) - perp(A[0][x], A[2][y], A[1][1]);
  }
  REP(i, n){
    arr[i] = i;
  }
  sort(arr, arr + n, [](int a, int b){return val[a] > val[b];});
  REP(i, n){
    ans[arr[i]] = i;
  }
  REP(i, n)printf("%d ", ans[i]);
  puts("");

	return 0;
}