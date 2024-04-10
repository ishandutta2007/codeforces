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

const int maxn = 51;

vector<pii> g[51];
int mem[51][51][51][51];
int p[51], wp[51], sm[51];
void dfs(int v, int par){
    for (pii ed : g[v]){
        if (ed.f != par){
            p[ed.f]=v;
            wp[ed.f]=ed.s;
            dfs(ed.f,v);
            sm[v]+=sm[ed.f];
        }
    }
}
int dp(int v, int from, int twk, int tot){
    bug(v,from,twk,tot);
    int &me = mem[v][from][twk][tot];
    if (me!=-1) return me;
    if (SZ(g[v]) == 1) {
        bug(v);
        if (twk == tot) return 0;
        return me = dp(from,v,tot-twk,tot-twk) + g[v][0].s;
    }
    vector<pii> ch; // {id, len}
    vector<array<int,51> > pref (SZ(g[v]));
    REP(i,51) pref[0][i]=0;
    pref[0][0]=iinf;
    int i = 0;
    for (pii u : g[v]){
        if (u.f != from){
            ++i;
//            bug(i);
//            ch.pb(u.f);
            int b = 0;
            REP(j,twk+1){
//                bug(j);
//                pref[i][j]=0;
//                int nans = min(pref[i-1][j-b],(b!=0? dp(u.f,v,b,tot) +u.s:iinf));
//                while (nans >= pref[i][j]){
//                    pref[i][j] = nans; ++b;
//                    if (b > j) {
//                        break;
//                    }
////                    bug(b);
//                    nans = min(pref[i-1][j-b],(b!=0? dp(u.f,v,b,tot) +u.s:iinf));
////                    if (nans != 0) bug("AYY");
//                }
//                --b;

                REP(B,j+1){
                    MX(pref[i][j],min(pref[i-1][j-B],(B!=0? dp(u.f,v,B,tot) +u.s:iinf)));
                }

            }
        }
    }
    bug(pref[i][twk]);
    return me = pref[i][twk];
}

signed main(){
    IOS();
    int n; cin>>n;
    REP(i,n-1){
        int a, b; cin>>a>>b; --a; --b;
        int w; cin>>w;
        g[a].pb({b,w}); g[b].pb({a,w});
    }
    int s; cin>>s; --s;
    int m; cin>>m;
    int tt = 0;
    REP(i,m){
        int x; cin>>x; --x;
        if (x!=s) sm[x]++, tt++;
    }
    dfs(s,-1);
    REP(i,51)REP(j,51)REP(k,51)REP(l,51) mem[i][j][k][l]=-1;
    int re = iinf;
    for (pii u : g[s]){
        bug(u.f, sm[u.f]);
        if (sm[u.f]==0) continue;
        bug(sm[u.f]);
        int mo = dp(u.f,s,sm[u.f],tt) + u.s;
        bug(mo);
        MN(re, mo);
    }
    cout<<re<<endl;
}