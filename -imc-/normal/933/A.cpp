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

void solve(bool __attribute__((unused)) read) {
    int n;
    if (read)
        cin >> n;
    else
        n = rand() % 100 + 1;
    
    vector<int> a(n), orig(n);
    for (int i = 0; i < n; ++i) {
        if (read) {
        cin >> a[i];
        --a[i];
        }
        else {
            a[i] = rand() % 2;
        }
        
        orig[i] = a[i];
        a[i] = 1 - a[i];
    }
    
#if 0
    cout << "TEST:\n";
    cout << n << "\n";
    for (int i = 0; i < n; ++i) cout << a[i] + 1 << " "; cout << endl;
#endif
    
    auto get_os = [&]() {
        vector<int> cnt = a;
        for (int i = 1; i < n; ++i)
            cnt[i] += cnt[i - 1];
        
#if 0
        for (int i = 0; i < n; ++i)
            cout << cnt[i] << " ";
        cout << endl;
#endif
        
        vector<int> os(n);
        for (int i = 0; i < n; ++i) {
            os[i] = cnt[i];
            for (int j = 0; j <= i; ++j)
                os[i] = max(os[i], (j ? cnt[j - 1] : 0) + (i - j + 1) - (cnt[i] - (j ? cnt[j - 1] : 0)));
        }
        return os;
    };
    
    auto left = get_os();
    reverse(all(a));
    for (int& x: a)
        x = 1 - x;
    auto right = get_os();
    
    int answer = 0;
    
    left.insert(left.begin(), 0);
    
#if 0
    for (int i = 0; i <= n; ++i)
        cout << left[i] << " ";
    cout << "\n";
#endif
    
    reverse(all(right));
    right.insert(right.end(), 0);
    
#if 0
    for (int i = 0; i <= n; ++i)
        cout << right[i] << " ";
    cout << "\n";
#endif
    
    for (int i = 0; i <= n; ++i)
        answer = max(answer, left[i] + right[i]);
    
    cout << answer << "\n";
    
#if 0
    int exp = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j) {
            auto x = orig;
            reverse(x.begin() + i, x.begin() + j + 1);
            int can = 0;
            for (int k = -1; k < n; ++k) {
                int a = 0;
                for (int l = 0; l <= k; l++)
                    if (x[l] == 0) a++;
                for (int l = k + 1; l < n; l++)
                    if (x[l] == 1) a++;
                    
                can = max(can, a);
            }
            exp = max(exp, can);
        }
        
    cout << exp << endl;
    assert(answer == exp);
#endif
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //while (true) solve(false);
    
    //solve(false);
    
    return 0;
}