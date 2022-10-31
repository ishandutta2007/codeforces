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

const ld pi = 3.14159265359;

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


int brute(vector<ll> a, int h) {
    int n = a.size();
    int ans = 1e9;
    for (int i = 0; i < (1 << n); i++) {
        vector<int> b, c;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                b.pb(a[j]);
            } else {
                c.pb(a[j]);
            }
        }
        int mi = 1e9, ma = -1e9;
        for (int j = 0; j < b.size(); j++) {
            for (int h = j + 1; h < b.size(); h++) {
                chmin(mi, b[j] + b[h]);
                chmax(ma, b[j] + b[h]);
            }
        }

        for (int j = 0; j < c.size(); j++) {
            for (int h = j + 1; h < c.size(); h++) {
                chmin(mi, c[j] + c[h]);
                chmax(ma, c[j] + c[h]);
            }
        }

        for (int x : b) {
            for (int y : c) {
                chmin(mi, x + y + h);
                chmax(ma, x + y + h);
            }
        }

        ans = min(ans, ma - mi);
    }

    return ans;
}

void gen() {
    int n = 6;
    int h = rand() % 10;
    ofstream out("a.in");
    out << n << " " << h << endl;
    for (int i = 0; i < n; i++) {
        out << rand() % 10 << endl;
    }
    out.close();
}

int main() {
    srand(time(NULL));
/*while (true)*/ {
#ifdef LOCAL
    gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n, h;
    scanf("%d %d", &n, &h);
    vector<pair<ll, int>> a;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a.pb(mp(x, i));
    }
    sort(a.begin(), a.end());
    ll ans = (a[n - 1].fst + a[n - 2].fst) - (a[0].fst + a[1].fst);
    int ansI = -1;

    multiset<ll> s, t;

    for (int i = 0; i < n; i++) {
        t.insert(a[i].fst);
    }

    for (int i = 1; i < n; i++) {

        {
            t.erase(t.find(a[i].fst));
            s.insert(a[i].fst);
        }

        ll mi = 1e18, ma = -1e18;

        if (s.size() && t.size()) {
            mi = min(mi, *s.begin() + *t.begin() + h);
            ma = max(ma, *s.rbegin() + *t.rbegin() + h);
        }

        if (s.size() > 1) {
            auto it = s.begin();
            auto it2 = it;
            it2++;

            mi = min(mi, *it + *it2);
            auto it3 = s.rbegin();
            auto it4 = it3;
            it4++;

            ma = max(ma, *it3 + *it4);
        }

        if (t.size() > 1) {
            auto it = t.begin();
            auto it2 = it;
            it2++;

            mi = min(mi, *it + *it2);
            auto it3 = t.rbegin();
            auto it4 = it3;
            it4++;

            ma = max(ma, *it3 + *it4);
        }

        if (ans > ma - mi) {
            ans = ma - mi;
            ansI = i;
        }

        /*{
            vector<int> b, c;
            b.pb(a[0]);
            for (int i2 = 1; i2 <= i; i2++) {
                c.pb(a[i2]);
            }
            for (int i2 = i + 1; i2 < n; i2++) {
                b.pb(a[i2]);
            }

            int mi2 = 1e9, ma2 = -1e9;
            for (int j = 0; j < b.size(); j++) {
                for (int h = j + 1; h < b.size(); h++) {
                    chmin(mi2, b[j] + b[h]);
                    chmax(ma2, b[j] + b[h]);
                }
            }

            for (int j = 0; j < c.size(); j++) {
                for (int h = j + 1; h < c.size(); h++) {
                    chmin(mi2, c[j] + c[h]);
                    chmax(ma2, c[j] + c[h]);
                }
            }

            for (int x : b) {
                for (int y : c) {
                    chmin(mi2, x + y + h);
                    chmax(ma2, x + y + h);
                }
            }

            assert(ma2 - mi2 == ma - mi);
        }*/
    }

    cout << ans << endl;

    if (ansI == -1) {
        for (int i = 0; i < n; i++) {
            if (i) {
                printf(" ");
            }
            printf("1");
        }
    } else {
        vector<int> ans(n, 1);
        for (int i = 1; i <= ansI; i++) {
            ans[a[i].snd] = 2;
        }
        for (int i = 0; i < n; i++) {
            if (i) {
                printf(" ");
            }
            printf("%d", ans[i]);
        }
    }
}

    return 0;
}