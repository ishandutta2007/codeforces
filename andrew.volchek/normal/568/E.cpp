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

ll gcd(ll a, ll b) {
    return a ? gcd(b % a, a) : b;
}

const int maxn = 2e5 + 5;
const int inf = 1e9;
int nxt[maxn];

int len[maxn];
int dp[maxn];
int ff[maxn];

int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    vector<int> cc;
    cc.pb(0);

    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        x++;
        a.pb(x);
        cc.pb(x);
    }

    int k;
    scanf("%d", &k);

    vector<int> b;
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        x++;
        b.pb(x);
        cc.pb(x);
    }

    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());


    for (int &x : a) {
        if (x != 0) {
            x = lower_bound(cc.begin(), cc.end(), x) - cc.begin();
        }
    }

    multiset<int> bs;

    for (int &x : b) {
        x = lower_bound(cc.begin(), cc.end(), x) - cc.begin();
        bs.insert(x);
    }

    sort(b.begin(), b.end());

    int p = 0;
    for (int i = 0; i < maxn; i++) {
        while (p < k && i == b[p]) {
            p++;
        }
        nxt[i] = p < k ? b[p] : -1;
    }


    fill(len, len + maxn, inf);
    len[0] = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            int lo = -1, hi = maxn;
            while (hi - lo > 1) {
                int mid = (lo + hi) >> 1;

                if (len[mid] < a[i]) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }

            dp[i] = lo + 1;
            ff[i] = a[i];

            if (len[lo + 1] > a[i]) {
                len[lo + 1] = a[i];
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                if (len[j] == inf) {
                    continue;
                }
                int x = nxt[len[j]];
                if (x != -1) {
                    if (dp[i] < j + 1) {
                        dp[i] = j + 1;
                        ff[i] = x;
                    }
                }
                if (x != -1 && len[j + 1] > x) {
                    len[j + 1] = x;
                }
            }
        }
    }

    int clen = *max_element(dp, dp + n);
    int ub = 1e9;
    int pos = n;
    p = k - 1;

    vector<vector<int>> d(maxn);
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            d[dp[i]].pb(i);
        }
    }

    for (int i = clen; i >= 1; i--) {
        bool found = false;
        for (int x : d[i]) {
            if (x < pos && a[x] < ub) {
                ub = a[x];
                pos = x;
                found = true;
                break;
            }
        }

        if (found) {
            continue;
        }

        for (int j = pos - 1; j >= 0; j--) {
            if (a[j] == 0 && dp[j] >= i) {
                while (p >= 0 && b[p] >= ub) {
                    p--;
                }

                //cerr << ub << " " << i << " " << pos << endl;

                assert(p >= 0);

                a[j] = b[p];
                bs.erase(bs.find(a[j]));
                ub = a[j];
                pos = j;
                p--;
                break;
            }
        }
    }



    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            assert(bs.size());
            a[i] = *bs.begin();
            bs.erase(bs.begin());
        }
    }

    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }

        printf("%d", cc[a[i]] - 1);
    }

    return 0;
}