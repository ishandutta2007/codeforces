#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
#define REP1(i,n) FOR(i,1,n+1)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
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

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e5+5;

ll dp[3003][105][2];

signed main(){
    IOS();
    string a, b;
    cin>>a>>b;
    int n = a.length(), m = b.length();
    vector<int> at(m+1);
    at[0]=-1;
    int l1 = 0;
    int mx = 0;
    REP(i,m) {
        at[i+1] = at[i]+1;
        while (at[i+1]<n && a[at[i+1]] != b[i]) at[i+1]++;
        if (at[i+1]<n) {
            l1 = i+1; mx = i+1;
        }
        cerr<<at[i+1]<<' ';
    }
    cerr<<endl;
    int j = n;
    bug(mx);
    int k = m;
    RREP(i,m) {
        j--;
        while (j>=0 && a[j]!=b[i]) j--;
        if (j<0) break;
        while (k>=0 && at[k]>=j) k--;
        int ans = k + (m-i);
        if (ans > mx) {
            mx = ans;
            l1 = k;
        }
        bug(i,j,k,ans);
    }
    MN(mx, m);
    if (mx==0) cout<<'-'<<endl;
    else {
        bug(l1, m-(mx-l1));
        REP(i,l1) {
            cout<<b[i];
        }
        FOR(i,m-(mx-l1),m) {
            cout<<b[i];
        }

    }
}