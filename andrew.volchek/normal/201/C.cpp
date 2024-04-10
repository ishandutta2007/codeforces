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

//-----------------------------------------------------------------------------

vector<string> split(char *s) {
    int n = strlen(s);

    vector<string> res;
    for (int i = 0; i < n; i++) {
        if (isspace(s[i])) {
            continue;
        }

        string c;
        int j = i;
        while (j < n && !isspace(s[j])) {
            c += s[j];
            j++;
        }

        res.pb(c);
        i = j - 1;
    }

    return res;
}

const int maxn = 1e5 + 5;
ll a[maxn];
ll dpR[maxn][2];
ll dpL[maxn][2];


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
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < 2) {
            dpR[i][0] = 0;
        } else {
            dpR[i][0] = (a[i] / 2) * 2 + dpR[i + 1][0];
        }

        dpR[i][1] = max(dpR[i + 1][1] + ((a[i] & 1) ? a[i] : a[i] - 1),
                dpR[i + 1][0] + a[i]);
    }

    for (int i = 1; i < n; i++) {
        if (a[i - 1] < 2) {
            dpL[i][0] = 0;
        } else {
            dpL[i][0] = (a[i - 1] / 2) * 2 + dpL[i - 1][0];
        }

        dpL[i][1] = max(dpL[i - 1][1] + ((a[i - 1] & 1) ? a[i - 1] : a[i - 1] - 1),
                        dpL[i - 1][0] + a[i - 1]);
    }


    ll ans = 0;

    for (int i = 0; i < n; i++) {
        chmax(ans, dpL[i][0] + dpR[i][1]);
        chmax(ans, dpL[i][0] + dpR[i][0]);
        chmax(ans, dpL[i][1] + dpR[i][0]);
    }

    cout << ans << endl;


    return 0;
}