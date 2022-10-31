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

const int maxn = 2e6 + 6;

int main() {
    srand(time(NULL));


#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    vector<int> used(n);
    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }
        int v = i;
        int c = 0;
        while (!used[v]) {
            c++;
            used[v] = 1;
            v = a[v];
        }
        b.pb(c);
    }
    sort(b.begin(), b.end());

    bitset<maxn> can;
    can[0] = 1;


    map<int,int> cnt;
    for (int x : b) {
        cnt[x]++;
    }

    for (auto kv : cnt) {
        int x = kv.snd;
        for (int i = 0; ; i++) {
            if (x < (1 << i)) {
                break;
            }
            can |= can << (kv.fst * (1 << i));
            x -= 1 << i;
        }
        if (x) {
            can |= can << (kv.fst * x);
        }
    }

    int ansMi = k + !can[k];

    int ansMa = 0;

    reverse(b.begin(), b.end());
    for (int &x : b) {
        if (!k) {
            break;
        }
        int y = x / 2;
        ansMa += min(y, k) * 2;
        k -= min(y, k);
        x -= y * 2;
    }

    for (int &x : b) {
        if (!k) {
            break;
        }

        if (x == 1) {
            ansMa++;
            k--;
        }
    }


    cout << ansMi << " " << ansMa << endl;

    return 0;
}