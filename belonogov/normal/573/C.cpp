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
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const int INF = 1e9 + 19;

int n;
vector < int > e[N];
int type[N];
int cnt[N][4];
bool use[N];
bool fail;


void dfs(int v) {
    use[v] = 1;
    for (auto u: e[v]) {
        if (!use[u]) {
            dfs(u);
            cnt[v][type[u]]++;
        }
    }
    int mx = 0;
    for (int i = 0; i < 4; i++)
        if (cnt[v][i] > 0)
            mx = i;
    if (mx <= 0 && cnt[v][0] <= 1)  {
        type[v] = 0;
        return;
    }
    if (mx <= 0 && cnt[v][0] == 2) {
        type[v] = 1;
        return;
    }
    if (mx <= 2 && cnt[v][2] <= 1) {
        type[v] = 2;
        return;
    }
    if (mx <= 2 && cnt[v][2] == 2) {
        type[v] = 3;
        return;
    }
   /* if (mx <= 3 && cnt[v][3] == 1) {
        if (cnt[v][2] == 0 && cnt[v][1] == 0 && cnt[v][0] <= 2)  {
            type[v] == 
        }
        

    }*/
    fail = 1;

}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
}

void clear() {
    fail = 0;
    for (int i = 0; i < n; i++) {
        use[i] = 0;
        type[i] = 0;
        for (int j = 0; j < 4; j++)
            cnt[i][j] = 0;
    }

}

int solve(int st = 0) {
    clear();
    dfs(st);
    if (fail) {
        for (int i = 0; i < n; i++)
            if (type[i] == 3) {
                clear();
                dfs(i);
                break;
            }
    }
    //for (int i = 0; i < n; i++) {
        //db2(i + 1, type[i]);
    //}
    return !fail;
}

void printAns(int x) {
    if (x)
        puts("Yes");
    else
        puts("No");
}

void genTest() {
    n = 40;
    for (int i = 0; i < n; i++)
        e[i].clear();
    for (int i = 1; i < n; i++) {
        int v = rand() % i;
        e[v].pb(i);
        e[i].pb(v);
    }
}

void printTest() {
    cout << n << endl;
    for (int i = 0; i < n; i++)
        for (auto u: e[i])
            if (u < i)
                cout << u + 1 << " " << i + 1 << endl;
}

void stress() {
    for (int t = 0; ; t++) {
        cerr << "test id: " << t << endl;
        genTest();
        vector < int > res;
        for (int i = 0; i < n; i++) 
            res.pb(solve(i));
        for (int i = 0; i < n; i++) {
            if (res[i] != res[0]) {
                db2(res[i], res[0]);
                db(i);
                printTest();
            }
            assert(res[i] == res[0]);
        }
        db(res[0]);
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
            printAns(solve(0));
        }
    }
    else {
        stress();
    }

    return 0;
}