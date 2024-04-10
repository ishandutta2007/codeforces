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


const int mod = 1000000007;

int f[1005][105];
int nf[1005][105];

void add(int &x, ll y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

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

    int n, k;
    cin >> n >> k;
    //n = 200, k = 1000;

    vector<int> a(n);
    int mi = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        //a[i] = rand() % 500;
        chmin(mi, a[i]);
    }


    sort(a.begin(), a.end());

    f[0][0] = 1;
    int prv = a[0];
    for (int x : a) {
        for (int i = 0; i < 1005; i++) {
            for (int j = 0; j < 105; j++) {
                int a = (x - prv) * j;
                if (i + a <= k) {
                    add(nf[i + a][j], f[i][j] * 1LL * (1 + j) % mod);
                    if (j + 1 < 105) {
                        add(nf[i + a][j + 1], f[i][j]);
                    }

                    if (j) {
                        add(nf[i + a][j - 1], f[i][j] * 1LL * j % mod);
                    }
                }
            }
        }

        for (int i = 0; i < 1005; i++) {
            for (int j = 0; j < 105; j++) {
                f[i][j] = nf[i][j];
                nf[i][j] = 0;
            }
        }

        prv = x;
    }

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        add(ans, f[i][0]);
    }

    cout << ans << endl;

    return 0;
}