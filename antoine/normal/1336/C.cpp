#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = 998244353;
const int MxN = 3009;
ll dp[MxN + 9][MxN + 9];

string s, t;

bool check(const int i, const char c ) {
    assert(i >= 0);
    return i >= (int)t.size() || t[i] == c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> s >> t;
    const int n = (int)s.size();

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) {
            ll &res = dp[i][j] = 0;
            if(check(j, s[i]))
                res += i ? dp[i-1][j+1]:1;
            if(check(j + i, s[i]))
                res += i ? dp[i-1][j]:1;
            res %= mod;
        }

    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        if(!check(0, s[i]))
            continue;
        ll cnt = 0;
        for(int j = i; j < n; ++j) {
            if(j != i && !check(j, s[j]))
                break;
            cnt += j >= (int)t.size() - 1;
        }
        ans += cnt * (i ? dp[i-1][1] : 2LL);
        ans %= mod;
    }



        cout << (ans%mod+mod)%mod;
    return 0;
}