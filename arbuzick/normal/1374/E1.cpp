#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> t(n), a(n), b(n);
    for(int i = 0; i < n; ++i)
        cin >> t[i] >> a[i] >> b[i];
    vector<pair<int, int>> a1, b1, ab;
    vector<bool> used(n);
    for(int i = 0; i < n; ++i){
        if (a[i])
            a1.pb({t[i], i});
        if (b[i])
            b1.pb({t[i], i});
        if (a[i]&&b[i])
            ab.pb({t[i], i});
    }
    sort(a1.begin(), a1.end());
    sort(b1.begin(), b1.end());
    sort(ab.begin(), ab.end());
    if(a1.size() < k || b1.size() < k){
        cout << -1;
        return 0;
    }
    int ans = 0;
    int a2 = 0, b2 = 0, ab2 = 0;
    int k1 = 0, k2 = 0;
    while(k1 < k || k2 < k){
        while(a2 < a1.size() && used[a1[a2].s])
            a2++;
        while(b2 < b1.size() && used[b1[b2].s])
            b2++;
        while(ab2 < ab.size() && used[ab[ab2].s])
            ab2++;
        if (k1 >= k){
           ans += b1[b2].f;
           used[b1[b2].s] = 1;
           b2++;
           k2++;
        }else if(k2 >= k){
           ans += a1[a2].f;
           used[a1[a2].s] = 1;
           a2++;
           k1++;
        }else{
           if(ab2 == ab.size() || a1[a2].f+b1[b2].f < ab[ab2].f){
                ans += a1[a2].f+b1[b2].f;
                used[a1[a2].s] = 1;
                used[b1[b2].s] = 1;
                a2++;
                b2++;
                k1++;
                k2++;
           }else{
                ans += ab[ab2].f;
                used[ab[ab2].s] = 1;
                ab2++;
                k1++;
                k2++;
           }
        }
    }
    cout << ans;
    return 0;
}