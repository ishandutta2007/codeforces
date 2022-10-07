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
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = 2e5 + 10;
const int INF = 1.01e9;
typedef vector<int> vi;

vector<int> e[N];
vector<vector<int>> answer;
int use[N];


int dfs(int v, int p) {
    use[v] = 1;
    vector<int> who;
    for (auto u: e[v]) {
        if (use[u] == 0) {
            if (dfs(u, v)) {
                who.pb(u);
            }
        }
        else if (use[u] == 2) {
            who.pb(u);
        }
    }
    use[v] = 2;
    int res = 1;
    if (p != -1 && who.size() % 2 == 1) {
        who.pb(p);
        res = 0;
    }
    for (int i = 0; i + 1 < sz(who); i += 2) {
        answer.pb({who[i], v, who[i + 1]});
    }

    return res;
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }

    forn(i, n) {
        if (!use[i]) {
            dfs(i, -1);
        }
    }

    

    
    printf("%d\n", sz(answer));
    for (auto x: answer) {
        for (auto y: x) {
            printf("%d ", y + 1);
        }
        puts("");
    }
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}