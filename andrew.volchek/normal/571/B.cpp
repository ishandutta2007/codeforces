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

const int maxk = 5005;
const ll inf = 1e17;

ll dp[maxk][maxk];

int main() {
    //srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a.pb(x);
    }

    sort(a.begin(), a.end());
    vector<int> used(n, 0);
    vector<int> ls;

    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }

        int v = i;
        int len = 0;
        while (v < n) {
            len++;
            used[v] = 1;
            v += k;
        }

        ls.pb(len);
    }

    sort(ls.begin(), ls.end());

    for (int i = 0; i < maxk; i++) {
        fill(dp[i], dp[i] + maxk, inf);
    }

    dp[0][0] = 0;

    vector<ll> diff;
    for (int i = 0; i + 1 < n; i++) {
        diff.pb(abs(a[i] - a[i + 1]));
    }

    for (int i = 1; i < diff.size(); i++) {
        diff[i] += diff[i - 1];
    }

    auto get = [&](int l, int r) {
        if (l == r) {
            return 0LL;
        } else {
            return diff[r - 1] - (l ? diff[l - 1] : 0LL);
        }
    };

    vector<int> sl, sr(ls.size(), 0);
    sl.pb(ls[0]);
    for (int i = 1; i < ls.size(); i++) {
        sl.pb(sl.back() + ls[i]);
    }

    for (int i = (int)ls.size() - 1; i >= 0; i--) {
        sr[i] = (i < ls.size() - 1 ? sr[i + 1] : 0) + ls[i];
    }

    for (int i = 0; i <= ls.size(); i++) {
        for (int j = 0; j <= ls.size(); j++) {
            if (i + j >= ls.size()) {
                continue;
            }
            int l = (i ? sl[i - 1] : 0) + (j ? sr[sr.size() - j] : 0);

            if (i < (int)ls.size() - j) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + get(l, l + ls[i] - 1));
            }

            if (j < (int)ls.size() - i) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + get(l, l + ls[ls.size() - j - 1] - 1));
            }
        }
    }

    ll ans = inf;

    for (int i = 0; i <= ls.size(); i++) {
        ans = min(ans, dp[i][ls.size() - i]);
    }

    cout << ans << endl;



    return 0;
}