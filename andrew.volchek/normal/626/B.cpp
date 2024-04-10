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
#define ld double
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

const int maxn = 205;
int was[maxn][maxn][maxn];


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

    int x = 0, y = 0, z = 0;
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        char c;
        scanf("%c", &c);
        x += c == 'R';
        y += c == 'G';
        z += c == 'B';
    }

    was[x][y][z] = 1;

    for (int sum = n; sum > 0; sum--) {
        for (int i = sum; i >= 0; i--) {
            for (int j = sum - i; j >= 0; j--) {
                {
                    int k = sum - i - j;

                    if (was[i][j][k] == 0) {
                        continue;
                    }

                    if (i > 1) {
                        was[i - 1][j][k] = 1;
                    }

                    if (j > 1) {
                        was[i][j - 1][k] = 1;
                    }

                    if (k > 1) {
                        was[i][j][k - 1] = 1;
                    }

                    if (i && j) {
                        was[i - 1][j - 1][k + 1] = 1;
                    }

                    if (i && k) {
                        was[i - 1][j + 1][k - 1] = 1;
                    }

                    if (j && k) {
                        was[i + 1][j - 1][k - 1] = 1;
                    }
                }
            }
        }
    }

    string ans;
    if (was[1][0][0]) {
        ans += "R";
    }

    if (was[0][1][0]) {
        ans += "G";
    }

    if (was[0][0][1]) {
        ans += "B";
    }

    sort(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}