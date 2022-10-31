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

const int maxn = 2e5 + 5;
int cnt[maxn];

int main() {
    //srand(time(NULL));

    retry:
#ifdef LOCAL
    //gen();

    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif
    int already = 0;
    int n, root;
    scanf("%d %d", &n, &root);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (i == root) {
            if (x != 0) {
                x = 0;
                already++;
            }
        }
        cnt[x]++;
    }
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 1e9;
    int r = n;
    r -= cnt[0];
    int l = cnt[0] - 1;
    int occ = 1;
    int add = cnt[0] - 1;
    for (int i = 1; i < n; i++) {
        l += max(0, cnt[i] - 1);
        r -= cnt[i];
        occ += cnt[i] > 0;
        {
            int need = i + 1 - occ;
            need = max(0, need - r);
            if (need <= l) {
                need = max(0, need - add);
                //cout << i << " " << r + need + add << endl;
                chmin(ans, r + add + need);
            }
        }
    }

    cout << ans + already << endl;



    return 0;
}