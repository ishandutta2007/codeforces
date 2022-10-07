#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
const ll INF18 = 1e18;
typedef vector<int> vi;



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    forn(i, n) {
        scanf("%d", &a[i]); a[i]--;
    }

    vector<vector<ll>> dp(k + 1, vector<ll> (n + 1, INF18));
    ll score = 0;
    int L = 0;
    int R = 0;
    vector<int> cnt(n);

    auto add = [&](int pos) {
        score += cnt[a[pos]];
        cnt[a[pos]]++;
        if (pos == R) {
            R++;
        }
        else if (pos == L - 1) {
            L--;
        }
        else {
            assert(false);
        }
    };

    auto rem = [&](int pos) {
        cnt[a[pos]]--;
        score -= cnt[a[pos]];
        if (pos == L) {
            L++;
        }
        else if (pos == R - 1) {
            R--;
        }
        else {
            assert(false);
        }
    };

    auto moveR = [&](int newR) {
        for (; R < newR;) {
            add(R);
        }
        if (newR < R) {
            for (; newR < L;) {
                add(L - 1);
            }
            for (; newR < R; ) {
                rem(R - 1);
            }
        }
    };
    auto moveL = [&](int newL) {
        assert(newL <= R);
        for (; L < newL; ) {
            rem(L);
        }
        for (; newL < L; ) {
            add(L - 1);
        }
    };


    // [l, r]
    function<void(int t, int l, int r, int optL, int optR)> rec = [&](int t, int l, int r, int optL, int optR) {
        assert(r - l + 1 >= 0);
        if (r - l + 1 == 0) return;
        //db3(t, l, r);
        int mid = (l + r) / 2;
        // solve for mid
        moveR(mid);
        int LL = min(mid, optR);
        moveL(LL);
        int optPos = -1;
        ll res = INF18;
        for (int i = LL; i >= optL; i--) {
            ll cand = dp[t - 1][i] + score;
            if (cand < res) {
                res = cand;
                optPos = i;
            }
            if (i != optL) {
                add(i - 1);
            }
        }
        //db(mid);
        //db(res);
        assert(res != INF18);
        dp[t][mid] = res;

        rec(t, l, mid - 1, optL, optPos);
        rec(t, mid + 1, r, optPos, optR);
    };

    dp[0][0] = 0;

    for (int t = 0; t < k; t++) {
        rec(t + 1, 0, n, 0, n);   
    }
    
    cout << dp[k][n] << endl;
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}