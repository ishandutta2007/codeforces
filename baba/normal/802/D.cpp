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

const int N = int(2e3)+10;
long double cnt[N],curr[N],fact[N];
int A[N],len;
long double solve(long double P){
  long double ret = 0;
  REP(i,len){
    int k = A[i];
    long double prob = (pow(P,k) * exp(-P)) / fact[k];
    long double val = 250.0 * prob;
    ret += fabs(val - cnt[k]);
  }
  return ret;
}
long double solve2(long double P){
  long double ret = 0;
  REP(i,len){
    int k = A[i];
    long double prob = 1 / ( 2 * P + 1);
    long double val = 250.0 * prob;
    ret += fabs(val - cnt[k]);
  }
  return ret;
}

int main()
{
  int t;si(t);
  fact[0] = 1;
  REP(i,N)fact[i] = fact[i-1] * i;
  while(t--){
    REP(i,N)cnt[i] = 0;
    len = 0;
		int est_max = 0;
    REP(i,250){
      int x;si(x);
      if(x >= N)continue;
      cnt[x]++;A[len++] = x;
			est_max = max(est_max, x);
    }
		double b1 = 0;
		double b2 = 0.2*est_max;
		int inside = 0;
		REP(i,250) {
			if(A[i]>b1 && A[i]<b2)
				++inside;
		}
		/*
    sort(A,A+len);
    len = unique(A,A+len) - A;
    long double mn1 = 1e18,best1 = -1;
    FOR(P,10,1001){
      long double err = solve(P);
      if(err < mn1){
        mn1 = err,best1 = P;
      }
    }
    long double mn2 = 1e18,best2 = -1;
    FOR(P,10,1001){
      long double err = solve2(P);
      if(err < mn2){
        mn2 = err,best2 = P;
      }
    }
		*/
    puts(inside < 12 ? "poisson" : "uniform");
  }
	return 0;
}