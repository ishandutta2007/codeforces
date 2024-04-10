#include <bits/stdc++.h>
using namespace std;

#define ll long long

#ifdef BALBIT
#define bug(...) cerr<<"#"<<#__VA_ARGS__<<": ", _do(__VA_ARGS__)
template <typename T> void _do(T&&x) {cerr<<x<<endl;}
template <typename T, typename ...S> void _do(T &&x, S &&...y) {cerr<<x<<", ", _do(y...);}
#else
#define endl '\n'
#define bug(...)
#endif // BALBIT

#define pb push_back
#define pii pair<int, int>
#define f first
#define s second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())

const int maxn = 5002;
const ll mod = 1e9+87;

int n,m;
int val[maxn];

vector<int> pfac[maxn];
map<ll, int> ID;
int NOWID= 0;
ll hval[maxn]; // for each prime number
ll hfac[maxn];

//vector<int> g[10000000];

int nm [5005];

void srt(vector<int> & x) {

    if (x.size() < 800) sort(ALL(x));
    else {
        memset(nm, 0, sizeof nm);
        for (int y :x) nm[y]++;
        int j = 0;

        for(int i = 0; i<5002; ++i) {
            for(int k = 0; k<nm[i]; ++k, ++j) {
                x[j] = i;
            }
        }
    }
}

int wei[maxn*2];
int primeid [maxn];
const int P = 669;
vector<int> primes;
array<int, P> nof[maxn];
int nofsum[maxn*2];
array<int, P> mysig[maxn*2];
bool np[maxn];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void build(){
    for(int i = 0; i<=5000; ++i) {
        hval[i] = rng() % mod;
    }
    for (int i = 2; i<=5000; ++i) {
        if (!np[i]){
            primeid[i] = SZ(primes);
            primes.pb(i);
            for (int j = i+i; j<=5000; j+=i) np[j] = 1;
        }
    }
    assert(P == SZ(primes));
    bug(P);
    for(int i = 1; i<=5000; ++i) {
        int tt = i;
        for (int j = 0; j<P; ++j) {
            while (tt % primes[j] == 0) {
                tt /= primes[j]; nof[i][j] ++;
                hfac[i] += hval[j];
            }
        }
        hfac[i] %= mod;
        if (tt != 1) {
            assert(0);
        }
        hfac[i] += hfac[i-1];
        hfac[i] %= mod;

//        if (i <= 5) {
//            bug(i, hfac[i], hval[0], nof[i][0]);
//        }
    }

}

vector<pii> g[maxn*2];
int inw[maxn];
int par[maxn*2];

void getsum(int i) {
    for (int j = 0; j<P; ++j) {
        nofsum[i] += mysig[i][j];
    }
}

int sz[maxn*2];
int allsz = 0;

ll re = 0;

void dfs1(int v, int p) {
    sz[v] = wei[v];
//    bug(v);
    for (pii & u : g[v]) {
        if (u.f != p) {
            dfs1(u.f, v);
            sz[v] += sz[u.f];
        }
    }
}

int findcen(int v, int p) {
    for (pii & u : g[v]) {
        if (u.f != p && sz[u.f] > allsz/2) {
            return findcen(u.f,v);
        }
    }
    return v;
}

void dfs2(int v, int p, ll d) {
    re += wei[v] * (ll)d;
    if (wei[v]) {
        bug(v,p,d);
    }
    for (pii & u : g[v]) {
        if (u.f != p) {
            dfs2(u.f, v, d+u.s);

        }
    }
}

signed main(){
    build(); //return 0;
    ios::sync_with_stdio(0), cin.tie(0);
//    array<int,2> hi = {{1,2}};
//    array<int, 2> bb = hi;
//    hi[0] = -1;
//    bug(bb[0], bb[1]);
//    return 0;
    cin>>n;
    for (int i = 0; i<n; ++i) {
        int x; cin>>x; inw[max(x,1)]++;
    }
    ID[0] = 0;
    wei[0] = inw[1];
//    fill(ALL(mysig[0]), 0);
    bug(mysig[0][2]);
    array<int,P> nownum;

    fill(ALL(nownum),0);
    bug(nownum[44]);
    int previ = 0; par[0] = 0;
    for (int i = 2; i<= 5000; ++i) {
//        bug(i, hfac[i]);
        ID[hfac[i]] = ++NOWID;
        wei[NOWID] = inw[i];
        int mx = -1, nmx = 0;
        for (int j = 0; j<P; ++j) {
            nownum[j] += nof[i][j];
            if (nof[i][j]) {
                mx = j; nmx = nof[i][j];
            }
        }
//        assert(NOWID != 0);
        mysig[NOWID] = nownum;
        getsum(NOWID);
        array<int, P> lcanum = nownum;
        ll lcah = hfac[i];
        for (int j = 0; nmx != 0; ) {
            --lcanum[j]; lcah -= hval[j];
            if (lcah < 0) lcah += mod;
            if (j == mx) --nmx;
            if (lcanum[j] == 0) {
                ++j;
            }
        }
        int me = NOWID;
//        bug(i,  lcah);
//        bug(lcah, hfac[i]);
//        assert(lcah!=hfac[i]);
        if (!ID.count(lcah)) {
            ID[lcah] = ++NOWID;
            assert(NOWID != 0);
            mysig[NOWID] = lcanum;
            getsum(NOWID);
//            bug(lcah, "HI", i, NOWID, nofsum[NOWID]);
        }
        par[me] = ID[lcah];
        if (par[me] == me+1) {
//            bug("hi");
            int at;
            for ( at = previ; nofsum[par[me]] < nofsum[par[at]]; at = par[at]) {
//                bug (at, par[at],  nofsum[par[at]]);
            }

            if (nofsum[par[me]] == nofsum[par[at]]) par[par[me]] = par[par[at]];
            else par[par[me]] = par[at];

            if (par[me] != at)
                par[at] = par[me];

        }

        previ = me;
//        bug(i);
        if (mysig[0][2] != 0) {
    bug(mysig[0][2]);
    bug(i);
    return 0;

        }
    }
//    for (int i =0 ; i<=6; ++i) {
//        bug(i, par[i], nofsum[i]);
//        ll mul = 1;
//        for (int j = 0; j<P; ++j) {
////            assert(primes[j]!=0);
//            if (mysig[i][j] != 0) {
//                bug(i,j,mysig[i][j]);
//            }
//            for (int k = 0; k<mysig[i][j]; ++k) mul *= primes[j];
////        bug(mul);
//        }
//        bug(mul);
//    }
//    bug(NOWID);
    for(int i = 0; i<=NOWID; ++i) {
        if (par[i] != i) {
            int d = nofsum[i] - nofsum[par[i]];
            g[par[i]].pb({i,d});
            g[i].pb({par[i], d});
        }
    }
//    return 0;
    dfs1(0,0);
    allsz = sz[0];
    bug(allsz); //return 0;
    int c = findcen(0,-1);
    bug(c);
    dfs2(c,-1,0);
    cout<<re<<endl;


}