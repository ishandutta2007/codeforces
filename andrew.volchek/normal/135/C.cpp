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
char s[maxn];

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

    int one = 0, zero = 0, add = 0;
    scanf("%s", s);

    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        one += s[i] == '1';
        zero += s[i] == '0';
        add += s[i] == '?';
    }


    int ans = 0;

    if (zero + add >= one + 1) {
        ans |= 1 << 0;
    }

    if (one + add >= zero + 2) {
        ans |= 1 << 3;
    }


    for (int i = 0; i <= add; i++) {
        if ((one + i == zero + add - i) || (one + i - 1 == zero + add - i)) {

            int x = i;

            int p[2] = {0, 0};
            for (int j = 0; j < n; j++) {
                if (s[j] == '0') {
                    chmax(p[0], j);
                }
                if (s[j] == '1') {
                    chmax(p[1], j);
                }
                if (s[j] == '?') {
                    if (x) {
                        x--;
                        chmax(p[1], j);
                    } else {
                        chmax(p[0], j);
                    }
                }
            }

            if (p[0] < p[1]) {
                ans |= 1 << 1;
            } else {
                ans |= 1 << 2;
            }


            x = add - i;

            p[0] = p[1] = 0;
            for (int j = 0; j < n; j++) {
                if (s[j] == '0') {
                    chmax(p[0], j);
                }
                if (s[j] == '1') {
                    chmax(p[1], j);
                }
                if (s[j] == '?') {
                    if (x) {
                        x--;
                        chmax(p[0], j);
                    } else {
                        chmax(p[1], j);
                    }
                }
            }

            if (p[0] < p[1]) {
                ans |= 1 << 1;
            } else {
                ans |= 1 << 2;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        if (ans & (1 << i)) {
            cout << bool(i & 2) << bool(i & 1) << endl;
        }
    }



    return 0;
}