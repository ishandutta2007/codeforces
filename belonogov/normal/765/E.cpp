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
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n;
vector<int> e[N];
bool use[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
}

bool fail = 0;
int st;

int dfs1(int v, bool top) {
    use[v] = 1;
    set<int> q;
    for (auto u: e[v]) {
        if (!use[u]) {
            int r = dfs1(u, 0);
            if (fail)
                return -1;
            q.insert(r);
        }
    }
    if (q.empty()) {
        return 1;
    }
    if (q.size() == 1) {
        return *q.begin() + 1;
    }
    if (top && q.size() == 2) {
        int sum = 0;
        for (auto x: q)
           sum += x; 
        return sum + 1;
    }
    st = v;
    fail = 1;
    return -1;


}

void printRes(int x) {
    assert(x > 0);
    for (; x % 2 == 0; x /= 2);
    printf("%d\n", x);
}

void solve() {
    int res = dfs1(0, 1);
    if (!fail) {
        printRes(res - 1);
        return;
    }
    for (int i = 0; i < n; i++)
        use[i] = 0;
    //db(st);
    fail = 0;
    res = dfs1(st, 1);
    if (fail) {
        puts("-1");
        return;
    }
    printRes(res - 1);
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