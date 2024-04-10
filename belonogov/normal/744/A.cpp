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
const int N = 1e6;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


int n, m, k;
int c[N];
vector<int> e[N];
bool use[N];
ll cnt;

void read() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &c[i]);
        c[i]--;
    }
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u);  v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
}

void dfs(int v) {
    cnt++;
    use[v] = 1;
    for (auto u: e[v])
        if (!use[u])
            dfs(u);
}

void solve() {
    ll total = 0;
    ll rem = n;
    ll mx = 0;
    for (int i = 0; i < k; i++) {
        cnt = 0;
        dfs(c[i]);
        rem -= cnt;
        mx = max(mx, cnt);
        total += cnt * 1ll * (cnt - 1) / 2;
    }
    assert(rem >= 0);
    total -= mx * (mx - 1) / 2;
    mx += rem;
    total += mx * (mx - 1) / 2;

    cout << total - m << endl;
}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}