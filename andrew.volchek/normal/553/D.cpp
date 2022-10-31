#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

const int maxn = 100005;

vector<int> g[maxn];
int bad[maxn];
int fo[maxn];
ll ne[maxn];
int n;

bool check(ll num, ll den) {
    for (int i = 1; i <= n; i++) {
        bad[i] = fo[i];
        ne[i] = 0;
    }

    queue<int> q;
    vector<int> f;

    for (int i = 1; i <= n; i++) {
        if (bad[i]) {
            continue;
        }
        for (int to : g[i]) {
            ne[i] += !bad[to];
        }

        if (ne[i] * den < num * g[i].size()) {
            q.push(i);
            f.pb(i);
        }
    }

    for (int x : f) {
        bad[x] = 1;
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : g[v]) {
            if (bad[to]) {
                continue;
            }

            ne[to]--;

            if (ne[to] * den < num * g[to].size()) {
                bad[to] = 1;
                q.push(to);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!bad[i]) {
            return true;
        }
    }

    return false;
}

void gen() {
    ofstream out("a.in");
    int n = 1e5, m = 1e5, k = 1;
    out << n << " " << m << " " << k << endl;
    for (int i = 0; i < k; i++) {
        out << (rand() % n) + 1 << endl;
    }
    for (int i = 0; i < m; i++) {
        int u = rand() % n, v = rand() % n;
        out << u + 1 << " " << v + 1 << endl;
    }
    out.close();
}

int main() {
    //srand(time(NULL));
    //gen();
    //freopen("a.in", "r", stdin);

    int m, k;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        fo[x] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }



    ld lo = 0, hi = 1.1;
    const ll mu = 1e12;

    for (int i = 0; i < 50; i++) {
        ld mid = (lo + hi) / 2.0;

        if (check(mid * mu, mu)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    check(lo * mu, mu);

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (!bad[i]) {
            ans.pb(i);
        }
    }


    printf("%d\n", (int)ans.size());

    for (int i = 0; i < ans.size(); i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", ans[i]);
    }
    cout << endl;

    cerr << (ld)clock() / CLOCKS_PER_SEC << endl;

    return 0;
}