#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[m];
    for (int i = 0; i < m; ++i)
        a[i] = 0;
    for (int i = 0; i < m; ++i){
        //cout << i << " " << i * i % m << " " << (n - i) << " " << m << endl;
        if (i <= n)
            a[(i * i) % m] += ((n - i) / m + 1);
    }
    int ans = 0;
    a[0]--;
    a[0] = max((long long)0, a[0]);
    for (int i = 0; i < m; ++i){
        //cout << a[i] << " ";
        ans += a[i] * a[(m - i) % m];
    }
    cout << ans << endl;
    return 0;
}