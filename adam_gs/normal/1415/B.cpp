#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int t;
        cin >> t;
        while(t--) {
                int n, k, ans=1000000000;
                cin >> n >> k;
                int T[n];
                rep(i, n) { cin >> T[i]; --T[i]; }
                rep(i, 100) {
                        int l=0, w=0;
                        while(l<n) {
                                while(l<n && T[l]==i) ++l;
                                if(l<n) {
                                        l+=k; ++w;
                                }
                        }
                        ans=min(ans, w);
                }
                cout << ans << '\n';
        }
}