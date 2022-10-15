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

const int maxn = 1e5+5;

const int BS = 300;

int sz[maxn], par[maxn], dst[maxn];

bool RE = 1;

struct Ev{
    int at; // Thing that was merged
//    int dd; // Previous distance
    bool B; // State before this merge
};
vector<int> g[maxn];
stack<Ev> stk;
void setup(){
    REP(i,maxn){
        sz[i]=1; par[i]=i; dst[i]=0;
    }
}
pair<int, int> find(int x){
    if (x == par[x]) return {x,0};
    pair<int, int> fp = find(par[x]);
    return {fp.f,fp.s^dst[x]};
}
void undo(){
    if (stk.top().at != -1){
        sz[par[stk.top().at]]-=sz[stk.top().at];
//        bug("Freed",stk.top().at);
        par[stk.top().at]=stk.top().at;
    }
//    dst[stk.top().at]=dd;
    RE = stk.top().B;
    stk.pop();
}
void merge(int a, int b){
    pii fa = find(a), fb = find(b);
    if (fa.f == fb.f){
        stk.push({-1,RE});
        if (fa.s==fb.s) RE = 0;
        return;
    }
    if (sz[fa.f]>sz[fb.f]) {
        swap(a,b); swap(fa,fb);
    }
    stk.push({fa.f,RE});
    sz[fb.f]+=sz[fa.f];
    par[fa.f]=fb.f;
    dst[fa.f] = fa.s ^ fb.s ^ 1;
}
bool seen[maxn];
void dfs(int v){
    seen[v]=1;
    for (int u : g[v]){
        if (!seen[u]) {
            dfs(u);
        }
        if (u>v) merge(u,v);
    }
}
signed main(){
    IOS();
    int n; cin>>n;
    vector<pii> E;
    map<pii, bool> hv;
    int q; cin>>q;
    for (int qat=0; qat<q; qat += BS){
        setup();
        RE=1;
        while (!stk.empty())stk.pop();
        REP(i,n) g[i].clear();
        map<pii, bool> gp;
        REP(i,min(BS,q-qat)){
            int a, b; cin>>a>>b; --a; --b;
            E.pb({a,b});
            if (a>b) swap(a,b);
            gp[{a,b}]=1;
        }
        set<pii> now;
        for (auto & ele : hv){
            if (ele.s){
                if (gp.count(ele.f)){
                    now.insert(ele.f);
                }else{
                    g[ele.f.f].pb(ele.f.s);
                    g[ele.f.s].pb(ele.f.f);
                }
            }
        }
        fill(seen,seen+n,0);
        REP(i,n){
            if (!seen[i] ) dfs(i);
        }
        REP(i,min(BS,q-qat)){
            hv[E[qat+i]]^=1;
            if (now.count(E[qat+i])) {
                now.erase(E[qat+i]);
            }else{
                now.insert(E[qat+i]);
            }

            int cnt = 0;
            for (pii ele : now){
                if (RE == 0){
                    break;
                }
                merge(ele.f, ele.s);
                cnt ++;
            }
            bug(qat+i);
            if (RE == 0) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
#ifdef BALBIT
            REP(i,n){
                cout<<find(i).f<<' ';
            }
            cout<<endl;
#endif
            REP(j,cnt) undo();
#ifdef BALBIT
            REP(i,n){
                cout<<find(i).f<<' ';
            }
            cout<<endl;
#endif
        }
    }


}