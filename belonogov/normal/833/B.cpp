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
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;



int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, k;
    scanf("%d%d", &n, &k);   
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    vector<int> cnt(n);
    int nonZero = 0;
    int curL = 0;
    int curR = 0;

    auto setLR = [&](int l, int r) {
        for (; curR < r; ) {
            nonZero += (cnt[a[curR++]]++) == 0; 
        }
        for (; l < curL; ) {
            nonZero += (cnt[a[--curL]]++) == 0;
        }
        for (; r < curR; ) {
            nonZero -= (--cnt[a[--curR]]) == 0;
        }
        for (; curL < l; ) {
            nonZero -= (--cnt[a[curL++]]) == 0;
        }
    };


    vector<vector<int>> dp(k + 1, vector<int> (n + 1));
    for (int i = 1; i <= n; i++) {
        setLR(0, i);
        dp[1][i] = nonZero;
    }

    function<void(int,int,int,int,int)> go = [&](int fl, int fr, int dpL, int dpR, int kk) {
        assert(fl <= fr);
        if (fr - fl == 0) return;
        int mid = (fl + fr) / 2;
        int best = -1;
        int where = -1;
        for (int i = dpL; i <= dpR && i < mid; i++)  {
            setLR(i, mid);
            int res = dp[kk - 1][i] + nonZero;
            if (res > best) {
                best = res;
                where = i;
            }
        }
        dp[kk][mid] = best;
        go(fl, mid, dpL, where, kk); 
        go(mid + 1, fr, where, dpR, kk);
    };

    for (int i = 2; i <= k; i++) {
        go(1, n + 1, 1, n, i);
    }


    cout << dp[k][n] << endl;  





#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}