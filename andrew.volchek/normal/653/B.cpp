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

    int n, q;
    cin >> n >> q;

    map<string, string> m;
    for (int i = 0; i < q; i++) {
        string x, y;
        cin >> x >> y;
        m[x] = y;
    }

    int ub = 1;
    for (int i = 0; i < n; i++) {
        ub *= 6;
    }

    int ans = 0;
    for (int i = 0; i < ub; i++) {
        string s;
        int x = i;
        for (int j = 0; j < n; j++) {
            s += 'a' + (x % 6);
            x /= 6;
        }

        while (s.size() > 1) {
            string x = s.substr(0, 2);
            string y = s.substr(2, 100);
            if (!m.count(x)) {
                break;
            }
            s = m[x] + y;
        }

        if (s == "a") {
            ans++;
        }
    }


    cout << ans << endl;
    return 0;
}