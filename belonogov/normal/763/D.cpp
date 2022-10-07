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

vector<int> e[N];
bool use[N];
int sz[N];
int type[N];
int n;
int cur;
map<vector<int>, int> q;
vector<int> cnt;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
}

void dfs0(int v) {
    use[v] = 1;
    sz[v] = 1;
    for (auto u: e[v])
        if (!use[u]) {
            dfs0(u);
            sz[v] += sz[u];
        }
}

void dfs1(int v) {
    use[v] = 1;
    vector<int> ch;
    for (auto u: e[v])
        if (!use[u])  {
            dfs1(u);
            ch.pb(type[u]);
        }
    sort(all(ch));
    if (q.count(ch) == 0) {
        q[ch] = cur++;
    }
    type[v] = q[ch];
}

int best;
int answer;

void dfs2(int v, int val) {
    use[v] = 1;
    if (cnt[type[v]] > 1)
        val++;
    if (val > best) {
        best = val;
        answer = v;
    }
    for (auto u: e[v])
        if (!use[u])
            dfs2(u, val);
}

void solve() {
    dfs0(0);
    int v = 0;
    bool flag = 1;
    while (flag) {
        flag = 0;
        for (auto u: e[v]) {
            if (sz[u] > sz[v])
                continue;
            if (sz[u] * 2 > n) {
                v = u;
                flag = 1;
                break;
            }  
        }
    }
    db(v);

    for (int i = 0; i < n; i++)     
        use[i] = 0;
    dfs1(v);
    cnt.resize(cur);
    for (int i = 0; i < n; i++)
        cnt[type[i]]++;
    
    for (int i = 0; i < n; i++)
        use[i] = 0;
    dfs2(v, 0);
    
    cout << answer + 1 << endl;
    db(best);
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