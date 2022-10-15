#include <bits/stdc++.h>
#define int ll
using namespace std;
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
const ll inf = 1ll<<60;
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
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 2e5+5;

vector<int> gs[maxn];
ll sum[maxn];

struct seg{
    vector<int> mn,tg;
    int MXV;
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
    void MO(int L, int R, ll v, int o, int l, int r) {
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

    void MO(int L, int R, int v) {
//        bug(L, v);
        MO(0,L,-v, 1, 0, MXV-1);
    }

//    ll QU(int L, int R, int o=1, int l=0, int r=MXV-1) {
//        push(o,l,r);
//        if (l>R || r<L) return INF;
//        if (l>=L && r<=R) {
//            return mn[o];
//        }
//        int mid = (l+r)/2;
//        return min(QU(L,R,o*2,l,mid), QU(L,R,o*2+1,mid+1,r));
//    }
    seg(int s): MXV(s){
        mn.resize(s*4);
        tg.resize(s*4);
    }

};

//int a[maxn];

signed main(){
    IOS();
    int t; cin>>t;
    while (t--) {
        int n,m; cin>>n>>m;
        auto cmp = [&](pii a, pii b) {return a.f * b.s < b.f * a.s;};
        vector<pii> ev;
        vector<int> a(n);
        REP(i,n) {
            cin>>a[i];
            ev.pb({a[i], 1});
        }
//        vector<pii> gp;


        REP(i,m) {
            int k; cin>>k;
            gs[i].clear(); gs[i].resize(k);
            sum[i] = 0;
            REP(j,k) cin>>gs[i][j], sum[i] += gs[i][j];
            ll A = sum[i], B = k;
            ll g = __gcd(A,B);
            A/=g; B/=g;
            ev.pb({A,B});
        }

       sort(ALL(ev), cmp);
       ev.resize(unique(ALL(ev)) - ev.begin());


        int SS = SZ(ev)+1;
        seg YA(SS);

        REP(i,n) {
            int at = lower_bound(ALL(ev), make_pair(a[i],1), cmp) - ev.begin();
            YA.MO(at, SS-1,-1);
        }

        REP(i,m) {
            ll A = sum[i], B = SZ(gs[i]);
            ll g = __gcd(A,B);
            A/=g; B/=g;
            int at = lower_bound(ALL(ev), make_pair(A,B), cmp) - ev.begin();
            YA.MO(at, SS-1,1);
        }

        REP(i,m) {
            ll A = sum[i], B = SZ(gs[i]);
            ll g = __gcd(A,B);
            A/=g; B/=g;
            int tat = lower_bound(ALL(ev), make_pair(A,B), cmp) - ev.begin();
            YA.MO(tat, SS-1,-1);

            for (int s : gs[i]) {
                ll aa = sum[i] - s, bb = SZ(gs[i])-1;
                ll gg = __gcd(aa,bb); aa/=gg; bb/=gg;
                int at = lower_bound(ALL(ev), make_pair(aa,bb), cmp) - ev.begin();
                YA.MO(at, SS-1,1);
//                bug(YA.mn[1]);
                if (YA.mn[1] < 0) cout<<0;
                else cout<<1;

                YA.MO(at, SS-1, -1);
            }

            YA.MO(tat, SS-1,1);
        }
        cout<<endl;


    }


}