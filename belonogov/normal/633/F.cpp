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

struct MX {
    vector < pair < long long, int > > g;
    MX(int sz) {
        g.assign(sz, mp(0, -1));
    }
    void add(long long x, int id) {
        if (g.back().fr < x) {
            g[g.size() - 1] = mp(x, id);
            for (int i = g.size() - 2; i >= 0; i--)
                if (g[i] < g[i + 1])
                    swap(g[i], g[i + 1]);
        }
    }
};

int n;
int a[N];
vector < int > e[N];
bool use[N];
long long f1[N];
long long f2[N];
long long f3[N];
long long answer;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
}

void dfs(int v) {
    use[v] = 1;
    MX m1(3);
    MX m2(3);
    MX m3(3);
    f1[v] = a[v];
    f2[v] = a[v];
    f3[v] = a[v];
    for (auto u: e[v]) {
        if (!use[u]) {
            dfs(u);
            f1[v] = max(f1[v], f1[u] + a[v]);
            f3[v] = max(f3[v], f3[u]);

            f2[v] = max(f2[v], f2[u] + a[v]);

            m1.add(f1[u], u);
            m2.add(f2[u], u);
            m3.add(f3[u], u);
        }
    }
    long long ans1 = a[v] + m1.g[0].fr + m1.g[1].fr;
    long long ans2 = m3.g[0].fr + m3.g[1].fr;


    for (int i = 0; i < (int)m3.g.size(); i++) {
        long long sum = m3.g[i].fr + a[v];
        int need = 2;
        for (int j = 0; need > 0 && j < (int)m1.g.size(); j++) {
            if (m1.g[j].sc != m3.g[i].sc) {
                sum += m1.g[j].fr;
                need--;
            }
        }
        ans2 = max(ans2, sum);
    }

    for (int i = 0; i < (int)m2.g.size(); i++) {
        long long sum = m2.g[i].fr + a[v];
        for (int j = 0; j < (int)m1.g.size(); j++)
            if (m2.g[i].sc != m1.g[j].sc) {
                sum += m1.g[j].fr;
                break;
            }
        ans2 = max(ans2, sum);
    }

    for (int i = 0; i < (int)m1.g.size(); i++) {
        long long sum = m1.g[i].fr + a[v];
        for (int j = 0; j < (int)m3.g.size(); j++)
            if (m1.g[i].sc != m3.g[j].sc) {
                sum += m3.g[j].fr;
                break;
            }
        f2[v] = max(sum, f2[v]);
    }

    answer = max(ans2, answer);
    answer = max(ans1, answer);

    f3[v] = max(ans1, f3[v]);
    f2[v] = max(f2[v], f3[v]);
}

long long solve() {
    for (int i = 0; i < n; i++)
        use[i] = 0;
    answer = 0;
    for (int i = 0; i < n; i++) {
        f1[i] = f2[i] = f3[i] = 0;
    }
    
    dfs(0);
    //for (int i = 0; i < n; i++) {
        //cerr << i << ": " << f1[i] << " " << f2[i] << " " << f3[i] << endl;
    //}


    return answer;
}

void genTest() {
    n = 10;
    int T = 100;
    for (int i = 0; i < n; i++)
        a[i] = rand() % T + 1;
    for (int i = 0; i < n; i++)
        e[i].clear();
    for (int i = 1; i < n; i++) {
        int v = rand() % i;
        e[v].pb(i);
        e[i].pb(v);
    }
}

vector < int > getPath(int st, int fn) {
    queue < int > q;
    vector < int > dist(n, INF);
    vector < int > p(n);
    q.push(st);
    dist[st] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u: e[v]) {
            if (dist[u] > dist[v] + 1) {
                dist[u] = dist[v] + 1;
                p[u] = v;
                q.push(u);
            }
        }
    }
    vector < int > path;
    int v = fn;
    for (; v != st; ) {
        path.pb(v);
        v = p[v];
    }
    path.pb(st);
    return path;
}

long long stupid() {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int v = 0; v < n; v++)
                for (int u = v; u < n; u++) {
                    auto p1 = getPath(i, j);
                    auto p2 = getPath(v, u);
                    vector < int > use(n, 0);
                    for (auto x: p1)
                        use[x] = 1;
                    bool flag = 1;
                    for (auto y: p2) {
                        flag &= !use[y];
                        use[y] = 1;
                    }
                    if (!flag) continue;
                    int sum = 0;
                    for (int i = 0; i < n; i++)
                        sum += use[i] * a[i];
                    answer = max(answer, sum);
                }
        }
    }
    return answer;
}

void printTest() {
    cerr << n << endl;
    for (int i = 0; i < n; i++)
        cerr << a[i] << " ";
    cerr << endl;
    for (int i = 0; i < n; i++)
        for (auto u: e[i])
            if (i < u)
                cerr << i + 1 << " " << u + 1 << endl;
}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();
        long long r1 = solve();
        long long r2 = stupid();
        db2(r1, r2);
        if (r1 != r2) {
            printTest();
        }
        assert(r1 == r2);
    }

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
            printf("%lld\n", solve());
        }
    }
    else {
        stress();
    }

    return 0;
}