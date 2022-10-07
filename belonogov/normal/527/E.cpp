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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const int INF = 1e9;

int n, m;
vector < pair < int, int > > e[N];
int deg[N];
bool use[N];
int useE[N];
pair < int, int > answer[N];


void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(mp(u, i));
        if (v != u)
            e[u].pb(mp(v, i));
        deg[v]++;
        deg[u]++;
    }
}

void dfs(int v) {
    //cerr << "v: " << v << endl;
    use[v] = 1;
    for (auto x: e[v]) {
        if (!use[x.fr])
            dfs(x.fr);
    }
    int cnt = 0;
    //cerr << "v: " << v << endl;
    for (auto x: e[v]) {
        if (useE[x.sc]) {
            //cerr << "id x.sc: " << x.sc << endl;
            if (answer[x.sc].sc == v) {
                //cerr << "sdfsdfsf\n";
                cnt ^= 1;
            }
        }
    }
    //cerr << "v cnt: " << v << " " << cnt << endl;
    for (auto x: e[v]) {
        if (!useE[x.sc]) {
            if (cnt == 0) {
                answer[x.sc] = mp(v, x.fr); 
            }
            else {
                answer[x.sc] = mp(x.fr, v);
                cnt ^= 1;
            }
            useE[x.sc] = 1;
        }
    }
    //cerr << "ex v: " << v << endl;
    //assert(cnt == 0);
}


void solve() {
    vector < int > b;
    for (int i = 0; i < n; i++)
        if (deg[i] % 2 == 1)
            b.pb(i);
    assert(b.size() % 2 == 0);
    for (int i = 0; i < (int)b.size(); i += 2) {
        int v = b[i];
        int u = b[i + 1];
        e[v].pb(mp(u, m));
        e[u].pb(mp(v, m));
        m++;
    }
    if (m % 2 == 1) {
        e[0].pb(mp(0, m));
        //e[0].pb(mp(0, m));
        m++;
    }
    memset(answer, -1, sizeof(answer));
    for (int i = 0; i < n; i++) {
        for (auto x: e[i])
            if (x.fr == i) {
                useE[x.sc] = 1;
                answer[x.sc] = mp(i, i);
            }
    }
    //for (int i = 0; i < m; i++)
        //cerr << useE[i] << "     " << answer[i].fr + 1 << " " << answer[i].sc + 1 << endl;

    dfs(0);

    cout << m << "\n";
    for (int i = 0; i < m; i++)
        cout << answer[i].fr + 1 << " " << answer[i].sc + 1 << "\n";


    vector < int > cnt[2];
    cnt[0].resize(n);
    cnt[1].resize(n);

    for (int i = 0; i < m; i++) {
        cnt[0][answer[i].fr] ^= 1;
        cnt[1][answer[i].sc] ^= 1;
    }
    //cerr << endl;
    for (int i = 0; i < n; i++) {
        //cerr << cnt[0][i] << " " << cnt[1][i] << endl;
        assert(cnt[0][i] == 0 && cnt[1][i] == 0);
    }

    for (int i = 0; i < m; i++)
        assert(useE[i] == 1);
    //cerr << m << endl;
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("test.txt", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}