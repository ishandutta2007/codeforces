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


ll A, B, C, D,n;
int s[maxn*4];
int QU(int L, int R, int o = 1, int l = 0, int r = n*2+1){
    if (l>R || r<L) return 0;
    if (l>=L && r<=R) return s[o];
    int mid = (l+r)/2;
    return max(QU(L,R,o*2,l,mid),QU(L,R,o*2+1,mid+1,r));
}
void MO(int p, int v, int o = 1, int l = 0, int r = n*2+1){
    if (l>p || r<p) return;
    if (l==r){
        MX(s[o],v); return;
    }
    int mid = (l+r)/2;
    MO(p,v,o*2,l,mid); MO(p,v,o*2+1,mid+1,r);
    s[o]=max(s[o*2],s[o*2+1]);
}
struct Ev{
    bool TP; // 0 is start, 1 is end
    ll p, id;
};
signed main(){
//    IOS();
    scanf("%lld\n%lld/%lld %lld/%lld",&n,&A,&B,&C,&D);
    vector<Ev> v;
//    map<ll, int> mp;
    vector<ll> start(n+1);
    ll BB = 2e10;
    REP(i,n){
        ll x,y; scanf("%lld%lld",&x,&y);
        bug(x,y);
        v.pb({0,-A*x+B*y,i});
        v.pb({1,-C*x+D*y+BB,i});
//        bug(-A*x+B*y,-C*x+D*y+BB);
        start[i] = -A*x+B*y;
    }
    v.pb({0,0,n});
    v.pb({1,0ll+BB,n});
    start[n]=0;
    sort(ALL(v),[&](Ev a, Ev b){return a.p!=b.p?a.p<b.p:start[a.id]<start[b.id];});
    vector<ll> tmp;
    REP(i,SZ(v)){
        tmp.pb(v[i].p);
    }
    SORT_UNIQUE(tmp);
    REP(i,SZ(v)){
        if (v[i].TP == 0){
        }else{
            bug(v[i].id, start[v[i].id]);
            int st = lower_bound(ALL(tmp),start[v[i].id])-tmp.begin();
            int en = lower_bound(ALL(tmp),v[i].p)-tmp.begin();
            ll Q = QU(st+1,en-1);
//            if (v[i].id == n || Q!=0) Q++;
//            if (Q==0) continue;
            MO(st,Q+1);
            bug(v[i].id,st,en,Q+1);
            if (v[i].id == n){
                printf("%d\n",Q); return 0;
            }
        }
    }

    // Check your array bounds!
    // Think about corner cases (smallest or biggest?)
}