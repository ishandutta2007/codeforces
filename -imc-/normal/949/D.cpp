#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int modpow(int x, int p) {
    int ans = 1;
    while (p) {
        if (p % 2)
            ans = ans * (li)x % MOD;
        p /= 2;
        x = x * (li)x % MOD;
    }
    return ans;
}

int d, gb;

struct subsolver {
    vector<int> a;
    int need;
    int n;
    
    subsolver(vector<int> a, int need): a(a), need(need), n(a.size()) {}
    
    // positive -> need take
    // negative -> can give
    bool can(int nBad, li balance) {
        int r = 0;
        li sum = 0;
        //li fullSum = 0;
        
        vector<int> b = a;
        
        if (balance > 0) {
            for (int i = need; i < n; ++i) {
                li h = min<li>(balance, b[i]);
                b[i] = h;
                balance -= h;
            }
            //assert(balance >= 0);
        }
        else {
            // can give
            balance = -balance;
            for (int i = need - 1; i >= 0; --i) {
                li h = min<li>(balance, b[i]);
                b[i] -= h;
                balance -= h;
            }
        }
        
        int nNowBad = 0;
        for (int i = 0; i < need; ++i) {
            li horizon = i + d * (li)(i + 1);
            while (r < n && r <= horizon) {
                sum += b[r];
                ++r;
            }
            
            if (sum >= gb) {
                sum -= gb;
            }
            else {
                ++nNowBad;
                if (nNowBad > nBad)
                    return false;
            }
        }
        
        return true;
    }
    
    li getMinTake(int nBad) {
        // low can't, high can
        li low = -1e18, high = 1e18;
        --low;
        while (low + 1 != high) {
            li m = (low + high) / 2;
            
            //if (abs(m) < 10)
            //cout << "bal " << m << " -> " << can(nBad, m) << "\n";
            
            if (can(nBad, m))
                high = m;
            else
                low = m;
        }
        return high;
    }
};

void solve(bool __attribute__((unused)) read) {
    int n;
    
    cin >> n >> d >> gb;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    subsolver first(a, (n + 1) / 2);
    reverse(all(a));
    subsolver second(a, n - (n + 1) / 2);
    reverse(all(a));
    
    //cout << first.getMinTake(1) << endl;
    //return;
    //second.getMinTake(1);
    //return;
    
#if 0
    for (int i = 0; i < n; ++i) {
        cout << i << " -> " << first.getMinTake(i) << " " << second.getMinTake(i) << endl;
    }
    
    for (int i = 1; i <= n; ++i) {
        assert(first.getMinTake(i) <= first.getMinTake(i - 1));
        assert(second.getMinTake(i) <= second.getMinTake(i - 1));
    }
#endif
    
    // low can't, high can
    int low = -1, high = n;
    while (low + 1 != high) {
        int m = (low + high) / 2;
        
        li f = first.getMinTake(m);
        li s = second.getMinTake(m);
        //cout << "m=" << m << " -> " << f << " " << s << endl;
        
        if (f + s <= 0) {
            high = m;
        }
        else {
            low = m;
        }
    }
    
    cout << high << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //while (true) solve(false);
    
    return 0;
}