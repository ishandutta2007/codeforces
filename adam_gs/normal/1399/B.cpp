#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int t;
        cin >> t;
        while(t--) {
                int n;
                cin >> n;
                long long c[n], o[n], mc=1000000007, mo=1000000007;
                rep(i, n) { cin >> c[i]; mc=min(mc, c[i]); }
                rep(i, n) c[i]-=mc;
                rep(i, n) { cin >> o[i]; mo=min(mo, o[i]); }
                rep(i, n) o[i]-=mo;
                long long ans=0;
                rep(i, n) ans+=max(o[i], c[i]);
                cout << ans << '\n';
        }
}