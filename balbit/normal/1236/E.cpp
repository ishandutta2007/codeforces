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

ll inv (ll b){
    return b==1?1:(mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 1e5+5;

int pos[maxn];
vector<int> at[maxn*2];
vector<int> at2[maxn*2];

int rb[maxn], lb[maxn];

signed main(){
    IOS();
    int n, m; cin>>n>>m;
    if (n==1) {
        cout<<0<<endl;
        return 0;
    }
    REP(i,m) {
        cin>>pos[i]; pos[i]--;
        at[i-pos[i]+maxn].pb(i);
        at2[pos[i]+i].pb(i);
    }
    RREP(i,m) {
        int d = i-pos[i]+1+maxn;
        int fg = lower_bound(ALL(at[d]),i) - at[d].begin();
        if (fg >= SZ(at[d])) {
            rb[i] = min(n-1, pos[i]-1 + m-i);
        }else{
            bug(i,at[d][fg]);
            rb[i] = rb[at[d][fg]];
        }
        bug(i,rb[i]);
    }

    RREP(i,m) {
        int d = pos[i]+i+1;
        int fg = lower_bound(ALL(at2[d]),i) - at2[d].begin();
        if (fg >= SZ(at2[d])) {
            lb[i] = max(0, pos[i]+1 - (m-i) );
        }else{
            bug(i,at2[d][fg]);
            lb[i] = lb[at2[d][fg]];
        }
        bug(i,lb[i]);
    }
    ll re = 0;
    REP(i,n) {
        int l, r;
        {
            int d = -1-i-1+1+maxn;
            int fg = lower_bound(ALL(at[d]),-1) - at[d].begin();
            if (fg >= SZ(at[d])) {
                r = min(n-1, i+1-1 + m+1);
            }else{
                r = rb[at[d][fg]];
            }
        }
        {
            int d = i-1+-1+1;
            int fg = lower_bound(ALL(at2[d]),-1) - at2[d].begin();
            if (fg >= SZ(at2[d])) {
                l = max(0, i-1+1 - (m+1) );
            }else{
                bug(-1,at2[d][fg]);
                l = lb[at2[d][fg]];
            }
        }
        bug(l,r);
        re += r-l+1;
    }
    cout<<re<<endl;
    // Check your array bounds!
    // Think about corner cases (smallest or biggest?)
}