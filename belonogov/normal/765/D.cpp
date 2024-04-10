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

int n;
vector<int> f;

void read() {
    scanf("%d", &n);
    f.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &f[i]);
        f[i]--;
    }
}

void solve() {
    vector<vector<int>> rev(n);
    for (int i = 0; i < n; i++)
        rev[f[i]].pb(i);


    vector<int> g(n);
    vector<int> h;

    for (int i = 0; i < n; i++) {
        if (rev[i].empty()) continue;
        bool flag = 0;
        for (auto x: rev[i])
            flag |= x == i;
        if (!flag) {
            puts("-1");
            return;
        }
        for (auto x: rev[i])
            g[x] = h.size();
        h.pb(i); 
    }
    printf("%d\n", (int)h.size());
    for (auto x: g)
        printf("%d ", x + 1);
    puts("");
    for (auto x: h)
        printf("%d ", x + 1);
    puts("");
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