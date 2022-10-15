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

const int maxn = 2e6+5;

bool dead[maxn];
map<int, int> mp;
vector<pii> g[maxn]; // to, id
bool used[maxn];
bool done[maxn];

int par[maxn];
int ed[maxn], sz[maxn];
void setup(int n) {REP(i,n) par[i]=i, ed[i]=0, sz[i]=1;}
int find(int x){if(x==par[x])return x;return par[x]=find(par[x]);}

void merge(int a, int b) {
    a = find(a); b = find(b);
    ed[b]++;
    if (a==b) return;
    sz[b]+=sz[a]; ed[b] += ed[a];
    par[a]=b;
}



bool go(int x) {
    if (done[x]) return 1;
    for (pii u : g[x]) {
        if (used[u.s]) continue;
        used[u.s]=1;
        {
            if (dead[u.f]) return 0;
            dead[u.f]=1;
            if (!go(u.f)) return 0;
        }
    }
    done[x]=1;
    return 1;
}

signed main(){
    IOS();
    int n; cin>>n;
    vector<pii > v(n);
    vector<int> tmp;
    REP(i,n) {
        cin>>v[i].f>>v[i].s; tmp.pb(v[i].f); tmp.pb(v[i].s);
    }
    SORT_UNIQUE(tmp);
    REP(i,SZ(tmp)) mp[tmp[i]] = i;
    REP(i,n) {
        v[i].f = mp[v[i].f];
        v[i].s = mp[v[i].s];
        bug(v[i].f, v[i].s);
        g[v[i].f].pb({v[i].s,i});
        g[v[i].s].pb({v[i].f,i});
    }
    bug(SZ(tmp));
    tmp.pb(-1);
    sort(ALL(v), [&](pii a,pii b){if(a.s!=b.s) return a.s>b.s;return a.f>b.f;});
    int l = 0, r = SZ(tmp)-1;
    while (l!=r) {
        bool ok = 1;
        int m = (l+r)/2;
        setup(SZ(tmp));
        fill(used, used+maxn, 0);
        fill(done, done+maxn, 0);
        fill(dead, dead+m+1, 0);
        fill(dead+m+1, dead+maxn,1);
        for (pii & e : v) {
            if (dead[e.s] ) {
                if (!go(e.s)) {
                        ok=0;break;}
            }
            else if (dead[e.f]) {
                if (!go(e.f)) {ok=0;break;}
            }else{
                merge(e.f,e.s);
            }
        }
        if (ok) REP(i,n) {
            if (!dead[i]) {
                int p = find(i);
                bug(ed[p], sz[p]);
                if (ed[p]>sz[p]) {
                    ok=0; break;
                }
            }
        }
        if (ok) {
            bug("WOt",m);
            r=m;
        }else{
            l = m+1;
        }
    }
//    if (l==SZ(tmp)-1) cout<<-1<<endl;
    cout<<tmp[l]<<endl;
}