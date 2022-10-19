#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(ll a = 0; a < (b); ++a)
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k;
    cin >> n >> k; --k;
    int ans[n], po=0, ko=n-1;
    rep(i, n-1) {
        if(k&(1ll<<(n-2-i))) {
            ans[ko]=i;
            --ko;
        } else {
            ans[po]=i;
            ++po;
        }
    }
    ans[po]=n-1;
    rep(i, n) cout << ans[i]+1 << " ";
    cout << '\n';
}