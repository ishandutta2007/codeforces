#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#include <bits/stdc++.h>
using namespace std;
//#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
#define int long long 
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 200005;

#define li inline
#define re register
#define ll __int128
#define abs(a) ((a)>0?(a):-(a))
namespace Miller_Rabin
{
	const int Pcnt=12;
	const ll p[Pcnt]={2,3,5,7,11,13,17,19,61,2333,4567,24251};
	li ll pow(re ll a,re ll b,re ll p)
	{
		re ll ans=1;
		for(;b;a=a*a%p,b>>=1)if(b&1)ans=ans*a%p;
		return ans;
	}
	li bool check(re ll x,re ll p)
	{
		if(x%p==0||pow(p%x,x-1,x)^1)return true;
		re ll t,k=x-1;
		while((k^1)&1)
		{
			t=pow(p%x,k>>=1,x);
			if(t^1&&t^x-1)return true;
			if(!(t^x-1))return false;
		}return false;
	}
	inline bool MR(re ll x)
	{
		if(x<2)return false;
		for(re int i=0;i^Pcnt;++i)
		{
			if(!(x^p[i]))return true;
			if(check(x,p[i]))return false;
		}return true;
	}
}
namespace Pollard_Rho
{
	#define Rand(x) (1ll*rand()*rand()%(x)+1)
	li ll gcd(const ll a,const ll b){return b?gcd(b,a%b):a;}
	li ll mul(const re ll x,const re ll y,const re ll X)
	{
		ll k=(1.0L*x*y)/(1.0L*X)-1,t=x*y-k*X;
		while(t<0)t+=X;return t;
	}
	li ll PR(const re ll x,const re ll y)
	{
		re int t=0,k=1;re ll v0=Rand(x-1),v=v0,d,s=1;
		while(true)
		{
			v=(mul(v,v,x)+y)%x,s=mul(s,abs(v-v0),x);
			if(!(v^v0)||!s)return x;
			if(++t==k){if((d=gcd(s,x))^1)return d;v0=v,k<<=1;}
		}
	}
	li void Resolve(re ll x,re ll&ans)
	{
		if(!(x^1)||x<=ans)return;
		if(Miller_Rabin::MR(x)){if(ans<x)ans=x;return;}
		re ll y=x;while((y=PR(x,Rand(x)))==x);while(!(x%y))x/=y;
		Resolve(x,ans);Resolve(y,ans);
	}
	li long long check(ll x)
	{
		re ll ans=0;Resolve(x,ans);
		return ans;
	}
}

int pr[N], cnt;
void xxs(int n) {
  static bool vis[200005];
  mset(vis, 0);
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) pr[++cnt] = i;
    for (int j = 1; j <= cnt && pr[j] * i <= n; j++) {
      vis[pr[j] * i] = 1;
      if (i % pr[j] == 0) break;
    }
  }
}


int a[N];
int n;

//#define zz

int b[N];

int query(int x, int y) {
  #ifdef zz
  ll g = __gcd(b[x], b[y]);
  return b[x] / g * b[y];
  #else
  printf("? %lld %lld\n", x, y), fflush(stdout);
  ll z; scanf("%lld", &z); return z;
  #endif
}

int f[105][105], vis[105], val[200005];
bool ban[105];
void small() {
  memset(vis, 0, sizeof(vis));
  memset(ban, 0, sizeof(ban));
  memset(val, 0, sizeof(val));
  rep(i, 1, n) rep(j, i + 1, n) f[i][j] = f[j][i] = query(i, j);
  int qwq = 0, A, B; rep(i, 1, n) rep(j, i + 1, n) if (f[i][j] > qwq) qwq = f[i][j], A = i, B = j;
  int r = 1; while (r * (r - 1) != qwq) ++r;
  int l = r - n + 1;
  int C = 1; while (C == A || C == B) ++C;
  if (f[C][A] % r == 0) a[A] = r, a[B] = r - 1, val[r] = A, val[r - 1] = B;
  else a[B] = r, a[A] = r - 1, val[r] = B, val[r - 1] = A;
  ban[A] = ban[B] = 1;
  int i;
  for (i = r - 2; i - 1 >= l; i -= 2) {
    qwq = 0; rep(ii, 1, n) rep(jj, 1, n) if (!ban[ii] && !ban[jj] && f[ii][jj] > qwq) qwq = f[ii][jj], A = ii, B = jj;
    if (f[A][val[i + 1]] == i * (i + 1)) a[A] = i, a[B] = i - 1, val[i] = A, val[i - 1] = B;
    else assert(f[B][val[i +1]] == i * (i + 1)), a[B] = i, a[A] = i - 1, val[i] = B, val[i - 1] = A;
    ban[A] = ban[B] = 1;
  }
  if (i == l) {
    for (int ii = 1; ii <= n; ii++) if (!ban[ii]) a[ii] = l;
  }
}
void big() {
  mt19937 rng(time(0));
  int A = 0, B = 0, C = 0, D = 0;
  rep(times, 1, 4900) {
    int x = rng() % n + 1, y = rng() % n + 1;
    while (x == y) x = rng() % n + 1, y = rng() % n + 1;
    int g = query(x, y);
    int q = Pollard_Rho::check(g);
    if (q > D) D = q, C = g, A = x, B = y;
  }
  int tem = rng() % n + 1;
  while (tem == A || tem == B) tem = rng() % n + 1;
  int tmp = query(tem, A), va, vb, go;
  if (tmp % D == 0) {
    va = D, vb = C / D, go = A;
  } else {
    va = C / D, vb = D, go = B;
  }
  rep(i, 1, n) {
    if (A == i) a[i] = va;
    else if (B == i) a[i] = vb;
    else {
      if (go == A) a[i] = query(i, A) / D;
      else a[i] = query(i, B) / D;
    }
  }
}

void solve() {
  n = read();
  #ifdef zz
  rep(i, 1, n) scanf("%lld", &b[i]);
  #endif
  if (n <= 90) small();
  else big();
  printf("! ");
  for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
  puts("");
  fflush(stdout);
}

signed main() {
  xxs(2e5);
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}