#include <bits/stdc++.h>

using namespace std;

int a[1005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ans = -1, kol = 1e9;
    for (int t = 1; t <= 101; ++t){
        int q = 0;
        for (int i = 1; i <= n; ++i){
            if (a[i] != t) q += (abs(a[i] - t) - 1);
        }
        if (q < kol) kol = q, ans = t;
    }
    cout << ans << " " << kol << '\n';
    return 0;
}