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
const int N = 3e5 + 10;
const long long INF = 1e9 + 19;
const int ALF = 26;

int n;
int c[N];
int cnt[N];
char s[N];
int id[N];
vector < int > e[N];
int go[N][ALF];
bool use[N];


void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    scanf("%s", s);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
}

bool cmpCh(int v, int u)  {
    return id[v] < id[u];
}
void reCalcCnt(int v) {
    cnt[v] = 1;
    for (int i = 0; i < ALF; i++)
        cnt[v] += (go[v][i] == -1)? 0 : cnt[go[v][i]];
}

void merge(int v, int u) {
    for (int i = 0; i < ALF; i++) {
        if (go[u][i] != -1) {
            if (go[v][i] == -1) {
                go[v][i] = go[u][i];
            }
            else
                merge(go[v][i], go[u][i]);
        }
    }  
    reCalcCnt(v);
}

void dfs(int v) {
    use[v] = 1;
    for (int i = 0; i < (int)e[v].size(); i++) {
        int u = e[v][i];
        if (!use[u]) {
            dfs(u);
        }
        else {
            e[v].erase(e[v].begin() + i);
            i--;
        }
    }
    

    sort(e[v].begin(), e[v].end(), cmpCh); 
    for (int i = 0; i < (int)e[v].size();) {
        int j = i;
        i++;
        go[v][ id[e[v][j]] ] = e[v][j];
        for (; i < (int)e[v].size() && id[e[v][j]] == id[e[v][i]]; i++) {
            merge(e[v][j], e[v][i]); 
        }
    } 
    reCalcCnt(v);
    c[v] += cnt[v];
}

pair < int, int > solve() {
    for (int i = 0; i < n; i++)
        use[i] = 0;
    for (int i = 0; i < n; i++)
        id[i] = s[i] - 'a';
    memset(go, -1, sizeof(go));
    dfs(0);
    int mx = -1;
    int answer = 0;
    //for (int i = 0; i < n; i++)
        //cerr << cnt[i] << " ";
    //cerr << endl;
    //for (int i = 0; i < n; i++)
        //cerr << id[i] << " ";
    //cerr << endl;
    //for (int i = 0; i < n; i++, cerr << endl)
        //for (int j = 0; j < 3; j++)
            //cerr << go[i][j] << " ";


    for (int i = 0; i < n; i++) {
        if (mx < c[i]) {
            mx = c[i];
            answer = 0;
        }
        if (mx == c[i])
            answer++;
    }
    //for (int i = 0; i < n; i++)
        //cerr << cnt[i] << " ";
    //cerr << endl;

    return mp(mx, answer);
    //printf("%d\n%d\n", mx, answer);
}

void printAns(pair < int, int > x) {
    printf("%d\n%d\n", x.fr, x.sc);
}


void genTest() {
    n = rand() % 20 + 1;
    for (int i = 0; i < n; i++)
        e[i].clear();
    int T = 10;
    int G = 5;
    for (int i = 0; i < n; i++) {
        c[i] = rand() % T;
        s[i] = rand() % G + 'a';
    }
    for (int i = 1; i < n; i++) {
        int v = rand() % i;
        e[v].pb(i);
        e[i].pb(v);
    }
}

int p[N];
void dfs2(int v) {
    use[v] = 1;
    for (auto u: e[v])
        if (!use[u]) {
            p[u] = v;
            dfs2(u);
        }
}
set < string > q;

void dfs3(int v, string s) {
    s += char('a' + id[v]);
    q.insert(s);
    for (auto u: e[v]) {
        if (u != p[v])
            dfs3(u, s);
    }
}

pair < int, int > stupid() {
    for (int i = 0; i < n; i++)
        id[i] = s[i] - 'a';
    map < int, int > val;
    for (int i = 0; i < n; i++)
        use[i] = 0;
    dfs2(0);

    for (int v = 0; v < n; v++) {
        for (int i = 0; i < n; i++)
            use[i] = 0;
        q.clear();
        dfs3(v, "");
        //db2(q.size(), c[v]);
        //for (auto s: q)
            //cerr << s << " ";
        //cerr << endl;
        val[q.size() + c[v]]++;
    }
    return *val.rbegin();
}

void printTest() {
    cerr << n << endl;
    for (int i = 0; i < n; i++)
        cerr << c[i] << " ";
    cerr << endl;
    for (int i = 0; i < n; i++)
        cerr << s[i];
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
        auto r2 = stupid();
        auto r1 = solve();
        if (r1.sc > 1) {
            db2(r1.fr, r1.sc);
            db2(r2.fr, r2.sc);
        }

        //printTest();
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
            printAns(solve());
            //printAns(stupid());
        }
    }
    else {
        stress();
    }

    return 0;
}