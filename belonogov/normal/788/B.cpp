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
bool use[N];
bool has[N];


void dfs(int v) {
    use[v] = 1;
    for (auto u: e[v])
        if (!use[u])
            dfs(u);
}


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    int st = 0;
    ll loop = 0;
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        has[v] = 1;
        has[u] = 1;
        st = v;
        if (v != u) {
            e[v].pb(u);
            e[u].pb(v);
        }
        else {
            loop++;
        }
    }

    dfs(st);

    for (int i = 0; i < n; i++) {
        if (!use[i] && has[i]) {
            puts("0");
            return 0;
        }
    }
    ll answer = loop * (loop - 1) / 2;
    answer += loop * (m - loop);

    for (int i = 0; i < n; i++) {
        answer += e[i].size() * 1ll * (e[i].size() - 1) / 2;
    }
    
    cout << answer << endl;
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}