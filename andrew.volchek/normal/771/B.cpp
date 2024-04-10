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
#include <numeric>
#include <future>

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

const ld pi = acos(-1.0);

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
bool chmin(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool chmax(T &x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
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


//--------------------------------------------------------------------------

const int maxn = 55;
int g[maxn][maxn];

int main(int argc, char* argv[]) {

    srand(134);

#ifdef LOCAL
    freopen("a.in", "r", stdin);

#else
    //freopen("identification.in", "r", stdin);
    //freopen("identification.out", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;

    int l = 0, r = k - 1;
    for (int i = 0; i < n - k + 1; i++) {
        string s;
        cin >> s;

        if (s == "YES") {
            for (int u = l; u <= r; u++) {
                for (int v = l; v <= r; v++) {
                    g[u][v] = 1;
                }
            }
        }
        l++, r++;
    }

   // cout << g[1][3] << endl;

    vector<int> ans(n);
    int v = 0;
    for (int i = 0; i < n; i++) {
        bool any = false;
        set<int> bad;
        for (int j = 0; j < i; j++) {
            if (g[j][i]) {
                bad.insert(ans[j]);
            }
        }
        for (int j = 0; j < i; j++) {
            if (!bad.count(ans[j])) {
                any = true;
                ans[i] = ans[j];
            }
        }
        if (!any) {
            ans[i] = v++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << char('A' + ans[i] / 26);
        cout << char('a' + ans[i] % 26);
        cout << " ";
    }
    cout << endl;


    return 0;
}