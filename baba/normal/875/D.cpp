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
const int N = int(2e5)+10;
const int LOGN = 20;
int A[N], DP[LOGN][N], msb[N], OR[LOGN][N];
LL sub = 0;
int MAX(int l, int r){
  assert(r >= l);
  int idx = msb[r-l+1], sub = 1 << idx;
  return A[DP[idx][l]] > A[DP[idx][r-sub+1]] ? DP[idx][l] : DP[idx][r-sub+1];
}
int brute(int l, int r){
  int v = 0;
  FOR(i, l, r + 1)v |= A[i];
  return v;
}
int f(int l, int r){
  assert(r >= l);
  int idx = msb[r-l+1], sub = 1 << idx;
  int ret =  OR[idx][l] | OR[idx][r-sub+1];
  //assert(ret == brute(l, r));
  return ret;
}
void solve(int l, int r){
  if(l > r)return;
  int mx = MAX(l, r);
  //trace(l, r, mx, A[mx]);
  int L = -1 , R = -1;
  int low, high;
  // search for L
  low = l, high = mx;
  while(low <= high){
    int mid = (low + high) >> 1;
    if(f(mid, mx) > A[mx])
      low = mid + 1;
    else {
      L = mid;
      high = mid - 1;
    }
  }
  //search for R
  low = mx, high = r;
  while(low <= high){
    int mid = (low + high) >> 1;
    if(f(mx, mid) > A[mx]){
      high = mid - 1;
    }
    else {
      R = mid;
      low = mid + 1;
    }
  }
  //done :)
  assert(L != -1 && R != -1);
  //trace(L, R, mx);
  //trace(f(L, mx));
  //trace(f(mx, R));
  sub += (mx - L + 1) * 1ll * (R - mx + 1);
  //trace(sub);
  solve(l, mx - 1);
  solve(mx + 1, r);
}
int main()
{
  int mx = -1;
  REP(i, N){
    if(i >= (1 << (mx + 1)))mx++;
    msb[i] = mx;
  }
  int n;si(n);
  REP(i, n){
    si(A[i]);
    DP[0][i] = i;
    OR[0][i] = A[i];
  }
  FOR(i, 1, LOGN){
    int add = (1 << (i - 1));
    if(add >= n)break;
    REP(j, n){
      if(j + add < n){
        DP[i][j] = A[DP[i-1][j]] < A[DP[i-1][j+add]] ? DP[i-1][j + add] : DP[i-1][j];
        OR[i][j] = OR[i-1][j] | OR[i-1][j+add];
      }
      else {
        DP[i][j] = DP[i-1][j];
        OR[i][j] = OR[i-1][j];
      }
    }
  }
  solve(0, n - 1);
  LL ans = (n * 1ll * (n + 1)) / 2 - sub;
  lldout(ans);

	return 0;
}