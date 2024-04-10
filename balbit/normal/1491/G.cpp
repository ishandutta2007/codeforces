#include <bits/stdc++.h>
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

int p[maxn]; bool s[maxn];
bool seen[maxn];
vector<pii> re;

inline void go(int a, int b) {
    assert(a!=b);
    s[p[a]]^=1; s[p[b]]^=1;
    re.pb({a+1,b+1});
    swap(p[a],p[b]);
    bug(a+1, b+1);
}

void ass(bool x) {
    if( x == 0) {
        cout<<"Boo"<<endl; exit(0);
    }
}

signed main(){
    IOS();
    int n; cin>>n;
    REP(i,n) {
        cin>>p[i]; --p[i];
    }
    int st = -1;
    vector<int> solo;
    bool merged = 0;
    REP(i,n) {
        if (seen[i]) continue;
        seen[i] = 1;

        if (p[i] != i) {
            for (int j = p[i]; j!=i; j = p[j]) {
                seen[j] = 1;
            }
            if (st == -1) {
                st = i;
            }else{
                go(i, st);
                int j = i;
                REP(hi, 2) {
                    for (; s[p[p[j]]] == 0;) {
                        int to = p[j];
                        go(j, to); //j = to;
                    }
                    j = p[j];
                }
//                REP(i,n) bug(p[i]+1);
                bug(j, p[j], s[j], s[p[j]]);
//                assert(s[j] == 1 && s[p[j]] == 1 && j != p[j]);
                go(j, p[j]);
                st = -1;
                solo.pb(i);
            }
        }else{
            solo.pb(i);
        }
    }
    bug(st);
    if (st != -1) {
        if (p[p[st]] != st) {
            int one = p[st];
            go(st, one);
            while (p[p[st]] != st) {
                go(st, p[st]);
            }
            go(p[st], one);
        }else{
            int ar = solo.back();
            go(ar, st);
            st = ar;
        }
        bug(st, p[st], p[p[st]], p[p[p[st]]]);
        ass(p[p[st]] != st && p[p[p[st]]] == st);
        go(st, p[st]);
        go(st, p[st]);
    }
    #ifdef BALBIT
    REP(i,n) {
        cout<<p[i]+1<<' ';
    }
    cout<<endl;
    REP(i,n) {
        cout<<s[i]<<' ';
    }
    cout<<endl;
    #endif
    cout<<SZ(re)<<endl;
    for (pii p : re) cout<<p.f<<' '<<p.s<<endl;
}