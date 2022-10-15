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

const int maxn = 2e5+5;

int p[maxn][26];

signed main(){
    IOS();
    string s; cin>>s;
    int n = s.length();
    REP(i,n) {
        REP(j,26) p[i+1][j] += p[i][j];
        p[i+1][s[i]-'a']++;
    }
    int q; cin>>q;
    while (q--) {
        int l, r; cin>>l>>r; --l; --r;
        if (l==r) {
            cout<<"Yes"<<endl;
        }else{
            if (s[l]!=s[r]) {
                cout<<"Yes"<<endl;
            }else{
                int tp = 0;
                REP(j,26) {
                    if (p[r+1][j]-p[l][j] > 0) tp ++;
                }
                bug(tp);
                if (tp > 2) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
        }
    }
    // Check your array bounds!
    // Think about corner cases (smallest or biggest?)
}