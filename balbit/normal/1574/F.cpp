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
const ll mod = 998244353;


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

const int maxn = 3e5+5;

bool dead[maxn];
bool strdead[maxn];
int grp[maxn];

int par[maxn];
int find(int x){return x == par[x]? x : par[x] = find(par[x]);}
void mrg(int a, int b){a = find(a); b = find(b); par[a] = b;}

vector<int> whohas[maxn];
vector<int> strgroup[maxn];

bool mentioned[maxn];
bool stepdone[maxn];

ll dp[maxn];

signed main(){
    IOS();
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int> > vs;
    REP(i,n) par[i] = i;
    map<int, int> frens;

    REP(i,n) {
        int t; cin>>t;
        vector<int> go(t);
        bool bye = 0;
        REP(j,t) {
            cin>>go[j];
            mentioned[go[j]] = 1;
            if (!whohas[go[j]].empty() && whohas[go[j]].back() == i) {
                bye = 1;
//                break;
            }
            if (!bye)
            whohas[go[j]].pb(i);
        }
        strdead[i] = bye;
        if (bye) {
            for (int m : go) dead[m] = 1;
        }
        vs.pb(go);
    }



    REP1(i,k) {
        if (!mentioned[i]) ++frens[1];
        for (int y : whohas[i]) {
            mrg(y, whohas[i][0]);
        }
    }



    REP(i,n) {
        strgroup[find(i)].pb(i);
    }


    REP(i,n) {
        if (SZ(strgroup[i])) {
            vector<int> ss = strgroup[i];
            bug(i, SZ(ss));
            for (int t : ss) bug(t);

            map<int, int> relpos;
            queue<int> q;
            relpos[vs[ss[0]][0]] = 0;

            for (int j : whohas[vs[ss[0]][0]]) {
                if (!stepdone[j]) {
                    q.push(j);
                    bug("q push ",j);
                    stepdone[j] = 1;
                }
            }

            bool groupdead = 0;

            for (int j : ss) {
                if (strdead[j]) {
                    groupdead = 1;
                }
            }

            if (!groupdead) while (!q.empty()) {
                int at = q.front(); q.pop();
                int anc = -1, ancval = -1;
                REP(j, SZ(vs[at])) {
                    if (relpos.count(vs[at][j])) {
                        anc = j;
                        ancval = relpos[vs[at][j]];
                    }
                }
                assert(anc != -1);
                REP(j, SZ(vs[at])) {
                    int ele = vs[at][j];
                    if (!relpos.count(ele)) {
                        relpos[ele] = j - anc + ancval;
                        for (int hey : whohas[ele]) {
                            if (!stepdone[hey]) {
                                q.push(hey);
                                stepdone[hey] = 1;
                            }
                        }
                    }else{
                        if (relpos[ele] != j-anc+ancval) {
                            groupdead = 1;
                            break;
                        }
                    }
                }
                if (groupdead) break;
            }

            unordered_set<int> yo;
            for (pii p : relpos) {
                if (yo.count(p.s)) {
                    groupdead = 1; break;
                }
                yo.insert(p.s);
            }

            if (groupdead) {
                for (int j : ss) strdead[j] = 1;
                for (int j : ss) for (int e : vs[j]) dead[e] = 1;
                bug("Dead!");
            }else{
                bug(SZ(relpos));
                frens[SZ(relpos)]++;
            }
        }
    }
//    sort(ALL(go), [&](vector<int> a, vector<int> b){return SZ(a) > SZ(b);});

    vector<pair<int, ll> > trans;
    for (pii p : frens) {
        bug(p.f, p.s);
        trans.pb(p);
    }

    dp[0] = 1;
    for (int i = 1; i<=m; ++i) {
        for (pii p : trans) {
            if (i >= p.f) dp[i] += dp[i-p.f] * p.s % mod;
        }
        dp[i] %= mod;
    }
    cout<<dp[m]<<endl;


}