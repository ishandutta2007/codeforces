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
const int N = 1e6;
const long long INF = 1e9 + 19;

struct Query {
    int type, v, u;
    Query(){ } 
    Query(int type, int v, int u): type(type), v(v), u(u) { }
};

int n, m, q;
vector < Query > b;
bool big[N];
int answer[N];
bool line[N];
vector < int > e[N];

void read() {
    scanf("%d%d%d", &n, &m, &q);
    int o;
    scanf("%d", &o);
    for (int i = 0; i < o; i++) {
        int v;
        scanf("%d", &v); v--;
        b.pb(Query(1, v, -1));
    }
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        b.pb(Query(3, v, u));
    }
    for (int i = 0; i < q; i++) {
        char ch;
        scanf(" %c", &ch);
        int v, u;
        scanf("%d", &v);  v--;
        if (ch == 'O') {
            b.pb(Query(1, v, -1));
        }
        else if (ch == 'F') {
            b.pb(Query(2, v, -1));
        }
        else if (ch == 'C') {
            b.pb(Query(5, v, -1));
        }
        else if (ch == 'A') {
            scanf("%d", &u); u--;
            b.pb(Query(3, v, u));
        }
        else if (ch == 'D') {
            scanf("%d", &u); u--;
            b.pb(Query(4, v, u));
        }
        else
            assert(false);
    }
}

void solve() {
    vector < pair < int, int > > best(n);
    for (int i = 0; i < n; i++)
        best[i] = mp(0, i);

    for (int i = 0; i < (int)b.size(); i++) {
        if (b[i].type == 3) {
            best[b[i].v].fr++;
            best[b[i].u].fr++;
        }
    } 
    sort(best.rbegin(), best.rend());
    int T = sqrt(n); 
    for (int i = 0; i < T; i++)
        big[best[i].sc] = 1;
    
    for (int i = 0; i < (int)b.size(); i++) {
        if (b[i].type == 1) {
            line[b[i].v] = 1;
            for (auto u: e[b[i].v])
                if (big[u])
                    answer[u]++;
        }
        else if (b[i].type == 2) {
            line[b[i].v] = 0;
            for (auto u: e[b[i].v]) 
                if (big[u])
                    answer[u]--;
        }
        else if (b[i].type == 3) {
            int v = b[i].v;
            int u = b[i].u;
            for (int t = 0; t < 2; t++) {
                if (!big[v] || (big[v] && big[u]))
                   e[v].pb(u); 
                if (big[v] && line[u]) {
                    answer[v]++;
                }
                swap(v, u);
            }
        }
        else if (b[i].type == 4) {
            int v = b[i].v;
            int u = b[i].u;
            for (int t = 0; t < 2; t++) {
                if (!big[v] || (big[v] && big[u])) {
                    bool flag = 0;
                    for (int j = 0; j < (int)e[v].size(); j++)
                        if (e[v][j] == u) {
                            e[v].erase(e[v].begin() + j);
                            flag = 1;
                            break;
                        }
                    assert(flag);
                }
                if (big[v] && line[u]) {
                    answer[v]--;
                }
                swap(v, u);
            }
        }
        else if (b[i].type == 5) {
            int v = b[i].v;
            int res;
            //assert(line[v] == 1);
            if (big[v]) 
                res = answer[v];
            else {
                res = 0;
                for (auto u: e[v])
                    res += line[u];
            }
            printf("%d\n", res);
        }
        else
            assert(false);
    }
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