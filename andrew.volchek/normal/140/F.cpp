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

struct pt {
    int x, y;
    pt(int x = 0, int y = 0) : x(x), y(y) {

    }

    pt operator + (const pt &rhs) const {
        return pt(x + rhs.x, y + rhs.y);
    }

    pt operator - (const pt &rhs) const {
        return pt(x - rhs.x, y - rhs.y);
    }

    bool operator < (const pt &rhs) const {
        return mp(x, y) < mp(rhs.x, rhs.y);
    }

    bool operator == (const pt &rhs) const {
        return mp(x, y) == mp(rhs.x, rhs.y);
    }

    pt operator / (const int d) const {
        return pt(x / d, y / d);
    }
};

vector<int> generateCandidates(vector<int> a, int k) {
    sort(a.begin(), a.end());
    const set<int> s(a.begin(), a.end());

    auto check = [&](int c) {
        int cnt = 0;
        for (int p : a) {
            cnt += !s.count(c - (p - c));
            if (cnt > k) {
                break;
            }
        }
        return cnt <= k;
    };

    vector<int> res;
    set<int> was;

    vector<int> groups = a;
    groups.resize(unique(groups.begin(), groups.end()) - groups.begin());

    for (int it = 0; it < 2; it++) {
        for (int j = 0; j < min(k + 1, (int)groups.size()); j++) {
            for (int i = 0; i < min((int) groups.size(), k + 1 - j); i++) {
                int c = (groups[j] + groups[groups.size() - 1 - i]) / 2;
                if (was.count(c)) {
                    continue;
                }
                was.insert(c);
                if (check(c)) {
                    res.pb(c);
                }
            }
        }

        reverse(groups.begin(), groups.end());
    }

    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());

    return res;
}

int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    // gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n, k;
    scanf("%d %d", &n, &k);
    //n = 2e5, k = 10;

    if (n <= k) {
        cout << -1 << endl;
        return 0;
    }

    vector<pt> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        //x = rand(), y = rand();
        //x = y = i;
        x *= 2;
        y *= 2;
        a.pb({x, y});
    }

    set<pt> s(a.begin(), a.end());

    if (n < 100) {
        vector<pt> ans;

        auto check = [&](pt c) {
            int cnt = 0;
            for (int h = 0; h < n; h++) {
                pt g = c - (a[h] - c);
                cnt += !s.count(g);
            }
            if (cnt <= k) {
                int diff = k - cnt;
                if (diff % 2 == 0 || !s.count(c)) {
                    return true;
                }
            }

            return false;
        };

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pt c = (a[i] + a[j]) / 2;
                if (check(c)) {
                    ans.pb(c);
                }
            }

            if (check(a[i])) {
                ans.pb(a[i]);
            }
        }

        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

        cout << ans.size() << endl;
        for (auto p : ans) {
            cout.precision(2);
            cout << fixed << p.x / 2.0 << " " << p.y / 2.0 << endl;
        }
    } else {
        random_shuffle(a.begin(), a.end());

        vector<int> cx, cy;
        for (auto p : a) {
            cx.pb(p.x);
            cy.pb(p.y);
        }

        auto candX = generateCandidates(cx, k);
        auto candY = generateCandidates(cy, k);

        vector<pt> ans;

        a.resize(min((int)a.size(), 600));

        for (int x : candX) {
            for (int y : candY) {
                pt c(x, y);

                int cnt = 0;
                for (auto p : a) {
                    cnt += !s.count(c - (p - c));
                }

                int diff = k - cnt;

                if (diff >= 0) {
                    ans.pb(c);
                }
            }
        }

        cout << ans.size() << endl;
        for (auto p : ans) {
            cout.precision(2);
            cout << fixed << p.x / 2.0 << " " << p.y / 2.0 << endl;
        }
    }


    return 0;
}