#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> void chmin(T &x, const T y) { if (x > y) { x = y; } }
template <typename T> void chmax(T &x, const T y) { if (x < y) { x = y; } }

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

void factorize(int x, set <int> &s) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            s.insert(i);
            do {
                x /= i;
            } while (x % i == 0);
        }
    }
    if (x > 1) {
        s.insert(x);
    }
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    int A, B;
    while (scanf("%d %d %d", &n, &A, &B) == 3) {
        int a[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        set <int> s;
        for (int i = -1; i <= 1; ++i) {
            factorize(a[0] + i, s);
            factorize(a[n - 1] + i, s);
        }

        const ll INF = (ll)1e+18 + 7;
        ll answer = INF;
        for (auto& g : s) {
            bool allow = true;
            ll sum = 0;
            ll pref = 0;

            ll best = INF;
            for (int i = 0; i < n; ++i) {
                if (pref > 0 && allow) {
                    pref = 0;
                }

                pref += A;
                if (a[i] % g) {
                    if ((a[i] + 1) % g == 0 || (a[i] - 1) % g == 0) {
                        sum += B;
                        pref -= B;
                    } else {
                        best = INF;
                        allow = false;
                    }
                }
                best = min(best, pref);
            }
            if (allow) {
                best = min(best, 0LL);
            }
            //cout << g << " " << best + sum << endl;
            answer = min(answer, best + sum);
        }
        cout << answer << "\n";
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}