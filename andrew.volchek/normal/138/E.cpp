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

const int maxn = 1e5 + 5;

int a[maxn][26];
char s[maxn];

int sum[maxn];
int cnt[maxn];

int L, R;
ll ans;


void change(int &x, int y) {
    if (L <= x && x <= R) {
        ans--;
    }

    x = y;

    if (L <= x && x <= R) {
        ans++;
    }
}

int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    // gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    scanf("%s\n", s + 1);

    int n = strlen(s + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            a[i][j] = a[i - 1][j];
        }
        a[i][s[i] - 'a']++;
    }

    struct restr {
        int c, l, r;
        int posL, posR;
    };

    vector<restr> b;

    int k;
    scanf("%d %d %d\n", &k, &L, &R);

    for (int i = 0; i < k; i++) {
        char c;
        int l, r;
        scanf("%c %d %d\n", &c, &l, &r);
        b.pb({c - 'a', l, r, 0, 0});
    }


    ll globalAns = 0;

    for (int i = 1; i <= n; i++) {

        if (L <= 0 && 0 <= R) {
            ans++;
        }

        for (auto &x : b) {
            while (x.posR < i && a[i][x.c] - a[x.posR][x.c] >= x.l) {
                x.posR++;
                change(sum[x.posR], sum[x.posR] + 1);
            }

            while (x.posL <= x.posR && a[i][x.c] - (x.posL ? a[x.posL - 1][x.c] : 0) > x.r) {
                if (x.posL) {
                    change(sum[x.posL], sum[x.posL] - 1);
                }

                x.posL++;
            }
        }

        globalAns += ans;
    }


    cout << globalAns << endl;

    return 0;
}