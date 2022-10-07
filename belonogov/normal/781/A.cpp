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

#define F first
#define S second
#define mp make_pair
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
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


vector<int> e[N];
int color[N];
int n;

void dfs(int v, int c, int cp) {
    color[v] = c;
    int cur = 0;
    for (auto u: e[v]) {
        if (color[u] == -1) {
            for (; cur == c || cur == cp; cur++);
            dfs(u, cur, c);
            cur++;
        }
    }
}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    memset(color, -1, sizeof color);

    dfs(0, 0, 0);

    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, color[i]);
    printf("%d\n", mx + 1);
    for (int i = 0; i < n; i++)
        printf("%d ", color[i] + 1);
    puts("");

    return 0;
}