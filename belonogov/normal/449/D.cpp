#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 2e6;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int BASE = 20;
int st[N];

vector < int > solve(int k, vector < int > & a) {
    //if (!a.empty()) {
        //cerr << "k a: " << k << "         ";
        //for (auto t : a) 
            //cerr << t << " ";
        //cerr << endl;
    //}
    vector < int > res(1 << k);
    if (k == 0) {
        res[0] = a.size();    
        return res;
    }
    vector < int > b[2];
    for (int i = 0; i < (int)a.size(); i++)
        b[((a[i] >> (k - 1)) & 1)].pb(a[i]);
    vector < int > dp[2];

    dp[0] = solve(k - 1, b[0]);
    dp[1] = solve(k - 1, b[1]);
    for (int mask = 0; mask < (1 << (k - 1)); mask++) {
        res[mask + (1 << (k - 1))] = dp[1][mask];
        res[mask] = dp[1][mask] + dp[0][mask];
    }
    return res;
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    vector < int > a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    vector < int > dp = solve(BASE, a);
    st[0] = 1;
    for (int i = 0; i < n; i++)
        st[i + 1] = (st[i] * 2) % MOD;
    long long ans = 0;
    for (int mask = 0; mask < (1 << BASE); mask++) {
        int t = __builtin_popcount(mask);
        if (t % 2 == 0) 
            ans = (ans + st[dp[mask]]) % MOD;
        else
            ans = (ans - st[dp[mask]] + MOD) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}