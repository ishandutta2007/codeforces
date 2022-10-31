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
#include <ctime>

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

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}


const ll mod = 1000000007;

ll add(ll x, ll y) {
    return (x + y) % mod;
}

ll sub(ll x, ll y) {
    return (x - y + mod) % mod;
}

ll mul(ll x, ll y) {
    return (x * y) % mod;
}

const int maxn = 105;

vector<int> g[maxn];
int used[maxn];

void dfs(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}


int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    vector<pair<int,int>> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a.pb(mp(x, y));
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].fst == a[j].fst || a[i].snd == a[j].snd) {
                g[i].pb(j);
                g[j].pb(i);
            }
        }
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            c++;
            dfs(i);
        }
    }

    cout << c - 1 << endl;

    return 0;
}