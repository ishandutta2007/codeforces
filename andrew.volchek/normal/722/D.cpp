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


//-----------------------------------------------------------------------------

struct node {
    node *nxt[2];

    node() {
        nxt[0] = nxt[1] = nullptr;

    }
};

const int maxn = 1600005;
int cnt = 0;

node pool[maxn];

node *get() {
    return &pool[cnt++];
}

node *root = get();

void add(int x) {
    node *v = root;

    int f = 0;
    for (int i = 0; i <= 30; i++) {
        if (x & (1 << i)) {
            f = i;
        }
    }

    for (int i = f; i >= 0; i--) {
        int c = bool(x & (1 << i));

        if (!v->nxt[c]) {
            v->nxt[c] = get();
        }

        v = v->nxt[c];
    }
}

vector<int> ans;

void dfs(node *v, int c) {
    if (c) {
        ans.pb(c);
    }

    if (v->nxt[0]) {
        dfs(v->nxt[0], c << 1);
    }

    if (v->nxt[1]) {
        dfs(v->nxt[1], (c << 1) + 1);
    }

}


int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    // gen();

    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    int n;
    cin >> n;

    set<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }


    while (true) {
        int x = *a.rbegin();
        int y = -1;
        x >>= 1;
        while (x) {
            if (!a.count(x)) {
                y = x;
                break;
            }
            x >>= 1;
        }

        if (y != -1) {
            a.erase(*a.rbegin());
            a.insert(y);
        } else {
            break;
        }
    }


    for (int x : a) {
        cout << x << " " ;
    }






    return 0;
}