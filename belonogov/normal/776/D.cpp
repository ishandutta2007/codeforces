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
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int r[N];
vector<int> e[N];
vector<int> g[N];
int color[N];
bool fail;
vector<int> tmp;

void dfs(int v, int cc) {
    assert(cc == 0 || cc == 1);
    assert(color[v] == -1);
    color[v] = cc; 
    tmp.pb(v);
    for (auto u: e[v]) {
        assert(g[u].size() == 2);
        int vv = g[u][0] + g[u][1] - v;
        //db(vv);
        if (color[vv] == -1) {
            dfs(vv, (r[u] + color[v]) % 2);
        }
        else {
            if ((color[v] + color[vv] + r[u]) % 2 != 0)
                fail = 1;
        }
    }
}


int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &r[i]);
    for (int i = 0; i < n; i++)
        r[i] ^= 1;

    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v); v--;
            e[i].pb(v); 
            g[v].pb(i);
        }
    }
    memset(color, -1, sizeof(color));
    for (int i = 0; i < m; i++) {
        if (color[i] == -1) {
            fail = 0;
            tmp.clear();
            dfs(i, 0);
            if (fail) {
                for (auto x: tmp) {
                    color[x] = -1;
                }
                fail = 0;
                dfs(i, 1);
                if (fail) {
                    puts("NO");
                    return 0;
                }
                    
            }
        }        

    }

    puts("YES");
    return 0;
}