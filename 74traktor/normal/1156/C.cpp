#include <bits/stdc++.h>

using namespace std;

int a[200005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, z;
    cin >> n >> z;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int lef = 0, righ = n / 2 + 1;
    while (righ - lef > 1){
        int mid = (righ + lef) / 2;
        bool f = true;
        for (int i = 1; i <= mid; ++i){
            if (a[n - mid + i] - a[i] < z) f = false;
        }
        if (f) lef = mid;
        else righ = mid;
    }
    cout << lef << '\n';
    return 0;
}