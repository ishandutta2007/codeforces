#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 1000000000 + 7;

int sz;
int v[65];

int dp[35][35][2]; // dp[bits processed][pivots][<]

inline void add(int &where, int val) {
    where += val;
    if (where >= MOD)
        where -= MOD;
}

int cnt_even(int n) {
    if (n == 0)
        return 1;
    else
        return (1LL << (n - 1)) % MOD;
}

int cnt_odd(int n) {
    if (n == 0)
        return 0;
    else
        return (1LL << (n - 1)) % MOD;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i <= 30; ++ i)
        v[i + 1] = (bool)(n & (1 << i));
    sz = 31;
    reverse(v + 1, v + sz + 1);

    //for (int i = 1; i <= sz; ++ i)
    //    cout << v[i];
    //cout << endl;

    dp[0][0][0] = 1;
    for (int bits = 0; bits < sz; ++ bits)
        for (int pivots = 0; pivots <= bits; ++ pivots) {
            //If it's already smaller, we can either place a pivot, or not
            add(dp[bits + 1][pivots + 1][1], dp[bits][pivots][1]);
            add(dp[bits + 1][pivots][1], (dp[bits][pivots][1] * ((1LL << pivots) % MOD)) % MOD);

            //If it's not smaller yet
            if (v[bits + 1] == 1) {
                add(dp[bits + 1][pivots + 1][0], dp[bits][pivots][0]);
                add(dp[bits + 1][pivots][0], (1LL * dp[bits][pivots][0] * cnt_odd(pivots)) % MOD);
                add(dp[bits + 1][pivots][1], (1LL * dp[bits][pivots][0] * cnt_even(pivots)) % MOD);
            }
            else
                add(dp[bits + 1][pivots][0], (1LL * dp[bits][pivots][0] * cnt_even(pivots)) % MOD);
        }

    int ans = 0;
    for (int pivots = 0; pivots <= sz; ++ pivots) {
        add(ans, dp[sz][pivots][0]);
        add(ans, dp[sz][pivots][1]);
    }

    cout << ans << '\n';
    return 0;
}