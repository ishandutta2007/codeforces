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


struct node {
    int nxt[26];
    char mrk;
    node() {
        fill(nxt, nxt + 26, -1);
        mrk = 0;
    }
};

const int maxn = 2e6 + 123456;
node pool[maxn];
int poolSz = 0;

int main() {

    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

#else
    //freopen("hovels.in", "r", stdin);
    //freopen("hovels.out", "w", stdout);
#endif

    string a, b, c;
    cin >> a >> b >> c;
    reverse(c.begin(), c.end());


    vector<int> ends(a.size(), 0);
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        if (a.substr(i, c.size()) == c) {
            ends[a.size() - 1 - i] = 1;
        }
    }

    reverse(a.begin(), a.end());

    int root = 0;
    poolSz++;

    for (int i = 0; i < a.size(); i++) {
        if (a.substr(i, b.size()) != b) {
            continue;
        }

        int v = root;
        for (int j = i; j < a.size(); j++) {
            char cc = a[j] - 'a';

            if (pool[v].nxt[cc] == -1) {
                pool[v].nxt[cc] = poolSz++;
            }

            v = pool[v].nxt[cc];

            if (ends[j] && j - i + 1 >= max(c.size(), b.size())) {
                pool[v].mrk = 1;
            }
        }
    }


    int ans = 0;
    for (int i = 0; i < poolSz; i++) {
        ans += pool[i].mrk;
    }

    cout << ans << endl;

    return 0;
}