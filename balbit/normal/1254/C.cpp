#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

#define int ll

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

const int maxn = 1004;


main(){
    IOS();
    int n; cin>>n;
    int A = n-1, B = n-2;
    vector<pair<ll, int> > pA, pB;
    REP(i,n-2){
        cout<<1<<' '<<A+1<<' '<<B+1<<' '<<i+1<<endl<<flush; 
        ll area; cin>>area;
        cout<<2<<' '<<A+1<<' '<<B+1<<' '<<i+1<<endl<<flush; 
        int sgn; cin>>sgn;
        if (sgn == 1){
            pA.pb({area,i});
        }else{
            pB.pb({area,i});
        }
    }

    vector<int> ans;
    if (SZ(pA)){
        sort(ALL(pA), greater<pii>()); 
        vector<pair<ll, int> > p1, p2;
        int M = pA[0].s;
        FOR(i,1,SZ(pA)){
            int it = pA[i].s;
            cout<<2<<' '<<A+1<<' '<<M+1<<' '<<it+1<<endl<<flush; 
            int sgn; cin>>sgn;
            if (sgn == -1){ // Before M
                p1.pb(pA[i]);
            }else{
                p2.pb(pA[i]);
            }
        }
        sort(ALL(p1)); // Increasing
        sort(ALL(p2), greater<pii > ()); // Decreasing
        for ( auto & x : p1) ans.pb(x.s);
        ans.pb(M);
        for ( auto & x : p2) ans.pb(x.s);
        
    }
    ans.pb(A);
    if (SZ(pB)){
        sort(ALL(pB), greater<pii>()); 
        vector<pair<ll, int> > p1, p2;
        int M = pB[0].s;
        FOR(i,1,SZ(pB)){
            int it = pB[i].s;
            cout<<2<<' '<<A+1<<' '<<M+1<<' '<<it+1<<endl<<flush; 
            int sgn; cin>>sgn;
            if (sgn == -1){ // Before M
                p1.pb(pB[i]);
            }else{
                p2.pb(pB[i]);
            }
        }
        sort(ALL(p1)); // Increasing
        sort(ALL(p2), greater<pii > ()); // Decreasing
        for ( auto & x : p1) ans.pb(x.s);
        ans.pb(M);
        for ( auto & x : p2) ans.pb(x.s);
        
    }
    ans.pb(B);
    cout<<0<<' ';
    int at1 = 0;
    REP(i, SZ(ans)) {
        if (ans[i] == 0) {
            at1 = i; break;
        }
    }
    REP(i,SZ(ans)) {
        cout<<ans[(i+at1)%SZ(ans)]+1<<' ';
    }
    cout<<flush;

}