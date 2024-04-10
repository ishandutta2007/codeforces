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
const ll inf = 0x3f3f3f3f3f3f3f3f;
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

const int maxn = 1e5+5;

struct pt{
    int x,y;
    int lay(){
        return max(x,y);
    }
    void in(){
        cin>>x>>y;--x;  --y;
    }
};

inline int dst(pt a, pt b) {
//    assert(a.lay() == b.lay());
    return  abs(a.x  - b.x) + abs(a.y - b.y);
}

pt A[maxn][2];

typedef array<array<int, 2>, 2> SS;

SS D[maxn*4];

SS mrg(SS &pl, SS &pr, int mid){
    SS to;
    REP(a,2) REP(b,2) {
        to[a][b] = inf;
        int df =  dst(A[mid][0], A[mid][1]);
        REP(c,2) REP(d,2) {
            MN(to[a][b], pl[a][c] + pr[d][b] + (c==d?0:df));
        }
    }
    return to;
}



void build(int o, int l, int r) { // l,r means going from l to r+1
    if (l == r) {
        REP(a,2) REP(b,2) {
            D[o][a][b] = dst({A[l][a].x+(a==0), A[l][a].y+(a==1)}, A[l+1][b]);
        }
        REP(a,2) REP(b,2) {
            MN(D[o][a][b], dst(A[l][0], A[l][1])+ D[o][a^1][b]);
        }
        return;
    }
    int mid = (l+r)/2;
    build(o*2, l, mid); build(o*2+1, mid+1, r);
    D[o] = mrg(D[o*2], D[o*2+1], mid+1);
}

SS bad = {{{{-1,-1}},{{-1,-1}}}};
SS noth = {{{{0,0}},{{0,0}}}};

SS QU(int L, int R, int o, int l, int r) {
    if (L > R) {
        SS ret = noth;
        ret[0][1] = ret[1][0] = dst(A[L][0], A[L][1]);
        return ret;
    }
    if (l >= L && r <= R) {
        return D[o];
    }
    if (l > R || r < L) {
        return bad;
    }
    int mid = (l+r)/2;
    SS ql = QU(L,R,o*2,l,mid), qr = QU(L,R,o*2+1,mid+1,r);
    if (ql[0][0] == -1) return qr;
    if (qr[0][0] == -1) return ql;
    return mrg(ql,qr,mid+1);
}

signed main(){
    IOS();

    int n; cin>>n;
    REP(i,n-1) {
        REP(b,2) A[i][b].in();
    }
    bug("ok");
    build(1,0,n-2);
    bug("ok");
    int q; cin>>q;
    REP(i,q) {
        pt p1, p2; p1.in(); p2.in();
        if (p1.lay() >  p2.lay())  swap(p1, p2);
        int L1 = p1.lay(), L2 = p2.lay();
        if (L1 == L2) {
            cout<<dst(p1, p2)<<endl; continue;
        }
        SS btw = QU(L1, L2-2,1,0,n-2);
        bug(btw[0][0], btw[0][1], btw[1][0], btw[1][1]);
        ll re = inf;
        REP(a,2) {
            REP(b,2) {
                MN(re, btw[a][b] + dst(p1, A[L1][a]) + dst(p2, pt{A[L2-1][b].x + (b==0), A[L2-1][b].y + (b==1)}));
            }
        }
        cout<<re + (L2-L1)<<endl;
    }
}