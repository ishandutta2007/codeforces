#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second

#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()

#define pb push_back

#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<": "<<#__VA_ARGS__<<"- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T && x, S && ...y){cerr<<x<<", "; _do(y...);}
#else
#define endl '\n'
#define bug(...)
#endif // BALBIT


#define IOS() ios::sync_with_stdio(0), cin.tie(0)

//const int maxn = 2e5+5;

const int maxt = 53;
int to[maxt][2];
int fail[maxt];
bool isend[maxt];
vector<int> meto[maxt];
int IT = 1;
ll F[102][maxt][maxt];

void buildac(vector<vector<int> > &vv) {
    memset(to, -1, sizeof to);
    sort(ALL(vv), [&](vector<int> a, vector<int> b){return SZ(a) < SZ(b);});
    vector<int> nok(SZ(vv));
    for (int i = 0; i<SZ(vv); ++i) {
        for (int j = i+1; j<SZ(vv); ++j) {
            for (int k = 0; k + SZ(vv[i]) <= SZ(vv[j]); ++k) {
                bool sm = 1;
                for (int l = 0; l<SZ(vv[i]); ++l) {
                    if (vv[i][l] != vv[j][l+k]) {
                        sm = 0; break;
                    }
                }
                if (sm) {
                    nok[j] = 1; break;
                }
            }
        }
    }
    for (int cnt = 0; cnt <SZ(vv); ++cnt) {
        if (nok[cnt]) continue;
        vector<int> v = vv[cnt];
        int at = 0;
        for (int x : v) {
            int nxt = to[at][x] == -1? IT ++: to[at][x];
            to[at][x] = nxt;
            meto[nxt] = meto[at]; meto[nxt].pb(x);
            if (isend[at]) isend[nxt] = 1;
            at = nxt;
        }
        isend[at] = 1;
    }
//    if (to[0][0] == -1) {
//        to[0][0] = IT++;
//        meto[IT-1] = {0};
//    }
//    if (to[0][1] == -1) {
//        to[0][1] = IT++;
//        meto[IT-1] = {1};
//    }
    for (int i = 1; i<IT; ++i) {
        for (int j = 0; j<IT; ++j) {
            if (SZ(meto[j]) < SZ(meto[i]) && SZ(meto[j]) > SZ(meto[fail[i]])) {
                bool ok = 1;
                for (int k = 1; k<=SZ(meto[j]); ++k) {
                    if (meto[i][SZ(meto[i]) - k] != meto[j][SZ(meto[j]) - k]) {
                        ok = 0; break;
                    }
                }
                if (ok) fail[i] = j;
            }
        }
//            bug(i);
//            for (int x : meto[i]) cout<<x<<' ';
//            bug(fail[i]);
    }
    memset(F, -1, sizeof F);
    for (int i = 0; i<IT; ++i) {
        if (!isend[i]) {
            int tmp = i;
            while (tmp!= 0 && (to[tmp][0]==-1)) tmp = fail[tmp];
//            bug(i, tmp);
            if (~to[tmp][0]) {
                F[0][i][to[tmp][0]] = 1;
                bug(i, to[tmp][0]);
            }else F[0][i][0] = 1;
        }
        if (!isend[i]) {
            int tmp = i;
            while (tmp!= 0 && (to[tmp][1]==-1)) tmp = fail[tmp];
//            bug(i, tmp);
            if (~to[tmp][1]) {
                F[1][i][to[tmp][1]] = 1;
                bug(i, to[tmp][1]);
            }else F[1][i][0] = 1;
        }
    }
}

vector<vector<int> > posg;

inline void W(ll &a, ll b) {
    if (a == -1) a = b;
    else if (b != -1) a = min(a,b);
}

ll dp[102][maxt];// position, node

bool go(int N, vector<int> &v) {
    int n = SZ(v);
    bool chg = 0;
    if (n == 1) {
        for (int st = 0; st<IT; ++st) if (!isend[st])
            for (int en = 0; en < IT; ++en)
                if (!isend[en]){
                    ll tmp = F[N][st][en];
                    W(F[N][st][en], F[v[0]][st][en]);
                    if (F[N][st][en] != tmp) chg = 1;
                }
        return chg;
    }
    for (int st = 0; st < IT; ++ st) if (!isend[st]) {
        for (int i =0 ; i<=n; ++i) {
            for (int j = 0; j<IT; ++j) dp[i][j] = -1;
        }
        dp[0][st] = 0;
        for (int i = 1; i<=n; ++i) {
            for (int nd = 0; nd < IT; ++nd) {
                if (!isend[nd]) {
                    for (int frm = 0; frm < IT; ++frm) {
                        if (!isend[frm] && dp[i-1][frm] != -1 && F[v[i-1]][frm][nd] != -1) {
//                            if (dp[i-1][frm] != -1 && i-1 != 0) {
//                                bug(i-1, dp[i-1][frm]); assert(0);
//                            }
                            if (dp[i-1][frm] <= LLONG_MAX - F[v[i-1]][frm][nd])
                                W(dp[i][nd], dp[i-1][frm] + F[v[i-1]][frm][nd]);
                        }
                    }
                }
            }
        }
        for (int en = 0; en < IT; ++en)
            if (!isend[en]) {
                ll tmp = F[N][st][en];
                W(F[N][st][en], dp[n][en]);
                if (F[N][st][en] != tmp) chg = 1;
            }
    }
    return chg;
}

vector<int> rg[103];

signed main(){
    IOS();
    bug(LLONG_MAX);
    bug((1ull << 63) - 1);
    int G,numg,m; cin>>G>>numg>>m;
//    if (m == 0) assert(0);
    vector<int> aofnum;
    for (int i = 0; i<numg; ++i) {
        int a,k; cin>>a>>k;
        aofnum.pb(a);
        vector<int> hi(k);
        vector<int> seen(102,0);
        for (int j = 0; j<k; ++j) {
            cin>>hi[j];
            if (!seen[hi[j]]) rg[hi[j]].pb(i);
            seen[hi[j]] = 1;
        }
        posg.pb(hi);
    }
    vector<vector<int> > gogo;
    for (int i = 0; i<m; ++i) {
        int k; cin>>k;
        vector<int> tmp(k);
        for (int j=0;j<k;++j) cin>>tmp[j];
        gogo.pb(tmp);
    }
    buildac(gogo);
//    assert(IT <= 30);
    bug(IT);
    queue<int> qq;
    vector<int> inq(G+2,0);
    qq.push(G);
    for (int i = 0; i<numg; ++i) {
        rg[G].pb(i);
    }
    while (!qq.empty()) {
        int x = qq.front(); qq.pop(); inq[x] = 0;
        bug(x);
        for (int u : rg[x]) {
            bug(u, aofnum[u]);
            if (go(aofnum[u], posg[u])) {
                if (!inq[aofnum[u]]) {
                    qq.push(aofnum[u]);
                    inq[aofnum[u]] = 1;
                }
            }
        }
    }
    for (int i = 0; i<numg; ++i) {
        if (go(aofnum[i],posg[i])) {
            assert(0);
        }
    }
    for (int N = 2; N<G; ++N) {
        ll re = -1;
        for (int j = 0; j<IT; ++j) {
            if (!isend[j]) {
                W(re, F[N][0][j]);
            }
        }
        if (re == -1) cout<<"YES"<<endl;
        else cout<<"NO"<<' '<<re<<endl;
//        cout<<re<<endl;
    }
}
/*
3 1 0
2 6 1 0 1 0 0 0
*/