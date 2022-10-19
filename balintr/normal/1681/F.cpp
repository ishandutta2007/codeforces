#include <bits/stdc++.h>
using namespace std;

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0)
#define ms(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x) {cerr << #x << ' ' << x << endl;}
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << arr[_i]; cerr << endl;}

#ifdef WIN32
const int MN = 105;
#else
const int MN = 5e5 + 5;
#endif
int n;
vpii adjList[MN];
int stSz[MN];
set<pii> sts[MN];
int downVal[MN], upVal[MN];

int proc(set<pii> &st, int sz, int c){
    auto iter = st.lower_bound(pii{c, -1});
    auto iterCpy = iter;
    while(iter != st.end() && iter->fs == c){
        sz -= stSz[iter->sn];
        ++iter;
    }
    iter = iterCpy;
    while(iter != st.end() && iter->fs == c){
        upVal[iter->sn] = sz;
        iter = st.erase(iter);
    }
    return sz;
}

void dfs(int n1, int par, int c1){
    stSz[n1] = 1;
    pii mx = {-1, -1};

    for(auto [n2, c2] : adjList[n1]){
        if(n2 == par) continue;
        dfs(n2, n1, c2);
        stSz[n1] += stSz[n2];
        mx = max(mx, pii{SZ(sts[n2]), n2});
    }

    downVal[n1] = stSz[n1];
    if(mx.sn == -1){
        sts[n1].insert({c1, n1});
        return;
    }

    sts[n1] = move(sts[mx.sn]);
    for(auto [n2, c2] : adjList[n1]){
        if(n2 == par || n2 == mx.sn) continue;
        for(pii p : sts[n2]) sts[n1].insert(p);
        sts[n2].clear();
    }

    if(par == -1){
        while(!sts[n1].empty()) proc(sts[n1], stSz[n1], sts[n1].begin()->fs);
    }
    else {
        downVal[n1] = proc(sts[n1], stSz[n1], c1);
        sts[n1].insert({c1, n1});
    }
}

int main(){
    boost();
    cin >> n;
    FR(i, n-1){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;
        adjList[a].pb({b, c});
        adjList[b].pb({a, c});
    }
    dfs(0, -1, -1);

    ll ans = 0;
    FOR(i, 1, n) ans += (ll) upVal[i] * downVal[i];
    cout << ans << '\n';
}