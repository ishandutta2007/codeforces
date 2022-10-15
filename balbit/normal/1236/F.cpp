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

//void prt(ll x) {
//
//}

template<typename T> void _do(T &&x){cout<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1e9+10;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


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

const int maxn = 1e6+5;

vector<vector<int> > faces;

bool seen[maxn];
vector<int> g[maxn];

int par[maxn];
int ts[maxn];
int ITT=0;

ll p2n[maxn]; // negative powers of 2

void dfs(int v, int p) {
    seen[v] = 1;
    ts[v] = ITT++;
    par[v] = p;
    for (int u : g[v]) {
        if (u != p) {
            if (seen[u]) {
                // face!
                if (ts[u] < ts[v]) {
                    vector<int> tmp;
                    for (int at = v; at != u; at = par[at]) {
                        tmp.pb(at);
                    }
                    tmp.pb(u);
                    bug("new face!");
                    for (int x : tmp) bug(x+1);
                    faces.pb(tmp);
                }
            }else{
                dfs(u,v);
            }
        }
    }
}

vector<pii> edges;

ll sighere[maxn]; // sum of 2^-t for faces touching this node

inline void add(int &a, int b) {
    a += b; a %= mod;
}

string prt(ll x ) {
    ll den = 1;
    while (x > 1000) {
        x *= 2; den *= 2; x %= mod;
    }
    return to_string(x)+" / "+to_string(den);
}


signed main(){
    IOS();

    p2n[0] = 1;
    ll i2 = inv(2);
    for (int i = 1; i<maxn; ++i) {
        p2n[i] = p2n[i-1] * i2 % mod;
    }

    int n,m; cin>>n>>m;
    REP(i,m) {
        int a,b; cin>>a>>b; --a; --b;
        g[a].pb(b); g[b].pb(a);
        edges.pb({a,b});
    }

    dfs(0, -1);


    ll V=0,E=0,F=0; // expected values of these raw ones


//    ll Fstuff = 0; // E[F * (F - 2E + 2V)]
    ll FE=0,FF=0,FV=0;

    ll sigt=0; // sum of 2^(-t) for each face
    for(vector<int> v : faces) {
        int s = SZ(v);
        for (int x : v) {
            add(sighere[x], p2n[s]);
        }
        add(sigt, p2n[s]);
    }

    for (vector<int> v : faces) {
        ll s = SZ(v);
        bug(s, v[0], v[1], v[2]);

        F += p2n[s];

        {// work with FF first
            add(FF, p2n[s] * (((sigt) - p2n[s] + mod)% mod) %mod);
            for (int x : v) {
                add(FF, p2n[s] * (((sighere[x]) - p2n[s] + mod)% mod) %mod);
            }
            add(FF, p2n[s]);
        }

        { // now work with FE
            int touch = 0;
            for (int x : v) {
                touch += SZ(g[x]) - 2;
            }
            int notouch = m - touch - s;

            bug(touch, notouch);
            add(FE, p2n[s] * s % mod);
            add(FE, p2n[s+1] * touch % mod);
            add(FE, p2n[s+2] * notouch % mod);
        }

        { // finally, FV
            add(FV, p2n[s] * s % mod);
            add(FV, p2n[s+1] * (n-s) % mod);
        }
    }

    ll EV=0, VV=0, EE=0;

    {
        VV = n * ((n-1) * p2n[2] % mod + p2n[1]) % mod;
        V = n * p2n[1] % mod;
    }

    {
        E = m * p2n[2] % mod;
        for (pii e : edges) {
            int a = e.f, b = e.s;
            int touch = SZ(g[a]) -1 + SZ(g[b]) - 1;

            EE += (1 * p2n[2]+
                   touch * p2n[3] +
                   (m-touch-1) * p2n[4]
                   ) % mod;

            EV += (2 * p2n[2] +
                    (n-2) * p2n[3]
                  ) % mod;
        }
    }

    bug(prt(V),prt(E),prt(F));
//    prt(V);
//    prt(E);
//    prt(F);
    bug(prt(FF), prt(FE), prt(FV));
    bug(prt(EV), prt(EE), prt(VV));

    ll exp = (V-E+F + mod) % mod;
    ll expsq = exp * exp % mod;


    ll exx = VV + EE + FF + 2*FV - 2 * EV - 2 * FE;
    exx = (exx % mod + mod) % mod;

    bug(prt(exx), prt(exp), prt(expsq));

    cout<<(exx-expsq+mod)%mod<<endl;






}