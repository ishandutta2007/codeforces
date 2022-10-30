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


const int maxn = 505;
const ll mod = 1000000007;


void mergeOr(int l, int r, vector<ll> &a, vector<ll> &b) {
    if (l == r) {
        a[l] = a[l] * b[l] % mod;
        return;
    }

    int c = (l + r) >> 1;
    int len = (r - l + 1) >> 1;

    for (int i = 0; i < len; i++) {
        a[c + 1 + i] += a[l + i];
        if (a[c + 1 + i] >= mod) {
            a[c + 1 + i] -= mod;
        }
        b[c + 1 + i] += b[l + i];
        if (b[c + 1 + i] >= mod) {
            b[c + 1 + i] -= mod;
        }
    }

    mergeOr(l, c, a, b);
    mergeOr(c + 1, r, a, b);

    for (int i = 0; i < len; i++) {
        a[c + 1 + i] -= a[l + i];
        if (a[c + 1 + i] < 0) {
            a[c + 1 + i] += mod;
        }
    }
}

const int maxs = 1 << 16;

void mergeAnd(int l, int r, vector<ll> &a, vector<ll> &b) {
    vector<ll> na(1 << 16), nb(1 << 16);
    for (int i = 0; i < maxs; i++) {
        int j = (~i) & (maxs - 1);
        na[j] = a[i];
        nb[j] = b[i];
    }
    mergeOr(0, maxs - 1, na, nb);
    for (int i = 0; i < maxs; i++) {
        int j = (~i) & (maxs - 1);
        a[j] = na[i];
    }
}

char s[maxn];



map<char, vector<ll>> was;

vector<ll> forS(char curC) {
    if (was.count(curC)) {
        return was[curC];
    }

    vector<ll> res(maxs, 0);

    for (char c : {'A', 'B', 'C', 'D', 'a', 'b', 'c', 'd'}) {
        if (curC != c && curC != '?') {
            continue;
        }

        int st = 0;
        for (int j = 0; j < 16; j++) {
            if (isupper(c)) {
                st |= bool(j & (1 << (c - 'A'))) << j;
            } else {
                st |= (!bool(j & (1 << (c - 'a')))) << j;
            }
        }

        res[st]++;
    }


    return was[curC] = res;
}


vector<ll> solve(int l, int r) {
    if (l == r) {
        return forS(s[l]);
    }

    int fb = l + 1;
    int bal = 1;
    while (true) {
        if (s[fb] == '(') {
            bal++;
        } else if (s[fb] == ')') {
            bal--;
        }
        if (!bal) {
            break;
        }
        fb++;
    }

    char op = s[fb + 1];


    auto resL = solve(l + 1, fb - 1);

    l = fb + 3;
    fb += 3;

    bal = 1;
    while (true) {
        if (s[fb] == '(') {
            bal++;
        } else if (s[fb] == ')') {
            bal--;
        }
        if (!bal) {
            break;
        }
        fb++;
    }

    auto resR = solve(l, fb - 1);


    vector<ll> res(maxs, 0);


    if (op == '?' || op == '|') {
        auto oldL = resL, oldR = resR;
        mergeOr(0, maxs - 1, resL, resR);

        for (int i = 0; i < maxs; i++) {
            res[i] += resL[i];
            if (res[i] >= mod) {
                res[i] -= mod;
            }
        }

        resL = oldL, resR = oldR;
    }

    if (op == '?' || op == '&') {
        auto oldL = resL, oldR = resR;
        mergeAnd(0, maxs - 1, resL, resR);

        for (int i = 0; i < maxs; i++) {
            res[i] += resL[i];
            if (res[i] >= mod) {
                res[i] -= mod;
            }
        }

        resL = oldL, resR = oldR;
    }

    return res;
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


    scanf("%s\n", s);

    auto res = solve(0, strlen(s) - 1);
    int n;
    scanf("%d", &n);

    vector<int> goodS;
    for (int i = 0; i < maxs; i++) {
        goodS.pb(i);
    }


    for (int i = 0; i < n; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        int msk = a + 2 * b + 4 * c + 8 * d;

        vector<int> ng;
        for (int x : goodS) {
            if (bool(x & (1 << msk)) == e) {
                ng.pb(x);
            }
        }

        goodS = ng;
    }


    //cout << goodS.size() << endl;
    ll ans = 0;
    for (int x : goodS) {
        ans = (ans + res[x]) % mod;
    }

    cout << ans << endl;

    return 0;
}