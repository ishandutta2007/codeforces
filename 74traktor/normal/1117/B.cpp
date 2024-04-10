#include <bits/stdc++.h>

using namespace std;

#define int long long

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, imax1 = 0, imax2 = 0, x;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        if (x > imax1){
            imax2 = imax1;
            imax1 = x;
        }
        else if (x > imax2) imax2 = x;
    }
    int k1 = m / (k + 1);
    cout << (m - k1) * imax1 + k1 * imax2 << endl;
    return 0;
}