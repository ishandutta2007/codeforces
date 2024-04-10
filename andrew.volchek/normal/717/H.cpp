#include <cstdio>
#include <set>
#include <ostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>
#include <assert.h>
#include <iomanip>
#include <map>

using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld double


const ld pi = acos(-1);


template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
ostream& operator << (ostream &s, const vector<T> &x) {
    s << "[";
    for (typename vector<T>::const_iterator it = x.begin(); it != x.end(); ++it) {
        s << *it << ", ";
    }
    s << "]";
    return s;
}

template<typename T>
ostream& operator << (ostream &s, const set<T> &x) {
    s << "{";
    for (typename set<T>::iterator it = x.begin(); it != x.end(); ++it) {
        s << *it << ", ";
    }
    s << "}";
    return s;
}


template<typename U, typename V>
ostream& operator << (ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename T>
bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

//---------------------------------------------------------------------

const int maxn = 1e5 + 5;
vector<int> g[maxn];
int color[maxn];

int main() {
    srand(time(NULL));
    retry:
#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#else
    //freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    fill(color, color + maxn, -1);
    for (int i = 1; i <= n; i++) {
        int cnt[2] = {0, 0};
        for (int to : g[i]) {
            if (color[to] != -1) {
                cnt[color[to]]++;
            }
        }

        if (cnt[0] > cnt[1]) {
            color[i] = 1;
        } else {
            color[i] = 0;
        }
    }

    vector<int> teams;
    int tCnt = 0;
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            a[i].pb(x);
            chmax(tCnt, x);
        }
    }

    teams.resize(tCnt + 1);
    for (int i = 1; i <= tCnt / 2; i++) {
        teams[i] = 1;
    }

    while (true) {
        random_shuffle(teams.begin() + 1, teams.end());
        bool good = true;
        for (int i = 1; i <= n; i++) {
            int was[2] = { 0, 0 };
            for (int x : a[i]) {
                was[teams[x]] = 1;
            }
            good &= was[color[i]];
        }
        if (good) {
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            printf(" ");
        }
        for (int x : a[i]) {
            if (teams[x] == color[i]) {
                printf("%d", x);
                break;
            }
        }
    }
    printf("\n");

    for (int i = 1; i < teams.size(); i++) {
        if (i > 1) {
            printf(" ");
        }
        printf("%d", teams[i] + 1);
    }
    printf("\n");


    return 0;
}