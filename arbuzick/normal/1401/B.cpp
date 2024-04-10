#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int x1, y1, z1;
        cin >> x1 >> y1 >> z1;
        int x2, y2, z2;
        cin >> x2 >> y2 >> z2;
        int ans = 2*min(z1, y2);
        ans = ans-2*max(0LL, y1-(x2+y2-min(z1, y2)));
        cout << ans << '\n';
    }
    return 0;
}