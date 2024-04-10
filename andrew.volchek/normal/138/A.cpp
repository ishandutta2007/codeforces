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

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool check(const string &a, const string &b) {
    return a == b;
}


string type(vector<string> a, int k) {
    for (string &s : a) {
        reverse(s.begin(), s.end());

        int p = 0;
        int cnt = 0;
        while (p < s.size() && cnt < k) {
            cnt += isVowel(s[p]);
            p++;
        }

        if (cnt != k) {
            return "NO";
        }

        s = s.substr(0, p);
    }

    //cout << a << endl;

    int g[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            g[i][j] = 0;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            g[i][j] = check(a[i], a[j]);
        }
    }

    if (g[0][1] && g[1][2] && g[2][3]) {
        return "aaaa";
    } else if (g[0][3] && g[1][2]) {
        return "abba";
    } else if (g[0][1] && g[2][3]) {
        return "aabb";
    } else if (g[0][2] && g[1][3]) {
        return "abab";
    } else {
        return "NO";
    }
}

char s[100005];

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

    int n, k;
    scanf("%d %d\n", &n, &k);

    string ans;

    for (int i = 0; i < n; i++) {
        vector<string> c;
        for (int j = 0; j < 4; j++) {
            scanf("%s\n", s);
            c.pb(s);
        }
        auto r = type(c, k);


        if (r == "NO") {
            cout << "NO" << endl;
            return 0;
        }

        if (ans.empty()) {
            ans = r;
        } else {
            if (ans == "aaaa") {
                ans = r;
            } else if (r == "aaaa") {

            } else {
                if (ans != r) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}