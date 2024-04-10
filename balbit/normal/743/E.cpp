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
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


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

const int maxn = 1003;

int dp[maxn][256];
int close[maxn][maxn];
// int prv[maxn];
int n; 
int a[maxn];
map<int, bool> seen;

int nap = 0;

int mv(int dst){
    if (dst<0){
        return -100;
    }
    if (dst==0){
        return nap;
    }
    REP(i,n+1) REP(j,256) dp[i][j] = -10000;
    dp[0][0]=0;
    FOR(i,1,n+1){
        REP(j, 256){
            dp[i][j] = dp[i-1][j];
            if (j & (1<<a[i-1]) ){
                if (close[i-1][dst-1] >=0 ) MXTO(dp[i][j], dp[ close[i-1][dst-1] ] [j-(1<<a[i-1])] + dst);
                if (close[i-1][dst-1+1] >=0 ) MXTO(dp[i][j], dp[ close[i-1][dst-1+1] ] [j-(1<<a[i-1])] + dst + 1);
            }
        }
    }
    if ( dp[n][256 - 1] >0 ) {
        return dp[n][256 - 1];
    }else{
        return -100;
    }
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n;
    REP(i,n) {
        cin>>a[i], a[i]--;
        if (!seen[a[i]]) nap++;
        seen[a[i]]=1;
    }

    REP(i,8){
        if (!seen[i]){
            cout<<nap<<endl; return 0;
        }
    }
    vector<vector<int> > sn ( 8 );
    REP(i,n) {
        fill(close[i], close[i]+maxn, -1);
    }
    REP(i,n){
        sn[a[i]] .pb (i);
        REP(j, sn[a[i]].size()) {
            close[i][j] = sn[a[i]][sn[a[i]].size() - j -1];
        }
        // cout<<i<<' '<<close[i][2]<<endl;
        
    }
    // return 0;
    int l = 0, r = n-1;
    int re = 0;
    while (l!=r){
        int mid = (l+r)/2;
        int val = mv(mid);

        // cout << mid <<' ';
        if (val==-100){
            r = mid;
        }else{
            MXTO(re, val);
            l=mid+1;
            // cout<<" is ok\n" << val << endl;
        }
        // cout<<l<<' '<<r<<endl;
    }
    MXTO(re, mv(l+1)); MXTO(re, mv(l-1));
    cout<<re<<endl;
}