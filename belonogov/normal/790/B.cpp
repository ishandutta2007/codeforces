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
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, k;
vector<int> e[N];
ll sz[N];
ll totalLen;
ll cntRem[5];
ll dp[N][5];


void dfs(int v, int p) {
    sz[v] = 1;
    dp[v][0] = 1;
    for (auto u: e[v]) {
        if (u != p) {
            dfs(u, v);
            sz[v] += sz[u];
            totalLen += (n - sz[u]) * 1ll * sz[u];
            for (int i = 0; i < k; i++)
                for (int j = 0; j < k; j++) {
                    cntRem[(i + j + 1) % k] += dp[v][i] * 1ll * dp[u][j];    
                }
            for (int i = 0; i < k; i++) {
                dp[v][(i + 1) % k] += dp[u][i];
            }
        }
    }
}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    dfs(0, -1);
    for (int i = 1; i < k; i++)
       totalLen += (k - i) * cntRem[i]; 


    assert(totalLen % k == 0);
    cout << totalLen / k << endl;

    return 0;
}