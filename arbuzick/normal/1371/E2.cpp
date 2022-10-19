#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    int l = a[0], r;
    for(int i = 1; i < n; ++i)
        l = max(l, a[i]-i);
    r = a[p-1]-1;
    for(int i = p; i < n; ++i)
        r = min(r, a[i]-(i-p+1)-1);
    cout << max(n-n, r-l+1) << "\n";
    for(int i = l; i <= r; ++i)
        cout << i << ' ';
    return 0;
}