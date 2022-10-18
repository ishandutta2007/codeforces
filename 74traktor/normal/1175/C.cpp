#include <bits/stdc++.h>

using namespace std;

#define int long long
int a[200005];

int bp(int lef, int righ, int l, int r){
    int l1 = l - 1, r1 = r + 1;
    while (r1 - l1 > 1){
        int m1 = (r1 + l1) / 2;
        if (a[m1] >= lef) r1 = m1;
        else l1 = m1;
    }
    int l2 = l - 1, r2 = r + 1;
    while (r2 - l2 > 1){
        int m2 = (r2 + l2) / 2;
        if (a[m2] <= righ) l2 = m2;
        else r2 = m2;
    }
    return l2 - r1 + 1;
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> n >> k;
        for (int j = 1; j <= n; ++j) cin >> a[j];
        int ans = 2000 * 1000 * 1000, ans_x;
        for (int j = 1; j <= n; ++j){
            int l = 1, r = a[j] + 1;
            while (r - l > 1){
                int m = (r + l) / 2;
                int lef = max((long long)1, 2 * m - a[j]), righ = a[j];
                int cnt = bp(lef, righ, 1, j);
                if (cnt >= k + 1) l = m;
                else r = m;
            }
            int lef = max((long long)1, 2 * l - a[j]), righ = a[j];
            if (a[j] - l < ans && bp(lef, righ, 1, j) >= k + 1){
                ans = a[j] - l;
                ans_x = l;
            }
            l = a[j] - 1, r = a[n] + 1;
            while (r - l > 1){
                //if (i == 2) cout << l << " " << r << endl;
                int m = (r + l) / 2;
                int lef = a[j], righ = 2 * (m - a[j]);
                int cnt = bp(lef, righ, j, n);
                //cout << cnt << " " << m << endl;
                if (cnt >= k + 1) r = m;
                else l = m;
            }
            lef = a[j], righ = 2 * (r - a[j]);
            if (r - a[j] < ans && bp(lef, righ, j, n) >= k + 1){
                ans = r - a[j];
                ans_x = r;
            }
        }
        cout << ans_x << '\n';
    }
    return 0;
}