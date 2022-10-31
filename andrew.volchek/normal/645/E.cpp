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

const int maxn = 2e6 + 5;
const int mod = 1000000007;
char s[maxn];
ll dp[maxn];

int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif

    int n, k;
    scanf("%d %d\n", &n, &k);
    scanf("%s", s + 1);
    int m = strlen(s + 1);

    int prv[30];
    fill(prv, prv + 30, -1);

    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        dp[i] = dp[i - 1] * 2 % mod;
        s[i] -= 'a';
        if (prv[s[i]] != -1) {
            dp[i] = dp[i] + mod - dp[prv[s[i]] - 1];
            if (dp[i] >= mod) {
                dp[i] -= mod;
            }
        }
        prv[s[i]] = i;
    }

    set<pair<int,int>> was;
    for (int i = 0; i < k; i++) {
        was.insert(mp(prv[i], i));
    }

    for (int i = m + 1; i <= m + n; i++) {
        auto c = *was.begin();
        was.erase(c);
        s[i] = c.snd;
        dp[i] = dp[i - 1] * 2 % mod;
        if (prv[s[i]] != -1) {
            dp[i] = dp[i] + mod - dp[prv[s[i]] - 1];
            if (dp[i] >= mod) {
                dp[i] -= mod;
            }
        }
        prv[s[i]] = i;
        was.insert(mp(i, s[i]));
    }

    cout << dp[n + m] << endl;


    return 0;
}