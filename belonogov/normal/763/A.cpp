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
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

vector<pair<int,int>> edge;
int n;
vector<int> c;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        edge.pb(mp(v, u));
    }
    c.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    vector<int> cnt(n, 0);
    for (auto x: edge) {
        if (c[x.F] != c[x.S]) {
            cnt[x.F]++;
            cnt[x.S]++;
        }
    }
    int res = 0;
    int g = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i] >= res) {
            res = cnt[i];
            g = i;
        }
    }
    for (auto x: edge) {
        if (c[x.F] != c[x.S]) {
            if (g != x.F && g != x.S) {
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
    printf("%d\n", g + 1);
}

void solve() {

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