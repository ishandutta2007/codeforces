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
#define ld double
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

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

template<int sz>
ostream operator << (ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 1005;
char a[maxn], b[maxn];

int g[3][3] = {
        0, 1, 0,
        0, 0, 1,
        1, 0, 0,
};

int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int k;
    scanf("%d", &k);

    scanf("%s\n", a);
    scanf("%s\n", b);

    int n = strlen(a);
    int m = strlen(b);

    map<char,int> s({
            mp('R', 0),
            mp('S', 1),
            mp('P', 2),
                    });

    for (int i = 0; i < n; i++) {
        a[i] = s[a[i]];
    }

    for (int i = 0; i < m; i++) {
        b[i] = s[b[i]];
    }

    int cnt[2] = {0, 0};
    int ans[2] = {0, 0};

    for (int i = 0; i < n * m; i++) {
        int u = a[i % n], v = b[i % m];
        cnt[0] += g[u][v];
        cnt[1] += g[v][u];

        if ((i + 1) == (k % (n * m))) {
            ans[0] = cnt[0];
            ans[1] = cnt[1];
        }
    }

    ans[0] += cnt[0] * (k / (n * m));
    ans[1] += cnt[1] * (k / (n * m));

    cout << ans[1] << " " << ans[0] << endl;

    return 0;
}