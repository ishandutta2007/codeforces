/*
,  ?  ?
 Cadillac
 ,  
 , ,   (, few)
*/
#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, a, b, n;
    cin >> t;
    while (t--) {
        cin >> a >> b >> n;
        int ans = 0;
        while (max(a, b) <= n) {
            ans++;
            if (a >= b) b += a;
            else a += b;
        }
        cout << ans << '\n';
    }
    return 0;
}