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

ll gcd(ll a, ll b) {
    return a ? gcd(b % a, a) : b;
}

struct R {
    ll num, den;
    R(ll num = 0, ll den = 1) : num(num), den(den){
        ll g = gcd(abs(num), abs(den));
        this->num /= g;
        this->den /= g;
    }
    R operator + (const R& rhs) const {
        return R(num * rhs.den + den * rhs.num, den * rhs.den);
    }
    R operator - (const R& rhs) const {
        return R(num * rhs.den - den * rhs.num, den * rhs.den);
    }
    R operator * (const R& rhs) const {
        return R(num * rhs.num, den * rhs.den);
    }
    R operator / (const R& rhs) const {
        return R(num * rhs.den, den * rhs.num);
    }
    bool operator < (const R& rhs) const {
        return num * rhs.den < den * rhs.num;
    }
    bool operator <= (const R& rhs) const {
        return num * rhs.den <= den * rhs.num;
    }
};

ll getScore(R x) {
    if (R(1, 2) < x && x <= R(1, 1)) {
        return 500;
    } else if (R(1, 4) < x) {
        return 1000;
    } else if (R(1, 8) < x) {
        return 1500;
    } else if (R(1, 16) < x) {
        return 2000;
    } else if (R(1, 32) < x) {
        return 2500;
    } else {
        return 3000;
    }
}

int main() {

    srand(0);

#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("brackets.in", "r", stdin);
    //freopen("brackets.out", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> solved(5);
    vector<int> V(5), P(5);
    for (int i = 0; i < 5; i++) {
        cin >> V[i];
        solved[i] += V[i] != -1;
    }
    for (int i = 0; i < 5; i++) {
        cin >> P[i];
        solved[i] += P[i] != -1;
    }

    for (int i = 2; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            int x;
            cin >> x;
            solved[j] += x != -1;
        }
    }

    //cout <<

    ll all = n;
    ll ans = 1e18;
    for (int add = 0; add < 120 * 37 * 2; add++) {
        R diff(0, 1);
        for (int i = 0; i < 5; i++) {
            if (V[i] == -1 && P[i] == -1) {
                continue;
            } else if (V[i] == -1) {
                ll s = getScore(R(solved[i], add + all));
                diff = diff - R(s) * (R(1) - R(P[i], 250));
            } else if (P[i] == -1) {
                ll s = getScore(R(solved[i], add + all));
                diff = diff + R(s) * (R(1) - R(V[i], 250));
            } else {
                if (V[i] < P[i]) {
                    ll s = getScore(R(solved[i], add + all));
                    //cout << (R(s) * (R(1) - R(P[i], 250))).num << " " << (R(1) - R(P[i], 250)).den << endl;
                    diff = diff - R(s) * (R(1) - R(P[i], 250));
                    diff = diff + R(s) * (R(1) - R(V[i], 250));
                } else {
                    ll s = getScore(R(solved[i] + add, add + all));
                    //cout << s << endl;
                    diff = diff - R(s) * (R(1) - R(P[i], 250));
                    diff = diff + R(s) * (R(1) - R(V[i], 250));
                }
            }
        }


        if (R(0) < diff) {
            ans = add;
            break;
        }

    }

    if (ans < 1e17) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }







    return 0;
}