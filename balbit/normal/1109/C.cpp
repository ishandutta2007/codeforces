#include <bits/stdc++.h>
using namespace std;
#define ll __int128
#define int __int128
#define double long double
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
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
template<typename T> void _do(T &&x){cerr<<(long long)x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<(long long)x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1e9+10;
const ll inf = 1e18+2;
const __int128 INF = 1e25;
const ll mod = 1e9+7 ;


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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e5+5;

ll mn[maxn*4], tg[maxn*4];
set<ll> have;
//map<ll, int> id;

void push(int o, int l, int r){
    if (tg[o]) {
        mn[o] += tg[o];
        if (l!=r) {
            tg[o*2] += tg[o];
            tg[o*2+1] += tg[o];
        }
        tg[o] = 0;
    }
}
int n;
void MO(int L, int R, ll v, int o=1, int l=0, int r=n-1) {
    push(o,l,r);
    if (l>R || r<L) return;
    if (l >= L && r <= R) {
        tg[o] += v;
        push(o,l,r);
        return;
    }
    int mid = (l+r)/2;
    MO(L,R,v,o*2,l,mid);
    MO(L,R,v,o*2+1,mid+1,r);
    mn[o] = min(mn[o*2], mn[o*2+1]);
}

ll QU(int L, int R, int o=1, int l=0, int r=n-1) {
    push(o,l,r);
    if (l>R || r<L) return INF;
    if (l>=L && r<=R) {
        return mn[o];
    }
    int mid = (l+r)/2;
    return min(QU(L,R,o*2,l,mid), QU(L,R,o*2+1,mid+1,r));
}

struct Que{
    int Tp;
    int t,s,l,r,v;
};

int slope[maxn];
bool state[maxn];

signed main(){
    IOS();
    signed Q; cin>>Q;
    vector<Que> queries;
    vector<ll> allt;
    allt.pb(0); allt.pb(1000000005);
    have.insert(0); have.insert(1000000005);
    for (int i = 0; i<Q; ++i) {
        signed Tp; cin>>Tp;
        if (Tp == 1) {
            signed t,s;cin>>t>>s; allt.pb(t);
            queries.pb({Tp,t,s,0,0,0});
        }
        if (Tp == 2) {
            signed t; cin>>t; allt.pb(t);
            queries.pb({Tp,t,0,0,0,0});
        }
        if (Tp == 3) {
            signed l,r,v; cin>>l>>r>>v;
            queries.pb({Tp,0,0,l,r,v});
        }
    }
    SORT_UNIQUE(allt);
    n = SZ(allt);
    bug(n);
    MO(1,n-2,inf);
//    MO(0,0,-inf);
//    MO(n-1,n-1,-inf);
    state[0] = 1;
    cout<<fixed<<setprecision(10);
    for (Que q: queries) {
        int lp, rp;

        if (q.Tp == 1) {

            lp = *prev(have.upper_bound(q.t)), rp = *have.upper_bound(q.t);
            int lat = lower_bound(ALL(allt), lp) - allt.begin();
            int rat = lower_bound(ALL(allt), rp) - allt.begin();
            int mat = lower_bound(ALL(allt), q.t) - allt.begin();
            assert(rat!=mat);
            assert(lat != mat);
            ll bfr = QU(rat,rat);
//            __int128 tmp = (q.t-lp) * (__int128)(bfr - QU(lat,lat));
//            if(tmp % ((rp-lp)) != 0)while(1);
            ll myv = QU(lat,lat) + slope[lat] * (q.t-lp);
            ll prevme = QU(mat,mat);
            bug(prevme, myv);

            MO(mat,mat,myv-prevme);
            bug(QU(mat,mat));
            assert(myv == QU(mat,mat));

            slope[mat] = q.s;
            ll newr = myv + (rp-q.t) * q.s;
            MO(rat, n-1, newr-bfr);
            bug(rat, (rp-q.t) * q.s);
            bug(mat, QU(mat,mat), QU(rat, rat));
            have.insert(q.t);
        }

        if(q.Tp==2) {
            if (!have.count(q.t)) assert(0);
            have.erase(q.t);
            lp = *prev(have.upper_bound(q.t)), rp = *have.upper_bound(q.t);
            int lat = lower_bound(ALL(allt), lp) - allt.begin();
            int rat = lower_bound(ALL(allt), rp) - allt.begin();
            int mat = lower_bound(ALL(allt), q.t) - allt.begin();
            MO(mat, mat, inf-QU(mat,mat));
            ll oldr = QU(rat, rat);
            ll newr = (rp-lp) * slope[lat] + QU(lat, lat);
            MO(rat, n-1, newr-oldr);
        }

        if (q.Tp == 3) {
            ll st = *have.lower_bound(q.l), stp = lower_bound(ALL(allt), st) - allt.begin();
            int mat = lower_bound(ALL(allt), q.l) - allt.begin();
//            bug(lp,rp,lat,rat);
//            bug(QU(lat,lat), QU(rat, rat));
            ll myv = QU(stp,stp);
            bug(q.l, myv);
            if (q.v == 0) {
                cout<<(long long)q.l<<endl; continue;
            }
            myv -= q.v;
            int l = mat, r = n-1;
            while(l!=r) {
                int mid = (l+r)/2;
                if (QU(mat, mid)<=myv) {
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            bug(l);
            if ( l >= n || l == mat) {
                cout<<-1<<endl; continue;
            }
//            assert(have.count(allt[l]));
            int prv = *prev(have.lower_bound(allt[l])), pp = lower_bound(ALL(allt), prv) - allt.begin();
            int A = QU(pp,pp), B = QU(l,l);
            bug(pp,l);
            bug(A,B,prv, allt[l]);
            if (B <= myv) {
                if (A==B) while(1);
                double ans = (myv-A) / (double) (B-A) * (allt[l]-prv)   + prv;
                if (ans <= q.r +1e-12 ) cout<<ans<<endl;
                else cout<<-1<<endl;
            }else{
//                assert(0);
                cout<<-1<<endl;
            }
        }
    }
}