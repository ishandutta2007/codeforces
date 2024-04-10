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

vector<int> g[maxn];
string sat[maxn];
string s = "";
int f[400005];
int ansfor[maxn][26];
ll re = 0;
int ORG;

void dfs(int v, int par) {
    int n = sat[v].length();
    int start = 0;
    if (par!=-100 && ansfor[par][sat[v][0]-'a']!=-100) {
        bug("Used Trick!");
        s += sat[v][0];
        f[s.length()-1] = ansfor[par][sat[v][0]-'a'];
        if (f[s.length()-1] == ORG-1) re++;
        start = 1;
    }
    FOR(i,start, n ){
        s += sat[v][i];
        int j = s.length()-1;
        f[j] = f[j-1];
        while (f[j]!=-1 && s[f[j]+1]!=s[j]) {
            f[j] = f[f[j]];
        }
        if (s[f[j]+1] == s[j]) f[j]++;
        if (i==0) ansfor[par][s.back()-'a'] = f[j];
        if (f[j] == ORG-1) re++;
    }

    bug(v,s);
    for (int u : g[v]) {
        dfs(u, v);
    }
    REP(i,n) s.pop_back();
}

signed main(){
    IOS();
    int n; cin>>n;
    REP1(i,n-1) {
        int p; cin>>p; --p;
        g[p].pb(i);
        cin>>sat[i];
    }
    cin>>s; ORG = s.length(); s+="#";
    f[0] = -1;
    REP1(i, s.length()-1) {
        f[i] = f[i-1];
        while (f[i]!=-1 && s[f[i]+1]!=s[i]) f[i] = f[f[i]];
        if (s[f[i]+1]==s[i]) f[i]++;
        bug(i,f[i]);
    }
    REP(i,maxn) REP(j,26) ansfor[i][j] = -100;
    dfs(0,-100);
    cout<<re<<endl;
}