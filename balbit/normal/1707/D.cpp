#include <bits/stdc++.h>

using namespace std;
#define int ll
#define ll long long
#define y1 zck_is_king
#define pii pair<ll, ll>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define REP(i,n) for (int i = 0; i<n; ++i)
#define RREP(i,n) for (int i = n-1; i>=0; --i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1e9+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll mod = 1e9+7 ;


void GG(){cout<<"0\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 2005+5;

ll dp[maxn][maxn], ps[maxn][maxn];

vector<int> g[maxn];

inline void ADD(ll &a, ll b) {
	a += b; if (a >= mod) a -= mod;
}

void dfs(int v, int p) {
	vector<int> ch;
	for (int u : g[v]) {
		if (u != p) {
			dfs(u,v);
			ch.pb(u);
		}
	}
	int m = SZ(ch);
	vector<vector<int> > L(m+1, vector<int> (maxn));
	vector<vector<int> > R(m+1, vector<int> (maxn));

	fill(ALL(L[0]), 1);
	REP(i,m) {
		REP(j, maxn) {
			L[i+1][j] = L[i][j] * ps[ch[i]][j] % mod;
		}
	}
	fill(ALL(R[m]), 1);
	RREP(i,m) {
		REP(j, maxn) {
			R[i][j] = R[i+1][j] * ps[ch[i]][j] % mod;
		}
	}

	if (p!=-1) REP(i,m) {
		ll YO = 0;
		REP(j,maxn) {
			ADD(dp[v][j], dp[ch[i]][j] * YO % mod);
			ADD(YO, L[i][j] * R[i+1][j] % mod);
		}
	}

	REP(j,maxn) {
		ADD(dp[v][j], L[m][j]);
		ps[v][j] = dp[v][j];
		if (j) ADD(ps[v][j], ps[v][j-1]);
		if (j <= 3) bug(v,j,dp[v][j]);
	}


}

ll C[maxn][maxn];

signed main(){
    IOS();


    int n; cin>>n>>mod;
    REP(i,maxn) REP(j,i+1) {
    	if (i==0||j==0) C[i][j] = 1;
    	else C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
    }
    REP(i,n-1) {
    	int a,b; cin>>a>>b; --a; --b; g[a].pb(b); g[b].pb(a);
    }

    dfs(0, -1);

    for (int i = 0; i<n-1; ++i) {
    	bug(i, dp[0][i]);
    	REP(j,i) {
    		dp[0][i] -= dp[0][j] * C[i+1][j+1] % mod;
    	}
    	dp[0][i] %= mod; if (dp[0][i] < 0) dp[0][i] += mod;
    	bug(dp[0][i]);
    	cout<<dp[0][i]<<' ';
    }
    cout<<endl;
}