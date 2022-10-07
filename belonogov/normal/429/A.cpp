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

vector < int > e[N];
bool use[N];
int a[N];
int b[N];
int n;
vector < int > answer;

void dfs(int v, int h, vector < int > rev) {
    use[v] = 1;
    a[v] ^= rev[h & 1];
    if (a[v] != b[v]) {
        a[v] = b[v];
        rev[h & 1] ^= 1;
        answer.pb(v);
    }
    for (auto u: e[v]) 
        if (!use[u])
            dfs(u, h + 1, rev);

}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

}

void solve() {
    dfs(0, 0, vector < int > (2, 0));
    printf("%d\n", (int)answer.size());
    for (auto x: answer)
        printf("%d\n", x + 1);
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