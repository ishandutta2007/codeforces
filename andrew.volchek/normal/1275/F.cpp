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

// template<int sz>
// ostream operator<<(ostream &s, const bitset<sz> &x) {
//     for (int i = 0; i < sz; i++) {
//         s << x[i];
//     }
//     return s;
// }
//

//--------------------------------------------------------------------------




int main() {

    srand(time(NULL));

#ifdef LOCAL
    //gen();
     freopen("a.in", "r", stdin);
      //freopen("a.in", "w", stdout);
#else
    //freopen("brackets.in", "r", stdin);
    //freopen("brackets.out", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fst;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i].snd;
    }

    map<int, vector<pair<int, int>>> b;
    for (int i = 0; i < n; i++) {
        b[a[i].fst].push_back({a[i].second, i});
    }


    sort(a.begin(), a.end());

    ll ans = 0;
    int ptr = 0;

    set<pair<int, int>> was;
    ll was_sum = 0;
    while (true) {
        if (was.empty()) {
            auto it = b.lower_bound(ptr);
            if (it == b.end()) {
                break;
            }
            ptr = it->first;
        }

        if (b.count(ptr)) {
            for (auto kv : b[ptr]) {
                was.insert(kv);
                was_sum += kv.first;
            }
        }

        assert(!was.empty());
        auto val = *was.rbegin();

        was.erase(val);
        was_sum -= val.first;

        ans += was_sum;
        ++ptr;
    }

    cout << ans << endl;


    return 0;
}