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

bool useless[maxn]; // this jar is useless!

bool win[maxn]; // this jar is direct victory!

int nwin = 0; // number of direct victories

struct pt{
    ll x, y; // remember, they can be VERY BIG!!!
    inline bool poscross(pt b) const {
        return x * (__int128)b.y - y * (__int128)b.x > 0;
    }
    inline bool ontop() const {
        return (y>0) || (y == 0 && x > 0);
    }
    bool operator < (const pt &b) const {
        if (ontop() != b.ontop()) {
            return ontop() > b.ontop(); // the one on top first
        }else{
            return poscross(b);
        }
    }
    bool operator == (const pt &b) const {
        return x == b.x && y == b.y;
    }
};

int npair = 0;

multiset<pt> st;
map<pt, int> ba;

pt here[maxn];

int get(){
    if (nwin) return 1;
    if (npair) return 2;
    if (st.empty() || (*st.begin() == *st.rbegin())) return 0;
    for (pt P : {pt{1,0}, pt{-1,0}}) {
        auto it = st.lower_bound(P);
        if (it == st.end()) it = st.begin();
        auto pit= it==st.begin()?prev(st.end()) : prev(it);
        if ((*it).poscross(*pit)) return 0;
    }
    return 3;
}

signed main(){
    IOS();
    ll AA,BB,CC; cin>>AA>>BB>>CC;
    int n; cin>>n;
    int IT = 1;
    REP(i,n) {
        char tp; cin>>tp;
        if (tp == 'A') {
            ll a,b,c; cin>>a>>b>>c;
            a *= max(BB, 1ll) * max(CC, 1ll);
            b *= max(AA, 1ll) * max(CC, 1ll);
            c *= max(BB, 1ll) * max(AA, 1ll);
            bug(a,b,c);


            if ( (AA == 0 && a != 0) ||
                 (BB == 0 && b != 0) ||
                 (CC == 0 && c != 0) ) {
                // useless!
                useless[IT] = 1;
            }else{
                // maybe useful??

                pt P;
                if (AA==0 || BB == 0 || CC == 0) {
                    if ((AA==0 && BB == 0) ||
                        (CC==0 && BB == 0) ||
                        (AA==0 && CC == 0)
                        ) {
                            P = {0,0};
                    }else{
                        if (CC == 0) P = {0, a-b};
                        else if (AA == 0) P = {0, b-c};
                        else if (BB == 0) P = {0, a-c};
                    }
                }else{
                    P = {b-a, c-a};
                }
                if (P.x != 0 || P.y != 0) {
                    ll g = __gcd(abs(P.x), abs(P.y));
                    P.x /= g; P.y /= g;
                }
                here[IT] = P;
                if (P.x == 0 && P.y == 0) {
                    win[IT] = 1;
                    ++nwin;
                    bug(i,nwin);
                }else{
                    st.insert(P);
                    if (ba.count({-P.x, -P.y})) npair += ba[{-P.x, -P.y}];
                    ++ba[P];
                }
            }

            ++IT;

        }else{
            int ha; cin>>ha;

            if (!useless[ha]) {
                if (win[ha]) {

                    --nwin;
                }else{
                    pt P = here[ha];
                    st.erase(st.find(P));
                    if (ba.count({-P.x, -P.y})) npair -= ba[{-P.x, -P.y}];
                    --ba[P];
                }
            }
        }
        cout<<get()<<endl;
    }


}


/*
0 1 0
3

*/