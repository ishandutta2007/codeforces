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
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int l;
        scanf("%d", &l);
        a[i].resize(l);
        for (int j = 0; j < l; j++) {
            scanf("%d", &a[i][j]);
            a[i][j]--;
        }
    }
    bool fail = 0;
    vector<int> b(m, -1);
    auto set = [&](int pos, int val) {
        if (b[pos] == val || b[pos] == -1) {
            b[pos] = val;
        }
        else {
            fail = 1;
        }
    };
    vector<vector<int>> e(m);

    for (int i = 0; i < n - 1; i++) {
        int cur = 0;
        for (; cur < (int)a[i].size() && cur < (int)a[i + 1].size() && a[i][cur] == a[i + 1][cur]; cur++);
        //db(cur);
        if (cur < (int)a[i].size() && cur == (int)a[i + 1].size()) {
            fail = 1;
        }
        if (cur < (int)a[i].size() && cur < (int)a[i + 1].size()) {
            int x = a[i][cur];
            int y = a[i + 1][cur];
            //db2(x, y);
            if (x > y) {
                //db3("type 1: ", x, y);
                set(x, 0);
                set(y, 1);
            }
            else {
                //db3("type 2: ", x, y);
                e[y].pb(x);
            }
        }
    }
    //db("done");
    vector<int> use(m, 0);
    function<void(int)> dfs = [&](int v) {
        use[v] = 1;
        for (auto u: e[v]) {
            if (!use[u]) {
                set(u, 0);
                dfs(u);
            }
        }
    };
    //db("@#$");

    for (int i = 0; i < m; i++) {
        if (b[i] == 0) {
            dfs(i);
        }
    }
    if (fail) {
        puts("No");
    }
    else {
        puts("Yes");
        vector<int> answer;
        for (int i = 0; i < m; i++) {
            if (b[i] == 0) {
                answer.pb(i);
            }
        }
        printf("%d\n", sz(answer));
        for (auto x: answer) {
            printf("%d ", x + 1);
        }
        puts("");
    }


    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}