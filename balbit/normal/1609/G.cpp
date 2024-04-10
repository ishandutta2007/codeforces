#include <bits/stdc++.h>
#define int ll
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

const int maxn = 1e5+5;

ll a[maxn], b[maxn];

namespace BB{
    ll con[maxn], lin[maxn];
    void MOO(int e, ll c, ll li) {
        for (++e; e<maxn; e+=e&-e) {
            con[e] += c; lin[e] += li;
        }
    }
    ll QU(int e) {
        ll org = e;
        ll rC = 0, rL = 0;
        for (++e; e>0; e-=e&-e) {
            rC += con[e];
            rL += lin[e];
        }
        return rC + rL * org;
    }
};

ll s[maxn];
ll pool = 0;
void MO(int e, ll v) {

    assert(e>0); // 2^16 < maxn
    for (; e<maxn; e+=e&-e) {
        s[e] += v;
    }
}
int FIND(ll v) { // 1-indexed!!!
    v -= pool;
    int re = 0;
    for (int i = 16; i>=0; --i) {
        if ((re|(1<<i)) < maxn && s[re|(1<<i)] <= v) {
//            bug("added", re | (1<<i), s[re|(1<<i)]);
            re |= (1<<i);
            v -= s[re];
        }
    }
    return re;
}

signed main(){
    IOS();
    int n,m,q; cin>>n>>m>>q;
    ll tot = 0;
    REP(i,n) {
        cin>>b[i];
//        tot += b[i];
    }
    REP(i,m) {
        cin>>a[i];
        tot += a[i];
    }
    REP(i,m) {
        if (i) {
            if (i > 1) {
                MO(i, a[i] - a[i-1] - (a[i-1] - a[i-2]));
//                bug(i, a[i] - a[i-1] - (a[i-1] - a[i-2]) );
            }else{
                MO(i, a[i] - a[i-1]);
            }
        }
    }

//    bug(s[2]);


    REP(qqq, q) {
        int tp; cin>>tp;
        ll k,d; cin>>k>>d;
        if (tp == 1) {
            // brute force
            for (int i = 1; i<=k; ++i) {
                b[n-k-1+i] += i*d;
//                tot += i*d;
            }
//            REP(i,n) bug(i, b[i]);
        }else{
            BB::MOO(m-k, -(m-1-k) * d, d);
            tot += (k) * (k+1) / 2 * d;
            if (k != m) {
                bug(m-1-k+1, d);
                MO(m-1-k+1, d);
            }else{
                pool += d;
            }
//            bug(s[2]);
        }

        // now... calculate with extreme constant!?!?

        ll re = tot;
        int prv = 0;
        for (int i = 1; i<n; ++i) {
            // gotta see when i get to row i
            int pos = min(FIND(b[i]-b[i-1]), m-1);
            assert(pos >= prv);

            bug(b[i]-b[i-1],i, pos);
            re += (pos - prv + 1) * (b[i-1]);
            re += BB::QU(pos) + a[pos];
            prv = pos;
        }
        re += (m-1 - prv + 1) * b[n-1];
        cout<<re<<endl;
    }


}