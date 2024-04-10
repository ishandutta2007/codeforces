#include <bits/stdc++.h>

using namespace std;

#define int long long
int a[100005];
int pref[100005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    vector < int > b;
    for (int i = 1; i <= n - 1; ++i) b.push_back(a[i + 1] - a[i]);
    sort(b.begin(), b.end());
    int pred = 0;
    for (int i = 0; i < n - 1; ++i){
        pref[i] = pred + b[i];
        pred = pref[i];
    }
    int q, l, r;
    cin >> q;
    for (int i = 1; i <= q; ++i){
        cin >> l >> r;
        l = (r - l + 1);
        int lef = -1, righ = b.size();
        while (righ - lef > 1){
            int mid = (righ + lef) / 2;
            if (b[mid] <= l) lef = mid;
            else righ = mid;
        }
        if (lef == -1) cout << n * l << " ";
        else cout << pref[lef] + (n - lef - 1) * l << " ";
    }
    return 0;
}