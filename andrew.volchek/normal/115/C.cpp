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
#include <limits>
#include <tuple>
#include <complex>

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

const ld pi = acos(-1.0l);

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
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 5e5 + 5;
const int mod = 1000003;
char s[maxn];


int main() {

    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

#else
    //freopen("hovels.in", "r", stdin);
    //freopen("hovels.out", "w", stdout);
#endif

    int n, m;
    scanf("%d %d\n", &n, &m);

    vector<vector<int>> a(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        scanf("%s\n", s);
        for (int j = 0; j < m; j++) {
            if (isdigit(s[j])) {
                a[i][j] = s[j] - '1';
            }
        }
    }

    auto die = []() {
        cout << 0 << endl;
        exit(0);
    };

    int ans = 1;
    for (int i = 0; i < n; i++) {
        int p = -1;
        for (int j = 0; j < m; j++) {
            if (a[i][j] != -1) {
                p = (j & 1) ^ bool(a[i][j] & 2);
                break;
            }
        }

        if (p == -1) {
            ans = ans * 2 % mod;
            continue;
        }

        for (int j = 0; j < m; j++) {
            if (a[i][j] != -1 && ((j & 1) ^ bool(a[i][j] & 2)) != p) {
                die();
            }
        }
    }

    auto vert = [](int x) {
        return x == 0 || x == 3;
    };

    for (int i = 0; i < m; i++) {
        int p = -1;
        for (int j = 0; j < n; j++) {
            if (a[j][i] != -1) {
                p = (j & 1) ^ vert(a[j][i]);
                break;
            }
        }

        if (p == -1) {
            ans = ans * 2 % mod;
            continue;
        }

        for (int j = 0; j < n; j++) {
            if (a[j][i] != -1 && ((j & 1) ^ vert(a[j][i])) != p) {
                die();
            }
        }
    }

    cout << ans << endl;

    return 0;
}