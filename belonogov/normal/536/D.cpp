#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 2222;
const long long INF = 1e9 + 19;
typedef long long ll;
const ll INF18 = 1e18;
typedef vector<int> vi;
typedef pair<int,int> pi;


int n, m;
int st, fn;
int p[N];
ll val[N][N];
int cnt[N][N];
ll pref[N][N];
int prefCnt[N][N];
ll dp[2][N][N];
ll bestMove[2][N];
int bestCur[2][N];
vector<pair<int,int>> e[N];


void dijkstra(int bg, vector<ll>& dist) {
    dist.assign(n, INF18);
    dist[bg] = 0;
    set<pair<ll,int>> q;
    q.insert({0, bg});
    while (!q.empty()) {
        int v = q.begin()->S;
        q.erase(q.begin());
        for (auto x: e[v]) {
            if (dist[x.F] > dist[v] + x.S) {
                q.erase({dist[x.F], x.F});
                dist[x.F] = dist[v] + x.S;
                q.insert({dist[x.F], x.F});
            }
        }
    }
}

ll getCnt(int x1, int y1, int x2, int y2) {
    return prefCnt[x2][y2] - prefCnt[x1][y2] - prefCnt[x2][y1] + prefCnt[x1][y1];
}

ll getSum(int x1, int y1, int x2, int y2) {
    return pref[x2][y2] - pref[x1][y2] - pref[x2][y1] + pref[x1][y1];
}

void read() {
    scanf("%d%d", &n, &m);
    scanf("%d%d", &st, &fn); st--; fn--;
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w); v--; u--;
        e[v].pb({u, w});
        e[u].pb({v, w});
    }
}


ll solve() {

    vector<ll> dst, dfn;
    dijkstra(st, dst);
    dijkstra(fn, dfn);
    vector<ll> xst = dst;
    vector<ll> xfn = dfn;
    //xst.pb(-1);
    //xfn.pb(-1);
    sort(all(xst));
    sort(all(xfn));
    for (auto& x: dst) x = lower_bound(all(xst), x) - xst.begin();
    for (auto& x: dfn) x = lower_bound(all(xfn), x) - xfn.begin();
    //for (int i = 0; i < n; i++) {
        //db3(dst[i], dfn[i], p[i]);
    //}


    memset(val, 0, sizeof val);
    memset(cnt, 0, sizeof cnt);
    memset(pref, 0, sizeof pref);
    for (int i = 0; i < n; i++) {
        val[dst[i]][dfn[i]] += p[i];
        cnt[dst[i]][dfn[i]]++;
    }


    //cerr << "val:" << endl;
    //for (int i = 0; i <= (int)dst.size(); i++, cerr << endl)
        //for (int j = 0; j <= (int)dfn.size(); j++) {
            //cerr << val[i][j] << " ";
        //}
    //cerr << "pref:" << endl;

    for (int i = 0; i < (int)dst.size(); i++)
        for (int j = 0; j < (int)dfn.size(); j++) {
            pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + val[i][j];
            prefCnt[i + 1][j + 1] = prefCnt[i + 1][j] + prefCnt[i][j + 1] - prefCnt[i][j] + cnt[i][j];
        }

    //for (int i = 0; i <= (int)dst.size(); i++, cerr << endl)
        //for (int j = 0; j <= (int)dfn.size(); j++) {
            //cerr << pref[i][j] << " ";

        //}

    for (int i = 0; i <= (int)dst.size(); i++) {
        bestMove[1][i] = INF18;
        bestCur[1][i] = dfn.size();
    }

    for (int i = 0; i <= (int)dfn.size(); i++) {
        bestMove[0][i] = -INF18;
        bestCur[0][i] = dst.size();
    }


    if (0) {
        for (int i = (int)dst.size(); i >= 0; i--) {
            for (int j = (int)dfn.size(); j >= 0; j--) {
                bool flag = 0;
                dp[0][i][j] = -INF18;
                for (int t = i + 1; t <= (int)dst.size(); t++) {
                    if (getCnt(i, j, t, dfn.size()) > 0) {
                        dp[0][i][j] = max(dp[0][i][j], dp[1][t][j] + getSum(i, j, t, dfn.size()));
                        flag = 1;
                    }
                }
                if (!flag)
                    dp[0][i][j] = 0;

                    ///dp[0][i][j] = bestMove[0][j] - (pref[i][dfn.size()] - pref[i][j]);
                /// max
                //bestMove[1][i] = min(bestMove[1][i], dp[0][i][j] + (pref[dst.size()][j] - pref[i][j]));


                //if (j == (int)dfn.size()) {
                    //dp[1][i][j] = 0;
                //}
                //else {
                flag = 0;
                dp[1][i][j] = INF18;
                for (int t = j + 1; t <= (int)dfn.size(); t++) {
                    if (getCnt(i, j, dst.size(), t) > 0) {
                        dp[1][i][j] = min(dp[1][i][j], dp[0][i][t] - getSum(i, j, dst.size(), t));
                        flag = 1;
                    }
                }
                if (!flag)
                    dp[1][i][j] = 0;
            }
        }
        //db(dp[1][1][0]);
        //db(dp[1][2][0]);
        //db(dp[0][2][1]);
    }
    else {
        //db(dst.size());
        for (int i = (int)dst.size(); i >= 0; i--) {
            for (int j = (int)dfn.size(); j >= 0; j--) {
                //if (i == (int)dst.size()) {
                    //dp[0][i][j] = 0;
                //}
                //else {

                //db(getSum(i, j, bestCur[0][j], dfn.size()));

                for (; bestCur[0][j] > 0 && getCnt(i, j, bestCur[0][j], dfn.size()) > 0; bestCur[0][j]--) {
                    int pos = bestCur[0][j];
                    bestMove[0][j] = max(bestMove[0][j], dp[1][pos][j] + pref[pos][dfn.size()] - pref[pos][j]);
                }

                if (bestCur[0][j] < (int)dst.size())
                    dp[0][i][j] = bestMove[0][j] - (pref[i][dfn.size()] - pref[i][j]);
                else 
                    dp[0][i][j] = 0;


                //}
                /// max
                //if (i == 1 &&  j == 2) {
                    //db(bestMove[1][i]);
                    //db(dp[0][i][j]);
                    //db((pref[dst.size()][j] - pref[i][j]));
                //}
              
                //if (j == (int)dfn.size()) {
                    //dp[1][i][j] = 0;
                //}
                //else {

                for (; bestCur[1][i] > 0 && getCnt(i, j, dst.size(), bestCur[1][i]) > 0; bestCur[1][i]--) {
                    int pos = bestCur[1][i];
                    bestMove[1][i] = min(bestMove[1][i], dp[0][i][pos] - (pref[dst.size()][pos] - pref[i][pos]));
                }

                if (bestCur[1][i] < (int)dfn.size()) {
                    dp[1][i][j] = bestMove[1][i] + (pref[dst.size()][j] - pref[i][j]);
                }
                else {
                    dp[1][i][j] = 0;
                }

                    //if (i == 1 && j == 0) {
                        //db(bestMove[1][i]);
                        //db(pref[dst.size()][j] - pref[i][j]);
                    //}
                //}
                //bestMove[1][i] = min(bestMove[1][i], dp[0][i][j] - (pref[dst.size()][j] - pref[i][j]));
                //if (i == 1 &&  j == 1) {
                    //db(dp[0][1][1]);
                    //db(bestMove[1][i]);
                //}
                //bestMove[0][j] = max(bestMove[0][j], dp[1][i][j] + pref[i][dfn.size()] - pref[i][j]);
            
                //for (int tt = 0; tt < 2; tt++) {
                    
                //} 
            }
        }
        //db(dp[0][1][1]);
        //db(dp[1][1][0]);
    }
    //for (int t = 0; t < 2; t++, cerr << endl)
        //for (int i = 0; i < n; i++)
            //cerr << bestCur[t][i] << " ";

    //cerr << "dp: " << endl;
    //for (int tt = 0; tt < 2; tt++, cerr << endl)
        //for (int i = 0; i <= (int)dst.size(); i++, cerr << endl)
            //for (int j = 0; j <= (int)dfn.size(); j++)
                //cerr << dp[tt][i][j] << " ";
    //db(dp[1][2][0]);

    ll g = dp[0][0][0];
    //db(g);


    return g;
}

vector<int> ford(int bg) {
    queue<int> q; 
    vector<int> dist(n, INF);
    dist[bg] = 0;
    q.push(bg);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto x: e[v])
            if (dist[x.F] > dist[v] + x.S) {
                dist[x.F] = dist[v] + x.S;
                q.push(x.F);
            }
    }
    return dist;
}


ll rec(int turn, vector<int> used) {
    bool allUsed = 1;
    for (auto x: used)
        allUsed &= x == 1;
    if (allUsed) return 0;
    vector<int> dist = ford(turn == 0? st: fn); 
    ll answer = (turn == 0)? -INF18: INF18;
    for (int i = 0; i < n; i++) {       
        if (!used[i]) {
            vector<int> nused = used;
            ll cost = 0;
            for (int j = 0; j < n; j++) {
                if (!used[j] && dist[j] <= dist[i]) {
                    nused[j] = 1;
                    cost += p[j];
                }
            }
            //db(cost);
            if (turn == 0)
                answer = max(answer, rec(turn ^ 1, nused) + cost);
            else 
                answer = min(answer, rec(turn ^ 1, nused) - cost);
        }
    }

    //db(answer);
    return answer;
}

ll slow() {
    vector<int> used(n, 0);
    auto tmp = rec(0, used);
    //db(tmp);
    return tmp;
}

void genTest() {
    n = rand() % 5 + 1;
    st = rand() % n;
    fn = rand() % n;
    if (st == fn)
        st = (st + 1) % n;
    m = n - 1 + rand() % 3;
    int T = 10;
    for (int i = 0; i < n; i++)
        p[i] = rand() % T - T / 2;

    for (int i = 0; i < n; i++)
        e[i].clear();


    for (int i = 1; i < n; i++) {
        int v = rand() % i; 
        int w = rand() % T;
        e[i].pb({v, w});
        e[v].pb({i, w});
    }
    for (int i = n - 1; i < m; i++) {
        int v, u, w;
        v = rand() % n;
        u = rand() % n;
        w = rand() % T;
        e[v].pb({u, w});
        e[u].pb({v, w});
    }
}

void printTest() {
    cout << n << " " << m << endl;
    cout << st + 1 << " " << fn + 1 << endl;
    for (int i = 0; i < n; i++)
        cerr << p[i] << " ";
    cerr << endl;
    for (int v = 0; v < n; v++)
        for (auto x: e[v]) {
            if (x.F <= v) {
                cout << x.F + 1 << " " << v + 1 << " " << x.S << endl;
            }
        }
}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();
        db2(n, m);
        //printTest();
        auto r1 = solve();
        auto r2 = slow();
        db2(r1, r2);
        assert(r1 == r2);
    }
}

void printAns(ll g) {
    if (g == 0) {
        puts("Flowers");
    }
    if (g < 0) {
        puts("Cry");
    }
    if (g > 0) {
        puts("Break a heart");
    }
}

int main(){
#define TASK "D"
#ifdef HOME 
    assert(freopen(TASK".in", "r", stdin));
    //assert(freopen(TASK".out", "w", stdout));
#endif
    if (1) {
        read();
        auto r1 = solve();
        //auto r2 = slow();
        //db2(r1, r2);
        printAns(r1);
    }
    else {
        stress();
    }
        
    
    //db("QQ");
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}