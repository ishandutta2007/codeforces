#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
#define ll long long
#define y1 zck_is_king
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
const int HF = 9;

bool smol[1<<HF]; // number of times each small mask appears, mod 2
bool bps[1<<HF][1<<HF]; // i,j: number of small masks attached to i, leq j
int ans[maxn];

vector<pii> que[maxn]; // L, i
bool chip[maxn];

signed main(){
    IOS();
    int n,m; cin>>n>>m;
    REP(i,n) {
        int x; cin>>x;
        chip[x] ^= 1;
    }
    int q; cin>>q;
    REP(i,q) {
        int l,r; cin>>l>>r;
        que[r+1].pb({l,i});
        que[l].pb({l,i});
    }
    int smk = (1<<HF)-1;
    for (int r = m; r>=1; --r) {
        if (chip[r]) {
//            nowxor ^= r;
            int rs = r & smk;
            smol[rs] ^= 1;
            int bg = (r ^ rs)>>HF;
            bug(bg, rs);
            for (int i = rs; i<(1<<HF); ++i) {
                bps[bg][i] ^= 1;
            }
        }

        for (auto P : que[r]) {
            int dst = P.f;
            int I = P.s;
            int dsmol = dst & (smk);
            int dbig = (dst ^ dsmol)>>HF; // shifted!
            int ss=0, bb=0;
            REP(j, (1<<HF)){
                if (smol[j]) {
                    ss ^= (j-dsmol<0?(j+(1<<HF)-dsmol):(j-dsmol));
                }
            }
            REP(j, 1<<HF) {
                // big mask :/
                bool more = dsmol==0?0:bps[j][dsmol-1];
                bool nor = bps[j][smk] ^ more;
                if (more) bb ^= (j - dbig -1);
                if (nor) bb ^= (j - dbig);
            }
            ans[I] ^= (ss) ^ (bb<<HF);
        }
    }

    REP(i,q) {
//        bug(i, ans[i]);
        cout<<"AB"[ans[i]==0];
    }


}