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
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

int nx(int i, int n) { return (i == n - 1)? 0: i + 1; }
int pr(int i, int n) { return (i == 0)? n - 1: i - 1; }

typedef long double dbl;
typedef long long ll;
const int N = -1;
const ll INF = 1.01e9;
typedef vector<int> vi;



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<int> p(n);
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);

    vector<int> g[3][3];
    for (int i = 0; i < n; i++) {
        g[a[i] - 1][b[i] - 1].pb(p[i]);
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            sort(all(g[i][j]));
            reverse(all(g[i][j]));
        }


    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x); x--;
        int best = INF;
        int wx = -1, wy = -1;
        for (int t1 = 0; t1 < 3; t1++)
            for (int t2 = 0; t2 < 3; t2++) {
                if (t1 == x || t2 == x) {
                    if (!g[t1][t2].empty() && best > g[t1][t2].back()) {
                        best = g[t1][t2].back();
                        wx = t1;
                        wy = t2;
                    }
                }
            }

        if (best == INF) {
            printf("-1 ");
        }
        else {
            printf("%d ", best);
            g[wx][wy].pop_back();
        }
    }

    puts("");

    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}