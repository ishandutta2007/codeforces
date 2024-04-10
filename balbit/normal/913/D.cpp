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

struct ev{
    int a, t;
    int id;
};

bool cmp(ev a, ev b) {
    if (a.a!=b.a) return a.a<b.a;
    return a.t<b.t;
}

signed main(){
    IOS();
    int n, T; cin>>n>>T;
    vector<ev> v;
    REP(i,n) {
        int a, t; cin>>a>>t;
        v.pb({a,t,i+1});
    }
    sort(ALL(v),cmp);
    int l = 0, r = n+1;
    while (l!=r)  {
        int mid = (l+r)/2;
        bool B = 1;
        vector<int> v2;
        REP(i,n) {
            if (v[i].a>=mid) v2.pb(v[i].t);
        }
        if (SZ(v2)<mid) {
            r=mid; continue;
        }
        sort(ALL(v2));
        ll tt = 0;
        REP(i,mid) {
            tt += v2[i];
        }
        if (tt<=T) {
            l=mid+1;
        }else{
            r=mid;
        }
    }
    cout<<l-1<<endl<<l-1<<endl;
    vector<ev> moe;
    REP(i,n) {
        if (v[i].a>=l-1) moe.pb(v[i]);
    }
    sort(ALL(moe),[&](ev a, ev b){return a.t<b.t;});
    REP(i,l-1) {
        cout<<moe[i].id<<' ';
    }

}