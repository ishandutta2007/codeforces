#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int mod = 998244353, maxn = 5010;

int a[maxn];
int fac[maxn], ifac[maxn];
int dp[maxn], dp_prev[maxn], sm[maxn], f[maxn];

struct Fenwick {
    int fn[maxn];
    int n;
    void set_n(int n) {
        for(int i = 1; i <= n; i++)
            fn[i] = 0;
        this->n = n;
    }
    void add(int pos, int x) {
        for(; pos <= n; pos+= (pos & -pos))
            fn[pos] = (fn[pos] + x) % mod;
    }
    int get(int pos) {
        int ans = 0;
        for(; pos > 0; pos-= (pos & -pos))
            ans = (ans + fn[pos]) % mod;
        return ans;
    }
};
Fenwick fn;


int Pow(int a, int b) {
    int ans = 1;
    for(; b; a = 1ll * a * a % mod, b >>= 1)
        if(b & 1)
            ans = 1ll * ans * a % mod;
    return ans;
}

void prep() {
    fac[0] = 1;
    for(int i = 1; i < maxn; i++)
        fac[i] = 1ll * i * fac[i-1] % mod;
    ifac[maxn-1] = Pow(fac[maxn-1], mod-2);
    for(int i = maxn-2; i >= 0; i--)
        ifac[i] = 1ll * ifac[i+1] * (i+1) % mod;
}

int solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);

    for(int i = 1; i <= n; i++) {
        f[i] = 0;
        for(int j = 1; j < i; j++)
            f[i] += a[j] < a[i];
    }

    if(f[n] != n-1)
        return 0;

    if(n == 2)
        return 1;

    // dp[i][j]
    for(int i = 1; i <= n; i++) {
        dp[i] = 1ll * f[i] * (f[i]-1) % mod;
    }

    // for(int i = 1; i <= n-1; i++) {
    //     for(int j = 2; f[i] - 2*j + 1 > 0; j++) {
    //         dp[i][j] = 0;
    //         for(int bef = 1; bef < i; bef++) {
    //             if(a[bef] < a[i]) {
    //                 dp[i][j] = (1ll * dp[i][j] + 1ll * (f[i]-2*j+1) * dp[bef][j-1]) % mod;
    //             }
    //         }
    //     }
    // }



    for(int j = 2; j <= (n/2)-1; j++) {
        for(int i = 0; i <= n; i++) {
            dp_prev[i] = dp[i];
        }
        fn.set_n(n);
        for(int i = 1; i <= n-1; i++) {
            dp[i] = 0;
            if(f[i] - 2*j + 1) {
                dp[i] = 1ll * (f[i]-2*j+1) * fn.get(a[i]-1) % mod;
            } else {
                dp[i] = 0;
            }
            fn.add(a[i], dp_prev[i]);
        }
    }

    int ans = dp[n-1];
    
    map<int, int> mp;
    for(int i = 1; i <= n-1; i++) {
        mp[a[i]]++;
    }
    for(auto p : mp) {
        ans = (1ll * ans * ifac[p.second]) % mod;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    prep();

    int q;
    cin >> q;
    while(q--) {
        cout << solve() << "\n";
    }
    return 0;
}