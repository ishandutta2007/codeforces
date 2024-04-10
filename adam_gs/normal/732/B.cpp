#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n, k, ans=0;
        cin >> n >> k;
        int t[n];
        rep(i, n) cin >> t[i];
        rep(i, n-1) if(t[i]+t[i+1]<k) {
                ans+=k-t[i]-t[i+1];
                t[i+1]=k-t[i];
        }
        cout << ans << '\n';
        rep(i, n) cout << t[i] << " ";
}