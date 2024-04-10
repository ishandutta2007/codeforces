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

const ll mod = 1000000007;
const int maxn = 1e6 + 5;
ll f[maxn];

int main() {
    srand(time(NULL));


#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    f[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = f[i - 1] * i % mod;
    }


    int n, m;
    scanf("%d %d", &n, &m);
    map<int, vector<pair<int,int>>> a;
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        map<int,int> cnt;
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            cnt[x]++;
        }
        for (auto kv : cnt) {
            a[kv.fst].pb(mp(i, kv.snd));
        }
    }

    ll ans = 1;
    vector<vector<pair<int,int>>> b;
    for (auto kv : a) {
        sort(kv.snd.begin(), kv.snd.end());
        b.pb(kv.snd);
    }

    for (int i = 1; i <= m - b.size(); i++) {
        ans = ans * i % mod;
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < b.size(); i++) {
        int j = i;
        while (j < b.size() && b[i] == b[j]) {
            j++;
        }
        ans = ans * f[j - i] % mod;
        i = j - 1;
    }

    cout << ans << endl;




    return 0;
}