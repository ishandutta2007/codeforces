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

const int maxn = 6e5 + 5;

int a[maxn];
int b[maxn];
int g[maxn];

int gcd(int a, int b) {
    return a ? gcd(b % a, a) : b;
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

    int n;
    scanf("%d", &n);
    //n = 2e5;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = a[i + n] = a[i + n + n] = x;
    }

    for (int i = 1; i <= n; i++) {
        g[i] = gcd(i, n);
    }

    ll ans = 0;

    for (int de = 1; de < n; de++) {
        if (n % de) {
            continue;
        }

        fill(b, b + maxn, 0);
        for (int j = n + n + n - 1; j >= 0; j--) {
            chmax(b[j], a[j]);
            if (j + de < n + n + n) {
                chmax(b[j], b[j + de]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (b[i] > a[i]) {
                continue;
            }
            int j = i;
            while (j < n + n && b[j] <= a[j]) {
                j++;
            }

            int len = j - i;

            for (int h = 1; h <= len; h++) {
                if (g[h] == de) {
                    ans += min(n - i, len - h + 1);
                }
            }
            i = j - 1;
        }
    }


    cout << ans << endl;

    return 0;
}