#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

const int MOD = 1e9 + 9;


ll binPow(ll a, ll b) {
    ll ret = 1;
    for (;b > 0; b /= 2) {
        if (b % 2 == 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
    }
    return ret;
}

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif 

    int n, a, b, k;
    scanf("%d%d%d%d", &n, &a, &b, &k);
    
    ll step = b * binPow(a, MOD - 2) % MOD;

    ll q0 = binPow(a, n);  
    string s;
    cin >> s;    
    ll sum = 0;
    ll cnt = (n + 1) / k;
    assert((n + 1) % k == 0);
    ll ss = binPow(step, k);
    ll up = (1 - binPow(ss, cnt) + MOD) % MOD;
    ll down = (1 - ss + MOD) % MOD;
    if (down == 0) {
        ll balans = 0;
        ll q1 = q0;
        for (auto ch: s) {
            int sign = ch == '+'? 1: -1;
            balans = (balans + sign * q1 + MOD) % MOD;
            q1 = (q1 * step) % MOD; 
        }

        balans = (balans * cnt) % MOD;
        cout << balans << endl;
        return 0;
    }

    ll res = q0 * up % MOD * binPow(down, MOD - 2) % MOD;
    //cout << res << endl; 
    for (int i = 0; i < k; i++) {
        int sign = (s[i] == '+')? 1: -1;
        sum =  (sum + res * sign + MOD) % MOD;
        res = res * step % MOD;
    }
    cout << sum << endl;



}