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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;

int n;
int a[N];
int perm[N];
int p[N];
ll sum[N];
bool use[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &perm[i]);
        perm[i]--;
    }
}

int getId(int v) {
    return p[v] == v? v: p[v] = getId(p[v]);
}

void merge(int v, int u) {
    v = getId(v);
    u = getId(u);
    p[v] = u;
    sum[u] += sum[v];
}

void solve() {
    for (int i = 0; i < n; i++) {
        p[i] = i;
        sum[i] = a[i];
    }

    vector<ll> res;
    ll answer = 0;
    res.pb(0);
    for (int i = n - 1; i >= 1; i--) {
        int pos = perm[i];
        use[pos] = 1;
        for (int dx = -1; dx <= 1; dx += 2) {
            int x = pos + dx;
            if (0 <= x && x < n && use[x]) {
                merge(pos, x);
            }
        }
        int v = getId(pos);
        answer = max(answer, sum[v]);
        res.pb(answer);
    }

    reverse(all(res));
    for (auto x: res)
        printf("%lld\n", x);


}

void stress() {

}

int main(){
#ifdef MY_DEBUG
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