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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;

int n, m;
vector < pair < int, int > > edge;
vector < int > e[N];
bool use[N];
vector < int > st;

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        edge.pb(mp(v, u));
    }
}

void dfs(int v) {
    use[v] = 1;
    for (auto u: e[v])
        if (!use[u])
            dfs(u);
    st.pb(v);
}

bool check(int k) {
    for (int i = 0; i < n; i++)
       e[i].clear(); 
    for (int i = 0; i < k; i++)
        e[edge[i].fr].pb(edge[i].sc);

    memset(use, 0, sizeof(use));
    
    st.clear();
    for (int i = 0; i < n; i++)
        if (!use[i])
            dfs(i);
    reverse(st.begin(), st.end());
    //for (auto x: st)
        //cerr << x + 1 << " ";
    //cerr << endl;

    for (int i = 0; i < n - 1; i++) {
        int v = st[i];
        int u = st[i + 1];
        bool flag = 0;
        for (auto y: e[v])
            if (y == u)
                flag = 1;
        if (!flag)
            return 0;
    }
    return 1;
}

void solve() {
    if (!check(m)) {
        puts("-1");
        return;
    }
    int l = 0;
    int r = m;
    while (r - l > 1) {
        if (check((l + r) / 2))
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    printf("%d\n", r);
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}