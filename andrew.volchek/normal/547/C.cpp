#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <queue>
#include <assert.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

const int maxn = 500005;
int p[maxn];
int a[maxn];
vector<pair<int,int>> d[maxn];

int cnt[maxn];

int main() {
    //freopen("a.in", "r", stdin);
    for (int i = 1; i < maxn; i++) {
        p[i] = i;
    }

    for (int i = 2; i < maxn; i++) {
        if (p[i] == i) {
            for (ll j = (ll)i + i; j < maxn; j += i) {
                p[j] = i;
            }
        }
    }

    int n, q;
    scanf("%d %d", &n, &q);
    //n = 2e5;
    //q = 2e5;

    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        //a[i] = 2 * 3 * 5 * 7 * 9 * 11 * 13;

        int x = a[i];
        vector<int> c;

        while (x > 1) {
            int y = p[x];
            c.pb(y);
            while (x % y == 0) {
                x /= y;
            }
        }

        for (int j = 0; j < (1 << c.size()); j++) {
            int z = 1;
            int f = 0;
            for (int h = 0; h < c.size(); h++) {
                if (j & (1 << h)) {
                    z *= c[h];
                    f++;
                }
            }

            if (z > 1) {
                d[i].pb(mp(z, f & 1));
            }
        }
    }

    ll ans = 0;

    set<int> was;

    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);

        if (was.count(x)) {
            was.erase(x);

            for (pair<int, int> dv : d[x]) {
                cnt[dv.fst]--;
            }

            ll nonCoprime = 0;
            for (pair<int, int> dv : d[x]) {
                if (dv.snd) {
                    nonCoprime += cnt[dv.fst];
                } else {
                    nonCoprime -= cnt[dv.fst];
                }
            }

            assert(was.size() >= nonCoprime);

            ans -= ((int)was.size() - nonCoprime);
        } else {
            ll nonCoprime = 0;
            for (pair<int, int> dv : d[x]) {
                if (dv.snd) {
                    nonCoprime += cnt[dv.fst];
                } else {
                    nonCoprime -= cnt[dv.fst];
                }
            }


            assert(was.size() >= nonCoprime);

            ans += ((int)was.size() - nonCoprime);

            for (pair<int, int> dv : d[x]) {
                cnt[dv.fst]++;
            }

            was.insert(x);
        }

        printf("%I64d\n", ans);
    }


    return 0;
}