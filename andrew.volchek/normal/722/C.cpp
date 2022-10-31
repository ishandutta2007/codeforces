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
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        b[i]--;
    }

    map<ll,int> cnt;
    vector<ll> ans;
    reverse(b.begin(), b.end());
    set<pair<pair<int,int>, ll>> s;

    ans.pb(0);

    for (int x : b) {
        auto it = s.lower_bound(mp(mp(x + 1, -1), -1));

        int l = x, r = x;
        ll sum = a[x];


        if (it != s.end() && it->fst.fst == x + 1) {
            r = it->fst.snd;
            sum += it->snd;
            cnt[it->snd]--;
            if (cnt[it->snd] == 0) {
                cnt.erase(it->snd);
            }
            s.erase(it);
        }

        it = s.lower_bound(mp(mp(x + 1, -1), -1));

        if (it != s.begin()) {
            it--;

            if (it->fst.snd == x - 1) {
                l = it->fst.fst;
                sum += it->snd;
                cnt[it->snd]--;
                if (cnt[it->snd] == 0) {
                    cnt.erase(it->snd);
                }
                s.erase(it);
            }
        }

        cnt[sum]++;
        s.insert(mp(mp(l, r), sum));

        ans.pb(cnt.rbegin()->fst);

    }

    ans.pop_back();
    reverse(ans.begin(), ans.end());

    for (ll x : ans) {
        cout << x << endl;
    }


    return 0;
}