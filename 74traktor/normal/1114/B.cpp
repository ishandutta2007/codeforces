#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[200005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector < int > b;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    int ans = 0;
    multiset < int > Q;
    for (int i = n - 1; i >= n - m * k; --i) ans += b[i], Q.insert(b[i]);
    cout << ans << '\n';
    int len = 0, what = 0, qq = 0;
    for (int i = 1; i <= n; ++i){
        if (Q.find(a[i]) != Q.end()){
            what++;
            Q.erase(Q.find(a[i]));
        }
        len++;
        if (len >= m && what == m && qq < k - 1){
            cout << i << " ";
            qq++;
            what = 0;
            len = 0;
        }
    }
    return 0;
}