#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

// const int MOD = 1e9 + 7;
const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    mt19937 rng(58);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // a[i] = (i ? a[i - 1] : 0) + rng() % 10000 + 1;
        // cout << a[i] << ' ';
    }
    // cout << endl;
    sort(a.begin(), a.end());
    string s;
    cin >> s;
    // for (int i = 0; i < n; i++) {
    //     if (rng() % 10) {
    //         s += 'R';
    //     } else {
    //         s += 'L';
    //     }
    // }
    // cout << s << endl;
    
    int changes = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            changes++;
        }
    }
    vector<int> b(n);
    int cur = n - changes;
    int hui = n - changes - 1;
    ll diff = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            b[i] = a[cur++];
        } else {
            b[i] = -a[cur++];
        }
        diff += b[i];
        int j = i;
        while (j + 1 < n && s[j + 1] == s[i]) {
            ++j;
            if (s[i] == 'L') {
                if (diff - a[hui] > 0)
                    b[j] = -a[hui];
                else
                    b[j] = a[hui];
            } else {
                if (diff + a[hui] < 0) 
                    b[j] = a[hui];
                else
                    b[j] = -a[hui];
            }
            hui--;
            diff += b[j];
        }
        i = j;
    }
    diff = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] > 0) {
            cout << b[i] << " L\n";
        } else {
            cout << -b[i] << " R\n";
        }
        diff += b[i];
        assert((s[i] == 'L' && diff > 0) || (s[i] == 'R' && diff < 0));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}