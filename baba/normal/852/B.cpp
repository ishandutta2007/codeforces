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
const int N = int(1e6)+10;
const int M = 101;
const int MOD = int(1e9)+7;
int C[3][N],cnt[3][M],ans[M];
int A[N];
void mul(int a[M][M], int b[M][M], int m){
  int ret[M][M];SET(ret,0);
  REP(i,m)REP(j,m)REP(k,m){
    ret[i][j] = (ret[i][j] + (a[i][k] * 1ll * b[k][j])) % MOD;
  }
  REP(i,m)REP(j,m)a[i][j] = ret[i][j];
}
void power(int a[M][M], int m, int p){
  int ret[M][M];SET(ret,0);
  REP(i,m)ret[i][i] = 1;
  while(p){
    if(p & 1)mul(ret,a,m);
    mul(a,a,m);
    p >>= 1;
  }
  REP(i,m)REP(j,m)a[i][j] = ret[i][j];
}
int main()
{
  int n,l,m;
  si(n);si(l);si(m);
  REP(i,3)
    REP(j,n){
      si(C[i][j]);
      cnt[i][C[i][j]%m]++;
    }

  REP(i,n)A[i] = C[1][i] + C[2][i];
  SET(cnt[2],0);
  REP(i,n)cnt[2][A[i]%m]++;

  int mat[M][M], c1mat[M][M], c3mat[M][M];
  REP(i,m)REP(j,m){
    mat[i][j] = cnt[1][(i - j + m) % m];
  }
  REP(i,m)REP(j,m){
    c1mat[i][j] = cnt[0][(i - j + m) % m];
  }
  REP(i,m)REP(j,m){
    c3mat[i][j] = cnt[2][(i - j + m) % m];
  }
  power(mat, m,  l - 2);
  mul(c3mat, mat, m);
  mul(c3mat, c1mat, m);
  dout(c3mat[0][0]);
  /*LL v = 0;

  REP(i,m)REP(j,m){
    ans[i] = (ans[i] + mat[i][j] * cnt[0][j]) % MOD;
  }
  REP(i, m){
    v = (v + ans[i] * 1ll * cnt[2][(m - i)%m]) % MOD;
  }
  lldout(v);*/
	return 0;
}