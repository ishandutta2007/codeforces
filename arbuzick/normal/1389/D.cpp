#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int l1, r1;
        cin >> l1 >> r1;
        int l2, r2;
        cin >> l2 >> r2;
        int k1 = 0;
        if(l2 > r1 || r2 < l1)
            k1 = max(l2-r1, l1-r2);
        int k2 = abs(l1-l2)+abs(r1-r2)-k1;
        int a = 0;
        if(k1 == 0)
            a = min(r1, r2)-max(l1, l2);
        int a1 = max(r1, r2)-min(l1, l2)-a;
        if(a*n >= k){
            cout << 0 << '\n';
            continue;
        }
        if(a*n+a1 >= k){
            cout << k1+k-a*n << '\n';
            continue;
        }
        if(a1 == 0){
            int ans = k1+k2+(k-a*n)*2;
            cout << ans << '\n';
            continue;
        }
        int k3 = (k-a*n)/a1;
        int ans = 0;
        int b = (k-a*n)%a1;
        if(k3 > n){
            ans = min(n*(k1+k2)+a1*2*(k3-n), k1+k2+a1*2*(k3-1));
            ans += b*2;
        }else{
            ans = min(k3*(k1+k2), k1+k2+a1*2*(k3-1));
            if(k3 == n && (ans != k1+k2+a1*2*(k3-1) || n == 1))
                ans += b*2;
            else
                ans += min(b*2, k1+b);
        }
        cout << ans << '\n';
    }
}