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


const int mod = 1000000007;
const int maxn = 1 << 20;
int dp[77][maxn];
int nxt[maxn];

int main() {
    srand(time(NULL));


#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    for (int i = 0; i < 77; i++) {
        dp[i][0] = 1;
    }
    int n;
    cin >> n;
    //n = 75;

    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        nxt[i] = n;
        for (int j = i; j < n; j++) {
            if (s[j] == '1') {
                nxt[i] = j;
                break;
            }
        }
    }


    for (int i = 0; i < n; i++) {

        for (int h = 0; h < maxn; h++) {
            int x = 0;
            for (int j = nxt[i]; j < n && x <= 20; j++) {
                x = (x << 1) + s[j] - '0';
                if (x && x <= 20) {
                    int nh = h | (1 << (x - 1));
                    dp[j + 1][nh] += dp[i][h];
                    if (dp[j + 1][nh] >= mod) {
                        dp[j + 1][nh] -= mod;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= 20; j++) {
            ans += dp[i][(1 << j) - 1];
            if (ans >= mod) {
                ans -= mod;
            }
        }
    }

    cout << ans << endl;




    return 0;
}