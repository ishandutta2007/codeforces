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
bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool chmax(T &x, const T y) {
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
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

#else
    //freopen("hovels.in", "r", stdin);
    //freopen("hovels.out", "w", stdout);
#endif

    int n, k;
    ll bb, c;
    cin >> n >> k >> bb >> c;
   // n = 2e5, k = 2e5, bb = 123, c = 321;


    bb = min(bb, c * 5);

    ll ans = 1e18;
    vector<ll> a;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        //x = rand();
        x += 1e9 + 5;
        a.pb(x);
    }

    for (int i = 0; i < 5; i++) {
        vector<pair<ll, ll>> b;
        for (int j = 0; j < n; j++) {
            if (a[j] % 5 == i) {
                b.pb(mp((a[j] - i) / 5, 0));
            } else {
                ll x = a[j];
                ll add = 0;
                while (x % 5 != i) {
                    x++;
                    add++;
                }
                b.pb(mp((x - i) / 5, c * add));
            }
        }

        sort(b.begin(), b.end());
        //cout << b << endl;


        multiset<ll> s;
        ll sum = 0;
        auto add = [&](ll x) {
            //cout << "add " << x << endl;
            s.insert(x);
            sum += x;
            while (s.size() > k) {
                sum -= *s.rbegin();
                s.erase(s.find(*s.rbegin()));
            }
        };

        for (int i = 0; i < b.size(); i++) {
            int j = i;
            while (j < b.size() && b[i].fst == b[j].fst) {
                j++;
            }

            for (int h = i; h < j; h++) {
                add(-b[h].fst * bb + b[h].snd);
            }

            if (s.size() == k) {
                //cout << bb * b[i].fst * k + sum << endl;
                chmin(ans, bb * b[i].fst * k + sum);
            }

            i = j - 1;
        }
    }

    cout << ans << endl;

    return 0;
}