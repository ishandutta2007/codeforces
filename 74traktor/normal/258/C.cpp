#include <bits/stdc++.h>

using namespace std;

#define int long long
int mod = 1e9 + 7;
int a[100005];

int st(int a, int b){
    if (b == 0) return 1;
    if (b % 2 == 0){
        int q = st(a, b / 2);
        return q * q % mod;
    }
    return st(a, b - 1) * a % mod;
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 0;
    vector < int > R;
    vector < int > T;
    vector < int > Have;
    for (int M = 1; M <= a[n]; ++M){
        R = {};
        T = {};
        Have = {};
        for (int i = 1; i <= sqrt(M); ++i){
            if (M % i == 0){
                R.push_back(i);
                if (i * i != M) T.push_back(M / i);
            }
        }
        for (int i = (int)T.size() - 1; i >= 0; --i) R.push_back(T[i]);
        int what = 1;
        int pred = 0;
        for (int j = 1; j < (int)R.size(); ++j){
            int l = 0, r = n + 1;
            while (r - l > 1){
                int mid = (r + l) / 2;
                if (a[mid] >= R[j]) r = mid;
                else l = mid;
            }
            Have.push_back(l - pred);
            pred = l;
        }
        int pocl = n - pred;
        for (int i = 0; i < (int)Have.size() - 1; ++i) what = (what * st(i + 1, Have[i])) % mod;
        if (M != 1) ans = (ans + what * (st(Have.size(), Have.back()) * st(Have.size() + 1, pocl) % mod + mod - st(Have.size(), Have.back()) * st(Have.size(), pocl) % mod)) % mod;
        else ans = 1;
    }
    cout << ans << '\n';
    return 0;
}