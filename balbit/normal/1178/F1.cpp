#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int maxn = 505;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 998244353 ;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n){ // a^n % mod
	ll re=1;
	while (n>0){
		if (n&1) re = re*a %mod;
		a = a*a %mod;
		n>>=1;
	}
	return re;
}

ll inv (ll b){
	if (b==1) return b;
	return (mod-mod/b) * inv(mod%b) % mod;
}

ll dp[maxn][maxn];
int a[maxn];

ll f(int l, int r){
	if (l==r) return 1;
	if (l>r) return 1;
	if (dp[l][r]) return dp[l][r];
	int mn = iinf, j = -1;
	FOR(i,l,r+1){
		if (a[i]<mn){
			mn = a[i], j = i;
		}
	}
	ll lf = 0, rf = 0;
	for (int i = j; i>=l; i--){
		lf+= f(i,j-1)*f(l,i-1);
		lf%=mod;
	}
	for (int i = j; i<=r; i++){
		rf+= f(j+1,i)*f(i+1,r);
		rf%=mod;
	}
	// cout<<l<<' '<<r<<" : "<<lf<<' '<<rf<<endl;
	dp[l][r]=lf*rf%mod;
	return dp[l][r];
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    REP(i,n){
    	cin>>a[i];
    }
    cout<<f(0,n-1)<<'\n';
    
}